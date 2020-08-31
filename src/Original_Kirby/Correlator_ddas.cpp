/*****************************************************************/
/* Correlator.cpp for DSSD Beta Decay - Digital Data Acquisition */
/* Based on standard BCS SpecTcl codes                           */
/* Scott Suchyta/Sean Liddick, June 2012                      */
/*****************************************************************/

/********************************************/
/* Correlation flags:                       */
/*                                          */
/*   4 - invalid DSSD implant pixel         */
/*   8 - invalid DSSD decay pixel           */
/*  12 - implantation event                 */
/*  16 - decay event                        */
/*  20 - unknown event                      */
/*  24 - front, no back decay               */
/*  28 - back, no front decay               */
/*  32 - back-2-back implantations          */
/*  36 - back-2-back decays                 */
/*  40 - invalid implant time               */
/*  44 - invalid decay time                 */
/*  48 - exceeded correlation time          */
/*  52 - long-lived implant rejection       */
/*  56 - reset correlation array            */
/*  60 - punchthrough                       */
/*                                          */
/********************************************/

#include <config.h>
#include <EventProcessor.h>
#include <TCLAnalyzer.h>
#include <math.h>
#include <iostream>

#include "Parameters-ddas.h"
#include "Variables-ddas.h"
#include "Correlator_ddas.h"

#define PIXEL_SIZE 1

typedef unsigned long long uint_64;

/* Define a struct for IMPLANT events */

typedef struct
{
  bool implanted;
  double timehigh;
  double timelow;
  double timecfd;
  double time;  /* Time of event, in 30.5 us clockticks */
  long dE1;   /* dE from PIN01 */
  long dE2;   /* dE from PIN02 */
  long dE3;   /* dE from PIN03 */
  long dEscint;   /* dE from scint */
  long isum;  /* Total implant energy (from sums) */
  long imax;  /* Total implant energy (from max) */
  double tof;   /* Time of flight */
  double dt;    /* Time since last implant */
} IMPLANT;

/* Define a struct for DECAY events */

typedef struct 
{
  double time; /* Time of event, in 30.5 us clockticks */
  long dE1;  /* dE from PIN01 */
  long dE2;  /* dE from PIN02 */
  long dE3;  /* dE from PIN03 */
  long dEscint;   /* dE from scint */
  long isum; /* Total implant energy (from sums) */
  long imax; /* Total implant energy (from max) */
  double tof;  /* Time of flight (for implant event) */
  double dt;   /* Time since implant */
} DECAY;

IMPLANT implant[41][41]; /* Implant data [x(back)][y(front)] */
DECAY decay2[41][41]; /* Correlated decay data */




Bool_t CBDecayCorrelator::operator()(const Address_t pEvent,
				     CEvent&         rEvent,
				     CAnalyzer&      rAnalyzer,
				     CBufferDecoder& rDecoder)
{
//  cout << "BEGIN CORRELATOR" << endl;

  int i, j;
  int condition = 0;
  int resetcheck = 0;
  int ibackch = 100;
  int ifrontch = 100;
  int dbackch = 100;
  int dfrontch = 100;
  int back = 100;
  int front = 100;
  int nerohit = 0;
  bool implant_event = false;
  bool sssd01_reject = false;
  bool punchthrough = false;
  bool decay_event = false;
  bool unknown_event = false;

  bool implanted = false;

  long num_corr = 0;

  /*** Correlation array reset ***/
  /* Need to reset bdecayv.corr.reset != 0 at start of each run */

  if (bdecayv.corr.reset != 0) {
    for (i=1; i<41; i++) {
      for (j=1; j<41; j++) {
	implant[i][j].implanted = false;
	implant[i][j].time = 0;
	implant[i][j].dE1 = 0;
	implant[i][j].dE2 = 0;
	implant[i][j].dE3 = 0;
	implant[i][j].dEscint = 0;
	implant[i][j].isum = 0;
	implant[i][j].imax = 0;
	implant[i][j].tof = 0;
	implant[i][j].dt = 0;
	
	decay2[i][j].time = 0;
	decay2[i][j].dE1 = 0;
	decay2[i][j].dE2 = 0;
	decay2[i][j].dE3 = 0;
	decay2[i][j].dEscint = 0;
	decay2[i][j].isum = 0;
	decay2[i][j].imax = 0;
	decay2[i][j].tof = 0;
	decay2[i][j].dt = 0;
      }
    }
    resetcheck = 56; /* Condition flag will be set to 56 when reset done */
    bdecayv.corr.reset = 0;
  }

  // define times;
  double current_time, implant_time, decay_time;

  //set current time in units of milliseconds
  if(rEvent[bdecay.clock.fast.getId()].isValid() && rEvent[bdecay.clock.slow.getId()].isValid() ){
    current_time = bdecay.clock.current/1000000.;                // In ms
  }
  else {
    cout << "times not valid ????? " << endl;
  }


  /*** Implant/Decay Logic ***/

  /*
    Pixel location is defined by the front and back strips
    showing the maximum energy deposited (in implant or decay)
    in each side of the DSSD.  The strip array runs from 1 to 40.  
    If there is no event data, imaxch and dmaxch are set to 100;
    there are channel checks to reject events with invalid positions.
  */

  /* First establish pixel locations for implants/decays */
  
  /* Implants first... */
  if ( rEvent[bdecay.front.imaxch.getId()].isValid() ) {
    ifrontch = (int)bdecay.front.imaxch;
  }
  if ( rEvent[bdecay.back.imaxch.getId()].isValid() ) {
    ibackch = (int)bdecay.back.imaxch;
  }
  
  /* Now decays... */
  if ( rEvent[bdecay.front.dmaxch.getId()].isValid() ) {
    dfrontch = (int)bdecay.front.dmaxch;
  }
  if ( rEvent[bdecay.back.dmaxch.getId()].isValid() ) {
    dbackch = (int)bdecay.back.dmaxch;
  }
  
  // Now establish boolean results of simple requirements to determine
  // implants vs. decays vs. oddball events

  
  // Low-gain events in PIN1, PIN2, DSSD, NOT SSSD01 - implant 
  if ((bdecayv.hit.pin01 == 1) && (bdecayv.hit.pin02 == 1) &&
      (bdecayv.hit.backlo != 0) && (bdecayv.hit.frontlo != 0)) {
    if (bdecayv.hit.sssd01 == 0) {
      implant_event = true;
    /*  if (( (bdecay.pid.de2 <= 2324.0) && (bdecay.pid.de2 >= 2139.0) && (bdecay.pid.pin02xfptof <= 15092.0) && (bdecay.pid.pin02xfptof >= 14731.0))) {
       cout << "Actual front imaxch = " << ifrontch << endl;
       ifrontch = rand() % 40 + 1.;
       cout << "Random front imaxch = " << ifrontch << endl;
       cout << "Actual back imaxch = " << ibackch << endl;
       ibackch = rand() % 40 + 1.;
       cout << "Random back imaxch = " << ibackch << endl;
      }*/ 
    
      //cout << "implant" << endl;
    } else {
      sssd01_reject = true;
    }
  }
  
  if (((bdecayv.hit.pin03 == 1) && (bdecayv.hit.sssd01 == 1)) || bdecayv.hit.scint == 1) {
  //if (((bdecayv.hit.pin03 == 1) && (bdecayv.hit.sssd01 == 1)) ) {
    punchthrough = true;
  }
  /*if (bdecayv.hit.sssd01 == 1) {
	punchthrough = true;
  }*/
  // remove sssd reject to reject implants because no sssds
  // are being used in this experiment
  /*//Low-gain events in PIN1, PIN2, DSSD - implant 
  if ((bdecayv.hit.pin01 == 1) && (bdecayv.hit.pin02 == 1) &&
      (bdecayv.hit.backlo != 0) && (bdecayv.hit.frontlo != 0)) {
    implant_event = true;
  } */

  /* High-gain event in DSSD, NO SIGNAL in PIN1, PIN2 - decay */
  if ((bdecayv.hit.pin01 == 0) && (bdecayv.hit.pin02 == 0) &&
      (bdecayv.hit.fronthi != 0) && (bdecayv.hit.backhi != 0)&&
      (bdecayv.hit.frontlo == 0) && (bdecayv.hit.backlo == 0) && (punchthrough == false)) {
    decay_event = true;
  }
    if (implant_event) {

    /* Check for valid implantation pixel in DSSD */
    if ((ibackch >= 1) && (ibackch <= 40) && (ifrontch >= 1) &&
	(ifrontch <= 40)) {
      
      condition = 12; /* Good position implantation */
     
      /* Check for existing implant in DSSD pixel */
        if (implant[ibackch][ifrontch].implanted) {
	  condition = 32; /* Back-2-back implantation in DSSD */

	  if ( rEvent[bdecay.clock.current.getId()].isValid() ) {
	    if (implant[ibackch][ifrontch].time > current_time/*bdecay.clock.current*/) {
	      condition = 40; /* Bad implant time flag */
	    }
	    implant[ibackch][ifrontch].dt = 
	      (current_time/*bdecay.clock.current*/ - implant[ibackch][ifrontch].time);
	  }
	  /* Output time between implants in 1 ms units on 16-bit
	     spectrum with 16-bit parameter declaration */
	  bdecay.corr.dtimplant = (unsigned long)((implant[ibackch][ifrontch].dt*
						       bdecayv.clock.calib));
	 } 
        else {
	  implant[ibackch][ifrontch].implanted = true;
	}
	
	/* Update time and tof */
	if ( rEvent[bdecay.clock.current.getId()].isValid() ) {
	  implant[ibackch][ifrontch].time = current_time/*bdecay.clock.current*/;
	}
	if ( rEvent[bdecay.clock.fast.getId()].isValid() ) {
	  implant[ibackch][ifrontch].timelow = bdecay.clock.fast;
	}
	if ( rEvent[bdecay.clock.slow.getId()].isValid() ) {
	  implant[ibackch][ifrontch].timehigh = bdecay.clock.slow;
	}
	if ( rEvent[bdecay.clock.cfd.getId()].isValid() ) {
	  implant[ibackch][ifrontch].timecfd = bdecay.clock.cfd;
	}
	if ( rEvent[bdecay.pid.i2ntof.getId()].isValid() ) {
	  implant[ibackch][ifrontch].tof = bdecay.pid.i2ntof;
	}
	       
	/* Update dE from PINs, etc. */
	if ( rEvent[bdecay.pid.de1.getId()].isValid() ) {
	  implant[ibackch][ifrontch].dE1 = bdecay.pid.de1;
	}
	if ( rEvent[bdecay.pid.de2.getId()].isValid() ) {
	  implant[ibackch][ifrontch].dE2 = bdecay.pid.de2;
	}
	if ( rEvent[bdecay.pid.de3.getId()].isValid() ) {
	  implant[ibackch][ifrontch].dE3 = bdecay.pid.de3;
	}
	if ( rEvent[bdecay.scint.energy.getId()].isValid() ) {
	  implant[ibackch][ifrontch].dEscint = bdecay.scint.energy;
	}
        //PIN04 not included because using high-gain for distinguishing light particles
	if ( rEvent[bdecay.pid.isum.getId()].isValid() ) {
	  implant[ibackch][ifrontch].isum = bdecay.pid.isum;
	}
	if ( rEvent[bdecay.pid.imax.getId()].isValid() ) {
	  implant[ibackch][ifrontch].imax = bdecay.pid.imax;
	}

	bdecay.corr.itime = implant[ibackch][ifrontch].time;
	bdecay.corr.ide1  = (long)implant[ibackch][ifrontch].dE1;
	bdecay.corr.ide2  = (long)implant[ibackch][ifrontch].dE2;
	bdecay.corr.ide3  = (long)implant[ibackch][ifrontch].dE3;
	bdecay.corr.idescint  = (long)implant[ibackch][ifrontch].dEscint;
	bdecay.corr.iisum = (long)implant[ibackch][ifrontch].isum;
	bdecay.corr.iimax = (long)implant[ibackch][ifrontch].imax;
	bdecay.corr.itof  = implant[ibackch][ifrontch].tof;
	//cout << "itof = " << bdecay.corr.itof << endl;
	//cout << "ide2 = " << bdecay.corr.ide2 << endl;
	//cout << "implant" << endl;
      
    } else {
	condition = 4; /* Invalid DSSD implantation pixel */
      }
  } else if (decay_event) {

    /* Code will search over user-defined correlation first to 
       find decay event in DSSD */

    //cout << "decay event" << endl;
    
    for (i=dfrontch-PIXEL_SIZE; i<=dfrontch+PIXEL_SIZE; i++) {
	for (j=dbackch-PIXEL_SIZE; j<=dbackch+PIXEL_SIZE; j++) {
	  if (j>=1 && j<=40 && i>=1 && i<=40) {
		if (implant[j][i].implanted) {
		      if ( (current_time- implant[j][i].time) < (bdecayv.clock.max*bdecayv.clock.scale) ){
			 /* Check to see if clock is incrementing */
	  		if ( rEvent[ bdecay.clock.current.getId()].isValid() ) {
	    		   if (implant[j][i].time > current_time/*bdecay.clock.current*/) {
	      		      condition = 44; /* Bad decay time */
	    		   }
	  		   else {
	            	      implanted=true;
			      back=j;
			      front=i;
			      num_corr++;
		           }
		        }
	 	      }
	        }
	    }
         }
    }
      
      bdecay.corr.mult = num_corr;
      
      if (implanted) {

        //cout << "implanted" << endl;
	
        /* Check for valid decay (really correlated implant) pixel in DSSD */
        if ((back >= 1) && (back <= 40) && (front >= 1) && (front <= 40)) {
	
	  condition = 16; /* Good decay flag */
         if (nero.hit ==1){nerohit=1;}
	  /* Make sure time between back-to-back implants is long; if not, reject event */
	  if (((implant[back][front].dt) >= bdecayv.corr.minimplant*bdecayv.clock.scale) || 
	      (implant[back][front].dt == 0)) {
	      
	      decay2[back][front].time = current_time/*bdecay.clock.current*/;
	      decay2[back][front].dt   = current_time/*bdecay.clock.current*/ - implant[back][front].time;
	      decay2[back][front].dE1  = implant[back][front].dE1;
	      decay2[back][front].dE2  = implant[back][front].dE2;
	      decay2[back][front].dE3  = implant[back][front].dE3;
	      decay2[back][front].dEscint  = implant[back][front].dEscint;
	      decay2[back][front].isum = implant[back][front].isum;
	      decay2[back][front].imax = implant[back][front].imax;
	      decay2[back][front].tof  = implant[back][front].tof;
	      
	      /* Output decay time in 10 ms units on 10-bit spectrum
		 with 16-bit parameter declaration */
	      bdecay.corr.dtimecal = (decay2[back][front].dt*bdecayv.clock.calib);
	      //cout << bdecay.corr.dtimecal << endl;
              bdecay.corr.dtime    = decay2[back][front].time;
	      bdecay.corr.dde1     = (long)decay2[back][front].dE1;
	      bdecay.corr.dde2     = (long)decay2[back][front].dE2;
	      bdecay.corr.dde3     = (long)decay2[back][front].dE3;
	      bdecay.corr.ddescint     = (long)decay2[back][front].dEscint;
	      bdecay.corr.disum    = (long)decay2[back][front].isum;
	      bdecay.corr.dimax    = (long)decay2[back][front].imax;
	      bdecay.corr.dtof     = decay2[back][front].tof;
	      bdecay.corr.dneut    = nerohit; 
	  } else {
	    condition = 52; /* Time between implants too short */
	  }
	  
	} else {
	condition = 8; /* Invalid decay pixel */
        }
     }
  } 
 else if (punchthrough == true){
 condition = 60;
 } 
 else {
    //cout << "unknown " << endl;
    unknown_event = true;
    condition = 20; /* Unknown event */
    if ((bdecayv.hit.fronthi != 0) && (bdecayv.hit.backhi == 0)) {
      condition = 24; /* DSSD front, no back */
    }
    if ((bdecayv.hit.fronthi == 0) && (bdecayv.hit.backhi != 0)) {
      condition = 28; /* DSSD back, no front */
    }
    
  }

  if (resetcheck != 0) {
    condition = resetcheck; /* Reset array flag */
  }
  //cout << "end " << endl;
  bdecay.corr.flag = (long) condition;

//  cout << "End of Correlator" << endl;
 
  /* END OF USER LOGIC */ 

  return kfTRUE; /* kfFALSE would abort the pipeline */

};

