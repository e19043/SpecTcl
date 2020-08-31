/*****************************************************************/
/* Threshold.cpp for DSSD Beta Decay - Digital Data Acquisition  */
/* Based on standard BCS SpecTcl codes                           */
/* Heather Crawford/Sean Liddick, June 2010                      */
/*****************************************************************/

#include <config.h>
#include <EventProcessor.h>
#include <TCLAnalyzer.h>
#include <Event.h> 
#include <math.h> 

#include "Parameters-ddas.h"
#include "Variables-ddas.h"

#include "Threshold_ddas.h"

#ifdef HAVE_STD_NAMESPACE
using namespace std;
#endif

typedef unsigned long long uint_64;

int temp1 = 0;
int temp2 = 0;
int mult1b = 0;
int mult1f = 0;
int mult1fb = 0;

Bool_t
CBDecayThreshold::operator()(const Address_t pEvent,
			     CEvent&         rEvent,
			     CAnalyzer&      rAnalyzer,
			     CBufferDecoder& rDecoder)
{
  //cout << "Begin of Threshold" << endl;
  int i, j;

  /* DSSD and SSSD energy sums */
  long isum, dsum, sum, isumtotal, dsumtotal; 

  /* DSSD and SSSD weighted sums */
  long isumch, dsumch, sumch; 

  /* DSSD and SSSD centroids */
  long icent, dcent, cent;
  
  /* DSSD and SSSD maximum energies */
  long imax, dmax, max, imaxtotal, dmaxtotal; 

  /* DSSD maximum time information */
  long dmaxtimecfd, dmaxtimelow, dmaxtimehigh, imaxtimecfd;
  long imaxtimelow, imaxtimehigh;
  
  /* DSSD and SSSD energy peaks */
  long imaxch, dmaxch, maxch; 

  /* DSSD and SSSD multiplicities */
  long imult, dmultf, dmultb, mult; 

  /* Set calorimeter hit mask to zero */
  long calhitmask=8;
  long bcsmask=0;

  long p1timelow, p1timehigh;
  long p2timelow, p2timehigh;
  long p3timelow, p3timehigh;
  /* Set total energies to zero before starting */

  /* Total decay energy based on energy sums within each detector */
  long decay_sumtotal = 0; 

  /* Total decay energy from maximum energy observed within each detector */
  long decay_maxtotal = 0; 

  /* Total implant energy including DSSD front energy sum */
  long implant_sumtotal = 0; 

  /* Total implant energy including maximum energy observed in DSSD front */
  long implant_maxtotal = 0; 

  /* Set hit flags to zero before starting */
  bdecayv.hit.pin01 = 0;
  bdecayv.hit.pin02 = 0;
  bdecayv.hit.pin03 = 0;
  bdecayv.hit.scint = 0;
  bdecayv.hit.veto = 0;
  bdecayv.hit.fronthi = 0;
  bdecayv.hit.fronthiover = 0;
  bdecayv.hit.frontlo = 0;
  bdecayv.hit.backhi = 0;
  bdecayv.hit.backhiover = 0;
  bdecayv.hit.backlo = 0;
  bdecayv.hit.sssd01 = 0;
  bdecayv.hit.tacpin01rf = 0;
  bdecayv.hit.taci2ntof = 0;
  bdecayv.hit.taci2stof = 0;
  bdecayv.hit.taci2pos = 0;
  bdecayv.hit.tacpin01xfp = 0;
  bdecayv.hit.tacpin02xfp = 0;

  /* Set front and back positions, multiplicities and energies
     for DSSD before starting */
  bdecay.front.dmax = 0;
  bdecay.front.dmaxch = 300;
  bdecay.front.dsum = 0;
  bdecay.front.dmult = 0;
  bdecay.front.dcent = 300;
  bdecay.front.imax = 0;
  bdecay.front.imaxch = 300;
  bdecay.front.isum = 0;
  bdecay.front.imult = 0;
  bdecay.front.icent = 300;
  bdecay.back.dmax = 0;
  bdecay.back.dmaxch = 300;
  bdecay.back.dsum = 0;
  bdecay.back.dmult = 0;
  bdecay.back.dcent = 300;
  bdecay.back.imax = 0;
  bdecay.back.imaxch = 300;
  bdecay.back.isum = 0;
  bdecay.back.imult = 0;
  bdecay.back.icent = 300;
  bdecay.ddasdiagnostics.front0116hihit = 0;
  bdecay.ddasdiagnostics.front1732hihit = 0;
  bdecay.ddasdiagnostics.front3348hihit = 0;
  bdecay.ddasdiagnostics.front0116lohit = 0;
  bdecay.ddasdiagnostics.front1732lohit = 0;
  bdecay.ddasdiagnostics.front3348lohit = 0;
  bdecay.ddasdiagnostics.back0116hihit = 0;
  bdecay.ddasdiagnostics.back1732hihit = 0;
  bdecay.ddasdiagnostics.back3348hihit = 0;
  bdecay.ddasdiagnostics.back0116lohit = 0;
  bdecay.ddasdiagnostics.back1732lohit = 0;
  bdecay.ddasdiagnostics.back3348lohit = 0;

/* Set sunfront and sunback positions, multiplicities and energies
     for DSSD before starting */
  gdecay.front.dmax = 0;
  gdecay.front.dmaxch = 300;
  gdecay.front.dsum = 0;
  gdecay.front.dmult = 0;
  gdecay.front.dcent = 300;
  gdecay.front.imax = 0;
  gdecay.front.imaxch = 300;
  gdecay.front.isum = 0;
  gdecay.front.imult = 0;
  gdecay.front.icent = 300;
  gdecay.back.dmax = 0;
  gdecay.back.dmaxch = 300;
  gdecay.back.dsum = 0;
  gdecay.back.dmult = 0;
  gdecay.back.dcent = 300;
  gdecay.back.imax = 0;
  gdecay.back.imaxch = 300;
  gdecay.back.isum = 0;
  gdecay.back.imult = 0;
  gdecay.back.icent = 300;

/* Set the sun time differences to zero before starting */
  for(int i=0;i<24;i++){
    gdecay.sun.dtdcf[i] = 0;
    gdecay.sun.dtimf[i] = 0;
  }

  bdecay.clock.dtCrate1Crate3 = 0;
  bdecay.clock.dtCrate1Crate2 = 0;

/* Set sun hit flags to zero before starting */
  gammav.hit.fronthi = 0;
  gammav.hit.fronthiover = 0;
  gammav.hit.frontlo = 0;
  gammav.hit.backhi = 0;
  gammav.hit.backhiover = 0;
  gammav.hit.backlo = 0;
  gammav.hit.sun = 0;



  /* PINs */

  /* Pin01 */
  if ( rEvent[bdecay.pin01.ecal.getId()].isValid() ) {
    //Set flag to 3 for light particles
    if ((bdecay.pin01.ecal) > (bdecayv.pin01.thresh) && 
	(bdecay.pin01.ecal) < (bdecayv.pin01.ithresh)){
	bdecayv.hit.pin01 = 3;
    }
    if ((bdecay.pin01.ecal) > (bdecayv.pin01.ithresh) &&
	(bdecay.pin01.ecal) < (bdecayv.pin01.iuld)) {
      bdecayv.hit.pin01 = 1;
      /* Increment total implant energies */
      implant_sumtotal += (long)bdecay.pin01.ecal; 
      implant_maxtotal += (long)bdecay.pin01.ecal;
    }
    else if((bdecay.pin01.ecal) > (bdecayv.pin01.ithresh)) {
      bdecayv.hit.pin01 = 2;
    }
  }

  /* Pin02 */
  if ( rEvent[bdecay.pin02.ecal.getId()].isValid() ) {
    //Set flag to 3 for light particles
    if ((bdecay.pin02.ecal) > (bdecayv.pin02.thresh) && 
	(bdecay.pin02.ecal) < (bdecayv.pin02.ithresh)){
	bdecayv.hit.pin02 = 3;
    }
    if ((bdecay.pin02.ecal) > (bdecayv.pin02.ithresh) &&
	(bdecay.pin02.ecal) < (bdecayv.pin02.iuld)) {
      bdecayv.hit.pin02 = 1;
      /* Increment total implant energies */
      implant_sumtotal += (long)bdecay.pin02.ecal; 
      implant_maxtotal += (long)bdecay.pin02.ecal;
    }
    else if((bdecay.pin02.ecal) > (bdecayv.pin02.ithresh)) {
      bdecayv.hit.pin02 = 2;
    }
  }

  /* Pin03 */  
  if ( rEvent[bdecay.pin03.ecal.getId()].isValid() ) {
    if ((bdecay.pin03.ecal) > (bdecayv.pin03.ithresh) &&
	(bdecay.pin03.ecal) < (bdecayv.pin03.iuld)) {
      bdecayv.hit.pin03 = 1;
      //Increment total implant energies 
      implant_sumtotal += (long)bdecay.pin03.ecal; 
      implant_maxtotal += (long)bdecay.pin03.ecal;
    }
    else if((bdecay.pin03.ecal) > (bdecayv.pin03.ithresh)) {
      bdecayv.hit.pin03 = 2;
    }
  }
 
  /* TACS */ 
  /*I2N*/
  if ( rEvent[bdecay.tac.i2ntof.getId()].isValid() ) {
    if (bdecay.tac.i2ntof > 0) {
      bdecayv.hit.taci2ntof = 1;
    }
  }

  /*I2S*/
  if ( rEvent[bdecay.tac.i2stof.getId()].isValid() ) {
    if (bdecay.tac.i2stof > 0) {
      bdecayv.hit.taci2stof = 1;
    }
  }

  /*I2POS*/ 
  if ( rEvent[bdecay.tac.i2pos.getId()].isValid() ) {
    if (bdecay.tac.i2pos > 0) {
      bdecayv.hit.taci2pos = 1;
    }
  }
  
  /*PIN01-XFP*/
  if ( rEvent[bdecay.tac.pin01xfp.getId()].isValid() ) {
    if (bdecay.tac.pin01xfp > 0) {
      bdecayv.hit.tacpin01xfp = 1;
    }
  }
  
  /*PIN02-XFP*/
  if ( rEvent[bdecay.tac.pin02xfp.getId()].isValid() ) {
    if (bdecay.tac.pin02xfp > 0) {
      bdecayv.hit.tacpin02xfp = 1;
    }
  }
 
  /* SCINTILLATOR */ 
  if ( rEvent[bdecay.scint.ecal.getId()].isValid() ) {
    if ((bdecay.scint.ecal) > (bdecayv.scint.ithresh) &&
	(bdecay.scint.ecal) < (bdecayv.scint.iuld)) {
      bdecayv.hit.scint = 1;
      //Increment total implant energies 
      //implant_sumtotal += (long)bdecay.scint.ecal; 
      //implant_maxtotal += (long)bdecay.scint.ecal;
    }
    else if((bdecay.scint.ecal) > (bdecayv.scint.ithresh)) {
      bdecayv.hit.scint = 2;
    }
   }

  /* BCS DSSD and SSSDs */
  isum = 0;
  dsum = 0;
  isumch = 0;
  dsumch = 0;
  imax = 0;
  imaxtimecfd = 0;
  imaxtimelow = 0;
  imaxtimehigh = 0;
  dmax = 0;
  dmaxtimecfd = 0;
  dmaxtimelow = 0;
  dmaxtimehigh = 0;
  imaxch = 0;
  dmaxch = 0;
  imult = 0;
  dmultf = 0;
  dmultb = 0;

   //  cout << "Start of DSSD Front" << endl;  
  /***** BCS DSSD FRONT *************************************************/
  
  /* Strips 1-40 Front (high and low) */

  for (i=1;i<41;i++) {
    
    /* Decay (high gain) */
    if ( rEvent[bdecay.front.hiecal[i].getId()].isValid() ) {
      if(bdecay.front.hiecal[i] > bdecayv.fthresh.duld[i]){
	bdecayv.hit.fronthiover = 1;    // at least one strip is an overflow
      }
      else  if ((bdecay.front.hiecal[i] >= bdecayv.fthresh.hithresh[i]) && 
	  (bdecay.front.hiecal[i] <= bdecayv.fthresh.duld[i])) {
	bdecayv.hit.fronthi = 1;

        bdecay.front.stripsThresh[dmultf]=i; // Filling array with strips that satisfy threshold cond.

        dmultf++; /* Increment multiplicity */
	/* Increment energy sum */
	dsum += long(bdecay.front.hiecal[i]); 
	/* Increment weighted sum */
	dsumch += i*long(bdecay.front.hiecal[i]); 
	  
	if (bdecay.front.hiecal[i] > dmax) {
	  /* Record maximum energy */
	  dmax = long(bdecay.front.hiecal[i]); 
	  dmaxch = i; /* Record location of maximum energy */
	  if ( rEvent[bdecay.front.hitimecfd[i].getId()].isValid() ) {
	    dmaxtimecfd = bdecay.front.hitimecfd[i];
	  } 
	  if ( rEvent[bdecay.front.hitimelow[i].getId()].isValid() ) {
	    dmaxtimelow = bdecay.front.hitimelow[i];
	  }
	  if ( rEvent[bdecay.front.hitimehigh[i].getId()].isValid() ) {
	    dmaxtimehigh = bdecay.front.hitimehigh[i];
	  }
	}
      
       if (i < 17) {
         bdecay.ddasdiagnostics.front0116hihit += pow(2.0,(i-1.0));
	 //temp2++;
	 //cout << "hit = " << temp2 << endl;
       }

       if ((i >= 17) && (i < 33)) {
         bdecay.ddasdiagnostics.front1732hihit += pow(2.0,(i-17.0));
       }

       if ((i >= 33) && (i < 49)) {
         bdecay.ddasdiagnostics.front3348hihit += pow(2.0,(i-33.0));
       }

      }
    }
   
    /* Implant (low gain) */
    if ( rEvent[bdecay.front.loecal[i].getId()].isValid() ) {
      if ( (bdecay.front.loecal[i] >= bdecayv.fthresh.lothresh[i]) &&
	   (bdecay.front.loecal[i] <= bdecayv.fthresh.loduld[i]) ) {

	bdecayv.hit.frontlo = 1;
	imult++; /* Increment multiplicity */
	/* Increment energy sum */
	isum += long(bdecay.front.loecal[i]);
	/* Increment weighted sum */
	isumch += i*long(bdecay.front.loecal[i]);  
	if (bdecay.front.loecal[i] > imax) {
	  /* Record maximum energy */
	  imax = long(bdecay.front.loecal[i]); 
	  imaxch = i; /* Record location of maximum energy */
	  if ( rEvent[bdecay.front.lotimecfd[i].getId()].isValid() ) {
	    imaxtimecfd = bdecay.front.lotimecfd[i];
	  } 
	  if ( rEvent[bdecay.front.lotimelow[i].getId()].isValid() ) {
	    imaxtimelow = bdecay.front.lotimelow[i];
	  }
	  if ( rEvent[bdecay.front.lotimehigh[i].getId()].isValid() ) {
	    imaxtimehigh = bdecay.front.lotimehigh[i];
	  }
	}

       if (i < 17) {
         bdecay.ddasdiagnostics.front0116lohit += pow(2.0,(i-1.0));
       }

       if ((i >= 17) && (i < 33)) {
         bdecay.ddasdiagnostics.front1732lohit += pow(2.0,(i-17.0));
       }

       if ((i >= 33) && (i < 49)) {
         bdecay.ddasdiagnostics.front3348lohit += pow(2.0,(i-33.0));
       }

      }
    }
  }
     
  if(bdecayv.hit.fronthi != 0) {
    calhitmask += 1; /* Add bit 0 to calorimeter hit mask for DSSD front */
    bdecay.front.dmult=dmultf;
    bdecay.front.dmax=dmax;
    bdecay.front.dmaxch=dmaxch; 
    bdecay.front.dsum=dsum;
    bdecay.front.dmaxtimecfd = dmaxtimecfd;
    bdecay.front.dmaxtimelow = dmaxtimelow;
    bdecay.front.dmaxtimehigh = dmaxtimehigh;

    if (dsum != 0) {
      bdecay.front.dcent = long(dsumch/dsum); // Decay centroid
    } else {
      bdecay.front.dcent = 100;
    }
    
    decay_sumtotal += dsum; /* Start accumulating total energy based on 
			       energy sums within each detector */
    decay_maxtotal += dmax; /* Start accumulating total energy based on 
			       maximum energy observed in each detector */
    }
  
  if(bdecayv.hit.frontlo != 0) {
    bdecay.front.imult=imult;
    bdecay.front.imax=imax;
    bdecay.front.imaxch=imaxch;
    bdecay.front.isum=isum;
    bdecay.front.imaxtimecfd = imaxtimecfd;
    bdecay.front.imaxtimelow = imaxtimelow;
    bdecay.front.imaxtimehigh = imaxtimehigh;

    if (isum != 0) {
      bdecay.front.icent = long(isumch/isum); // Implant centroid
    } else {
      bdecay.front.icent = 100;
    }
    
    implant_sumtotal += isum; /* Increment total implant energies */
    implant_maxtotal += imax;
    }

  /*if (dmultf == 1) {  
    mult1f++;
    cout << "mult1 front = " << mult1f << endl;
  }*/

  isum = 0;
  dsum = 0;
  isumch = 0;
  dsumch = 0;
  imax = 0;
  imaxtimecfd = 0;
  imaxtimelow = 0;
  imaxtimehigh = 0;
  dmax = 0;
  dmaxtimecfd = 0;
  dmaxtimelow = 0;
  dmaxtimehigh = 0;
  imaxch = 0;
  dmaxch = 0;
  imult = 0;
  //dmult = 0;

  // cout << "Start of DSSD Back" << endl; 
  /***** BCS DSSD BACK ***************************************************/

  /* Strips 1-40 Back (high and low) */

  for (i=1;i<41;i++) {
    
    /* Decay (high gain) */
    if ( rEvent[bdecay.back.hiecal[i].getId()].isValid() ) {
      if(bdecay.back.hiecal[i] > bdecayv.bthresh.duld[i]){
	bdecayv.hit.backhiover = 1;
      }
      else if ((bdecay.back.hiecal[i] >= bdecayv.bthresh.hithresh[i]) && 
	  (bdecay.back.hiecal[i] <= bdecayv.bthresh.duld[i])) {
	bdecayv.hit.backhi = 1;

	bdecay.back.stripsThresh[dmultb]=i; // Filling array with strips that satisfy threshold cond.

	dmultb++; /* Increment multiplicity */
	dsum += long(bdecay.back.hiecal[i]); /* Increment energy sum */
	/* Increment weighted sum */
	dsumch += i*long(bdecay.back.hiecal[i]); 

	if (bdecay.back.hiecal[i] > dmax) {
	  /* Record maximum energy */
	  dmax = long(bdecay.back.hiecal[i]); 
	  dmaxch = i; /* Record location of maximum energy */
	  if ( rEvent[bdecay.back.hitimecfd[i].getId()].isValid() ) {
	    dmaxtimecfd = bdecay.back.hitimecfd[i];
	  } 
	  if ( rEvent[bdecay.back.hitimelow[i].getId()].isValid() ) {
	    dmaxtimelow = bdecay.back.hitimelow[i];
	  }
	  if ( rEvent[bdecay.back.hitimehigh[i].getId()].isValid() ) {
	    dmaxtimehigh = bdecay.back.hitimehigh[i];
	  }
	}

       if (i < 17) {
         bdecay.ddasdiagnostics.back0116hihit += pow(2.0,(i-1.0));
       }

       if ((i >= 17) && (i < 33)) {
         bdecay.ddasdiagnostics.back1732hihit += pow(2.0,(i-17.0));
       }

       if ((i >= 33) && (i < 49)) {
         bdecay.ddasdiagnostics.back3348hihit += pow(2.0,(i-33.0));
       }
     
      }
    }

    /* Implant (low gain) */
    if ( rEvent[bdecay.back.loecal[i].getId()].isValid() ) {
      if ( (bdecay.back.loecal[i] >= bdecayv.bthresh.lothresh[i]) &&
	   (bdecay.back.loecal[i] <= bdecayv.bthresh.loduld[i])) {
	bdecayv.hit.backlo = 1;
	imult++; /* Increment multiplicity */
	isum += long(bdecay.back.loecal[i]); /* Increment energy sum */
	/* Increment weighted energy sum */
	isumch += i*long(bdecay.back.loecal[i]); 

	if (bdecay.back.loecal[i] > imax) {
	  /* Record maximum energy */
	  imax = long(bdecay.back.loecal[i]); 
	  imaxch = i; /* Record location of maximum energy */
	  if ( rEvent[bdecay.back.lotimecfd[i].getId()].isValid() ) {
	    imaxtimecfd = bdecay.back.lotimecfd[i];
	  } 
	  if ( rEvent[bdecay.back.lotimelow[i].getId()].isValid() ) {
	    imaxtimelow = bdecay.back.lotimelow[i];
	  }
	  if ( rEvent[bdecay.back.lotimehigh[i].getId()].isValid() ) {
	    imaxtimehigh = bdecay.back.lotimehigh[i];
	  }
	}
       if (i < 17) {
         bdecay.ddasdiagnostics.back0116lohit += pow(2.0,(i-1.0));
       }

       if ((i >= 17) && (i < 33)) {
         bdecay.ddasdiagnostics.back1732lohit += pow(2.0,(i-17.0));
       }

       if ((i >= 33) && (i < 49)) {
         bdecay.ddasdiagnostics.back3348lohit += pow(2.0,(i-33.0));
       }

      }
    }
  }
    
  if(bdecayv.hit.backhi != 0) {
    calhitmask += 2; /* Add bit 1 to calorimeter hit mask */
    bdecay.back.dmult=dmultb;
    bdecay.back.dmax=dmax;
    bdecay.back.dmaxtimecfd = dmaxtimecfd;
    bdecay.back.dmaxtimelow = dmaxtimelow;
    bdecay.back.dmaxtimehigh = dmaxtimehigh;
    bdecay.back.dmaxch=dmaxch;
    bdecay.back.dsum=dsum;

    if (dsum != 0) {
      bdecay.back.dcent = long(dsumch/dsum); // Decay centroid
    } else {
      bdecay.back.dcent = 100;
    }
    // decay_sumtotal += dsum; /* Start accumulating total energy based on 
    //			       energy sums within each detector */
    // decay_maxtotal += dmax; /* Start accumulating total energy based on 
    //			       maximum energy observed in each detector */
  }
     
  if(bdecayv.hit.backlo != 0) {
    bdecay.back.imult=imult;
    bdecay.back.imax=imax;
    bdecay.back.imaxtimecfd = imaxtimecfd;
    bdecay.back.imaxtimelow = imaxtimelow;
    bdecay.back.imaxtimehigh = imaxtimehigh;
    bdecay.back.imaxch=imaxch;
    bdecay.back.isum=isum;
    
    if (isum != 0) {
      bdecay.back.icent = long(isumch/isum); // Implant centroid
    } else {
      bdecay.back.icent = 100;
    }
    // implant_sumtotal += isum; /* Increment total implant energies */
    // implant_maxtotal += imax;
  }

  /*if (dmultb == 1) {  
    mult1b++;
    cout << "mult1 back = " << mult1b << endl;
  }

  if ((dmultb == 1) && (dmultf == 1)){
	mult1fb++;
	cout << "mult1 front and back = " << mult1fb << endl;
  }*/
  
  //check for gain match condition on decays
  if(bdecayv.hit.fronthi != 0 && bdecayv.hit.backhi !=0){

    //calculate diff in energy between front and back
    double diff = fabs(bdecay.front.dmax - bdecay.back.dmax);
    double perdifff = diff / bdecay.front.dmax;
    double perdiffb = diff / bdecay.back.dmax;

    //cout << "diffs " << bdecay.front.dmax << " " << bdecay.back.dmax << " " <<diff << " " << perdiff << endl;

    double ftime =  (bdecay.front.dmaxtimelow + bdecay.front.dmaxtimehigh*4294967296.)*10.;  // In ns
    double btime =  (bdecay.back.dmaxtimelow + bdecay.back.dmaxtimehigh*4294967296.)*10.;

    bdecay.back.dtdiff  = (btime - ftime + 25000);
    bdecay.front.dtdiff = (ftime - btime + 25000);
    bdecay.front.dediff = perdifff;
    bdecay.back.dediff  = perdiffb;

  }

  //check for gain match condition on implants
  if(bdecayv.hit.frontlo != 0 && bdecayv.hit.backlo !=0){

    //calculate diff in energy between front and back
    double diff = fabs(bdecay.front.imax - bdecay.back.imax);
    double perdifff = diff / bdecay.front.imax;
    double perdiffb = diff / bdecay.back.imax;

    //cout << "diffs " << bdecay.front.dmax << " " << bdecay.back.dmax << " " <<diff << " " << perdiff << endl;

    double ftime =  (bdecay.front.imaxtimelow + bdecay.front.imaxtimehigh*4294967296.)*10.;  // In ns
    double btime =  (bdecay.back.imaxtimelow + bdecay.back.imaxtimehigh*4294967296.)*10.;

    bdecay.back.itdiff  = (btime - ftime + 25000);
    bdecay.front.itdiff = (ftime - btime + 25000);
    bdecay.front.iediff = perdifff;
    bdecay.back.iediff  = perdiffb;

  }
  
  /* Implant and decay totals */ 
  bdecay.total.isum = implant_sumtotal;
  bdecay.total.imax = implant_maxtotal;
  
  bdecay.total.dsum = decay_sumtotal;
  bdecay.total.dmax = decay_maxtotal;

   /***** SSSDs ***********************************************************/
  //Using 1 sssd for this experiment
  
    sum = 0;
    sumch = 0;
    max = 0;
    maxch = 0;
    mult = 0;

  for (i=2; i<17; i++) {
    
    if ( rEvent[bdecay.sssd01.ecal[i].getId()].isValid() ) {
      if ((bdecay.sssd01.ecal[i] >= bdecayv.sssd01.thresh[i]) &&
	  (bdecay.sssd01.ecal[i] <= bdecayv.sssd01.uld[i])) {
	bdecayv.hit.sssd01 = 1;
	mult++;  //Increment multiplicity 
	sum += long(bdecay.sssd01.ecal[i]); // Increment energy sum 
	sumch += i*long(bdecay.sssd01.ecal[i]); // Increment weighted sum 

	if (bdecay.sssd01.ecal[i] > max) {
	  max = long(bdecay.sssd01.ecal[i]); // Record maximum energy 
	  maxch = i; // Record location of maximum energy 
	}
      }
    }
  }
  if (bdecayv.hit.sssd01 != 0) {
    calhitmask += 4; // Add bit 2 to calorimeter hit mask 
    bdecay.sssd01.mult = mult;
    bdecay.sssd01.max = max;
    bdecay.sssd01.maxch = maxch;
    bdecay.sssd01.sum = sum;
    
    if (sum != 0) {
      bdecay.sssd01.cent = long(sumch/sum); // Calculate centroid 
    } else {
      bdecay.sssd01.cent = 100;
    }

    dsumtotal += sum; // Increment sum-based total energy 
    dmaxtotal += max; // Increment maximum-based total energy 
  }
  
  // end of the SSSD section 
  
  bdecay.bit.calhitmask = calhitmask;
  if(bdecayv.hit.frontlo == 1){
	bcsmask += 2;
  }
  if(bdecayv.hit.backlo == 1){
	bcsmask += 3;
  }
  if(bdecayv.hit.sssd01 == 1){
	bcsmask += 7;
  }
  bdecay.bit.bcsmask = bcsmask;

  /* Total implant energy */
  bdecay.pid.isum = bdecay.total.isum; 
  bdecay.pid.imax = bdecay.total.imax; 

 //  cout << "after SSSDs" << endl;

 /******************* SuN DSSD *********************/
 /******************* SuN DSSD *********************/
 /******************* SuN DSSD *********************/
 /******************* SuN DSSD *********************/
 
/* DSSD and SSSD maximum energies */
  long dmax2, dmax3, dmax4; 
  long fpixeldmax, fpixeldmax2, fpixeldmax3, fpixeldmax4;
  long bpixeldmax, bpixeldmax2, bpixeldmax3, bpixeldmax4;
  long pixeldsum, pixeldsumch;
   
  /* DSSD and SSSD energy peaks */
  long dmax2ch, dmax3ch, dmax4ch; 
  long fpixeldmaxch, fpixeldmax2ch, fpixeldmax3ch, fpixeldmax4ch;
  long bpixeldmaxch, bpixeldmax2ch, bpixeldmax3ch, bpixeldmax4ch;

  /* DSSD mult */ 
  long dmult, gmult, suntotal, xmatrix, ymatrix;
 /* SuN DSSD */
  isum = 0;
  dsum = 0;
  pixeldsum = 0;
  isumch = 0;
  dsumch = 0;
  pixeldsumch = 0;
  imax = 0;
  imaxtimecfd = 0;
  imaxtimelow = 0;
  imaxtimehigh = 0;
  dmax = 0;
  dmaxtimecfd = 0;
  dmaxtimelow = 0;
  dmaxtimehigh = 0;
  imaxch = 0;
  dmaxch = 0;
  dmax2 = 0;
  dmax2ch = 0;
  dmax3 = 0;
  dmax3ch = 0;
  dmax3 = 0;
  dmax3ch = 0;
  fpixeldmax = 0;
  fpixeldmax2 = 0;
  fpixeldmax3 = 0;
  fpixeldmax4 = 0;
  fpixeldmaxch = 0;
  fpixeldmax2ch = 0;
  fpixeldmax3ch = 0;
  fpixeldmax4ch = 0;
  
  bpixeldmax = 0;
  bpixeldmax2 = 0;
  bpixeldmax3 = 0;
  bpixeldmax4 = 0;
  bpixeldmaxch = 0;
  bpixeldmax2ch = 0;
  bpixeldmax3ch = 0;
  bpixeldmax4ch = 0;

  imult = 0;
  dmult = 0;

    
  /***** SUN DSSD FRONT ********************************************/
  
  /* Strips 0-15 Front (high and low) */

  for (i=0;i<16;i++) {
    
    /* Decay (high gain) */
    if ( rEvent[gdecay.front.hiecal[i].getId()].isValid() ) {
      if(gdecay.front.hiecal[i] > gammav.fthresh.duld[i]){
	gammav.hit.fronthiover = 1;
      }
      else  if ((gdecay.front.hiecal[i] >= gammav.fthresh.hithresh[i]) && 
	  (gdecay.front.hiecal[i] <= gammav.fthresh.duld[i])) {
	gammav.hit.fronthi = 1;
	dmult++; /* Increment multiplicity */
	/* Increment energy sum */
	dsum += long(gdecay.front.hiecal[i]); 
	/* Increment weighted sum */
	dsumch += i*long(gdecay.front.hiecal[i]); 
	  
	if (gdecay.front.hiecal[i] > dmax) {
	  /* Record maximum energy */
	  dmax = long(gdecay.front.hiecal[i]); 
	  dmaxch = i; /* Record location of maximum energy */
	  if ( rEvent[gdecay.front.hitimecfd[i].getId()].isValid() ) {
	    dmaxtimecfd = gdecay.front.hitimecfd[i];
	  } 
	  if ( rEvent[gdecay.front.hitimelow[i].getId()].isValid() ) {
	    dmaxtimelow = gdecay.front.hitimelow[i];
	  }
	  if ( rEvent[gdecay.front.hitimehigh[i].getId()].isValid() ) {
	    dmaxtimehigh = gdecay.front.hitimehigh[i];
	  }
	}
      }
    }
    /* Implant (low gain) */
    if ( rEvent[gdecay.front.loecal[i].getId()].isValid() ) {
      if ( (gdecay.front.loecal[i] >= gammav.fthresh.lothresh[i]) &&
	   (gdecay.front.loecal[i] <= gammav.fthresh.loduld[i]) ) {

	gammav.hit.frontlo = 1;
	imult++; /* Increment multiplicity */
	/* Increment energy sum */
	isum += long(gdecay.front.loecal[i]);
	/* Increment weighted sum */
	isumch += i*long(gdecay.front.loecal[i]);  
	if (gdecay.front.loecal[i] > imax) {
	  /* Record maximum energy */
	  imax = long(gdecay.front.loecal[i]); 
	  imaxch = i; /* Record location of maximum energy */
	  if ( rEvent[gdecay.front.lotimecfd[i].getId()].isValid() ) {
	    imaxtimecfd = gdecay.front.lotimecfd[i];
	  } 
	  if ( rEvent[gdecay.front.lotimelow[i].getId()].isValid() ) {
	    imaxtimelow = gdecay.front.lotimelow[i];
	  }
	  if ( rEvent[gdecay.front.lotimehigh[i].getId()].isValid() ) {
	    imaxtimehigh = gdecay.front.lotimehigh[i];
	  }
	}
      }
    }
  }
  //finding the four highest energy strips
  for (i=0;i<16;i++) {     
    if (( rEvent[gdecay.front.hiecal[i].getId()].isValid() ) &&((gdecay.front.hiecal[i] >= gammav.fthresh.hithresh[i]) && 
							    (gdecay.front.hiecal[i] <= gammav.fthresh.duld[i]))){
      if((gdecay.front.hiecal[i]<dmax)&&(gdecay.front.hiecal[i]>dmax2)){
	  dmax2=gdecay.front.hiecal[i];
	  dmax2ch=i;
	}
    }
  }
  for (i=0;i<16;i++) {     
    if (( rEvent[gdecay.front.hiecal[i].getId()].isValid() ) &&((gdecay.front.hiecal[i] >= gammav.fthresh.hithresh[i]) && 
							    (gdecay.front.hiecal[i] <= gammav.fthresh.duld[i]))){
      if((gdecay.front.hiecal[i]<dmax2)&&(gdecay.front.hiecal[i]>dmax3)){
	  dmax3=gdecay.front.hiecal[i];
	  dmax3ch=i;
	}
    }
  }
  for (i=0;i<16;i++) {     
    if (( rEvent[gdecay.front.hiecal[i].getId()].isValid() ) &&((gdecay.front.hiecal[i] >= gammav.fthresh.hithresh[i]) && 
							    (gdecay.front.hiecal[i] <= gammav.fthresh.duld[i]))){
      if((gdecay.front.hiecal[i]<dmax2)&&(gdecay.front.hiecal[i]>dmax4)){
	  dmax4=gdecay.front.hiecal[i];
	  dmax4ch=i;
	}
    }
  }
  if(gammav.hit.fronthi != 0) {
    calhitmask += 1; /* Add bit 0 to calorimeter hit mask for DSSD front */
    gdecay.front.dmult=dmult;
    gdecay.front.dmax=dmax;
    gdecay.front.dmaxch=dmaxch;
    gdecay.front.dmaxarray[0]=dmax;
    gdecay.front.dmaxcharray[0]=dmaxch;
    gdecay.front.dmaxarray[1]=dmax2;
    gdecay.front.dmaxcharray[1]=dmax2ch;
    gdecay.front.dmaxarray[2]=dmax3;
    gdecay.front.dmaxcharray[2]=dmax3ch;
    gdecay.front.dmaxarray[3]=dmax4;
    gdecay.front.dmaxcharray[3]=dmax4ch;
    gdecay.front.dsum=dsum;
    gdecay.front.dmaxtimecfd = dmaxtimecfd;
    gdecay.front.dmaxtimelow = dmaxtimelow;
    gdecay.front.dmaxtimehigh = dmaxtimehigh;

    if (dsum != 0) {
      gdecay.front.dcent = long(dsumch/dsum); // Decay centroid
    } else {
      gdecay.front.dcent = 100;
    }
    
    decay_sumtotal += dsum; /* Start accumulating total energy based on 
			       energy sums within each detector */
    decay_maxtotal += dmax; /* Start accumulating total energy based on 
			       maximum energy observed in each detector */
    }
  
  if(gammav.hit.frontlo != 0) {
    gdecay.front.imult=imult;
    gdecay.front.imax=imax;
    gdecay.front.imaxch=imaxch;
    gdecay.front.isum=isum;
    gdecay.front.imaxtimecfd = imaxtimecfd;
    gdecay.front.imaxtimelow = imaxtimelow;
    gdecay.front.imaxtimehigh = imaxtimehigh;

    if (isum != 0) {
      gdecay.front.icent = long(isumch/isum); // Implant centroid
    } else {
      gdecay.front.icent = 100;
    }
    
    implant_sumtotal += isum; /* Increment total implant energies */
    implant_maxtotal += imax;
    }

  isum = 0;
  dsum = 0;
  isumch = 0;
  dsumch = 0;
  imax = 0;
  imaxtimecfd = 0;
  imaxtimelow = 0;
  imaxtimehigh = 0;
  dmax = 0;
  dmaxtimecfd = 0;
  dmaxtimelow = 0;
  dmaxtimehigh = 0;
  imaxch = 0;
  dmaxch = 0;
  dmax2 = 0;
  dmax2ch = 0;
  dmax3 = 0;
  dmax3ch = 0;
  dmax4 = 0;
  dmax4ch = 0;
  imult = 0;
  dmult = 0;

  
  /***** SUN DSSD BACK ************************************************/

  /* Strips 0-15 Back (high and low) */

  for (i=0;i<16 ;i++) {
    
    /* Decay (high gain) */
    if ( rEvent[gdecay.back.hiecal[i].getId()].isValid() ) {
      if(gdecay.back.hiecal[i] > gammav.bthresh.duld[i]){
	gammav.hit.backhiover = 1;
      }
      else if ((gdecay.back.hiecal[i] >= gammav.bthresh.hithresh[i]) && 
	  (gdecay.back.hiecal[i] <= gammav.bthresh.duld[i])) {
	gammav.hit.backhi = 1;
	dmult++; /* Increment multiplicity */
	dsum += long(gdecay.back.hiecal[i]); /* Increment energy sum */
	/* Increment weighted sum */
	dsumch += i*long(gdecay.back.hiecal[i]); 

	if (gdecay.back.hiecal[i] > dmax) {
	  /* Record maximum energy */
	  dmax = long(gdecay.back.hiecal[i]); 
	  dmaxch = i; /* Record location of maximum energy */
	  if ( rEvent[gdecay.back.hitimecfd[i].getId()].isValid() ) {
	    dmaxtimecfd = gdecay.back.hitimecfd[i];
	  } 
	  if ( rEvent[gdecay.back.hitimelow[i].getId()].isValid() ) {
	    dmaxtimelow = gdecay.back.hitimelow[i];
	  }
	  if ( rEvent[gdecay.back.hitimehigh[i].getId()].isValid() ) {
	    dmaxtimehigh = gdecay.back.hitimehigh[i];
	  }
	}
      }
    }

    /* Implant (low gain) */
    if ( rEvent[gdecay.back.loecal[i].getId()].isValid() ) {
      if ( (gdecay.back.loecal[i] >= gammav.bthresh.lothresh[i]) &&
	   (gdecay.back.loecal[i] <= gammav.bthresh.loduld[i])) {
	gammav.hit.backlo = 1;
	imult++; /* Increment multiplicity */
	isum += long(gdecay.back.loecal[i]); /* Increment energy sum */
	/* Increment weighted energy sum */
	isumch += i*long(gdecay.back.loecal[i]); 

	if (gdecay.back.loecal[i] > imax) {
	  /* Record maximum energy */
	  imax = long(gdecay.back.loecal[i]); 
	  imaxch = i; /* Record location of maximum energy */
	  if ( rEvent[gdecay.back.lotimecfd[i].getId()].isValid() ) {
	    imaxtimecfd = gdecay.back.lotimecfd[i];
	  } 
	  if ( rEvent[gdecay.back.lotimelow[i].getId()].isValid() ) {
	    imaxtimelow = gdecay.back.lotimelow[i];
	  }
	  if ( rEvent[gdecay.back.lotimehigh[i].getId()].isValid() ) {
	    imaxtimehigh = gdecay.back.lotimehigh[i];
	  }
	}
      }
    }
  }
  for (i=0;i<16;i++) {
    if (( rEvent[gdecay.back.hiecal[i].getId()].isValid() )&&  ((gdecay.back.hiecal[i] >= gammav.bthresh.hithresh[i]) && 
								(gdecay.back.hiecal[i] <= gammav.bthresh.duld[i]))){
      if((gdecay.back.hiecal[i]<dmax)&&(gdecay.back.hiecal[i]<dmax2)){
	dmax2=gdecay.back.hiecal[i];
	dmax2ch=i;
      }
    }
  }
  for (i=0;i<16;i++) {
    if (( rEvent[gdecay.back.hiecal[i].getId()].isValid() )&&  ((gdecay.back.hiecal[i] >= gammav.bthresh.hithresh[i]) && 
								(gdecay.back.hiecal[i] <= gammav.bthresh.duld[i]))){
      if((gdecay.back.hiecal[i]<dmax2)&&(gdecay.back.hiecal[i]<dmax3)){
	dmax3=gdecay.back.hiecal[i];
	dmax3ch=i;
      }
    }
  }
  for (i=0;i<16;i++) {
    if (( rEvent[gdecay.back.hiecal[i].getId()].isValid() )&&  ((gdecay.back.hiecal[i] >= gammav.bthresh.hithresh[i]) && 
								(gdecay.back.hiecal[i] <= gammav.bthresh.duld[i]))){
      if((gdecay.back.hiecal[i]<dmax3)&&(gdecay.back.hiecal[i]<dmax4)){
	dmax4=gdecay.back.hiecal[i];
	dmax4ch=i;
      }
    }
  }
  if(gammav.hit.backhi != 0) {
    calhitmask += 2; /* Add bit 1 to calorimeter hit mask */
    gdecay.back.dmult=dmult;
    gdecay.back.dmax=dmax;
    gdecay.back.dmaxtimecfd = dmaxtimecfd;
    gdecay.back.dmaxtimelow = dmaxtimelow;
    gdecay.back.dmaxtimehigh = dmaxtimehigh;
    gdecay.back.dmaxch=dmaxch;
    gdecay.back.dmaxarray[0]=dmax;
    gdecay.back.dmaxcharray[0]=dmaxch;
    gdecay.back.dmaxarray[1]=dmax2;
    gdecay.back.dmaxcharray[1]=dmax2ch;
    gdecay.back.dmaxarray[2]=dmax3;
    gdecay.back.dmaxcharray[2]=dmax3ch;
    gdecay.back.dmaxarray[3]=dmax4;
    gdecay.back.dmaxcharray[3]=dmax4ch;
    gdecay.back.dsum=dsum;

    if (dsum != 0) {
      gdecay.back.dcent = long(dsumch/dsum); // Decay centroid
    } else {
      gdecay.back.dcent = 100;
    }
    // decay_sumtotal += dsum; /* Start accumulating total energy based on 
    //			       energy sums within each detector */
    // decay_maxtotal += dmax; /* Start accumulating total energy based on 
    //			       maximum energy observed in each detector */
  }

if(gammav.hit.backlo != 0) {
    gdecay.back.imult=imult;
    gdecay.back.imax=imax;
    gdecay.back.imaxtimecfd = imaxtimecfd;
    gdecay.back.imaxtimelow = imaxtimelow;
    gdecay.back.imaxtimehigh = imaxtimehigh;
    gdecay.back.imaxch=imaxch;
    gdecay.back.isum=isum;
    
    if (isum != 0) {
      gdecay.back.icent = long(isumch/isum); // Implant centroid
    } else {
      gdecay.back.icent = 100;
    }
    // implant_sumtotal += isum; /* Increment total implant energies */
    // implant_maxtotal += imax;
  }


  //checkfor gain match condition on decays
  if(gammav.hit.fronthi != 0 && gammav.hit.backhi !=0){

    //calculate diff in energy between front and back
    double diff = fabs(gdecay.front.dmax - gdecay.back.dmax);
    double perdifff = diff / gdecay.front.dmax;
    double perdiffb = diff / gdecay.back.dmax;

    //cout << "diffs " << bdecay.front.dmax << " " << bdecay.back.dmax << " " <<diff << " " << perdiff << endl;

    double ftime =  (gdecay.front.dmaxtimelow + gdecay.front.dmaxtimehigh*4294967296.)*10.; // In ns
    double btime =  (gdecay.back.dmaxtimelow + gdecay.back.dmaxtimehigh*4294967296.)*10.;

    gdecay.back.dtdiff  = (btime - ftime + 25000);
    gdecay.front.dtdiff = (ftime - btime + 25000);
    gdecay.front.dediff = perdifff;
    gdecay.back.dediff  = perdiffb;

  }

  //checkfor gain match condition on implants
  if(gammav.hit.frontlo != 0 && gammav.hit.backlo !=0){

    //calculate diff in energy between front and back
    double diff = fabs(gdecay.front.imax - gdecay.back.imax);
    double perdifff = diff / gdecay.front.imax;
    double perdiffb = diff / gdecay.back.imax;

    //cout << "diffs " << bdecay.front.dmax << " " << bdecay.back.dmax << " " <<diff << " " << perdiff << endl;

    double ftime =  (gdecay.front.imaxtimelow + gdecay.front.imaxtimehigh*4294967296.)*10.;  // In ns
    double btime =  (gdecay.back.imaxtimelow + gdecay.back.imaxtimehigh*4294967296.)*10.;

    gdecay.back.itdiff  = (btime - ftime + 25000);
    gdecay.front.itdiff = (ftime - btime + 25000);
    gdecay.front.iediff = perdifff;
    gdecay.back.iediff  = perdiffb;

  }


  /* Implant and decay totals */ 
  gdecay.total.isum = implant_sumtotal;
  gdecay.total.imax = implant_maxtotal;
  
  gdecay.total.dsum = decay_sumtotal;
  gdecay.total.dmax = decay_maxtotal;
 
  gdecay.bit.calhitmask = calhitmask;
  
  /* Total implant energy */
  bdecay.pid.isum = gdecay.total.isum; 
  bdecay.pid.imax = gdecay.total.imax; 

  /*Implant energy on the back and front side of DSSD, no PINs added*/
 //  cout<<"I am here"<<endl;
   bdecay.pid.fisum = gdecay.front.isum; 
   bdecay.pid.bisum = gdecay.back.isum; 
   bdecay.pid.fimax = gdecay.front.imax; 
   bdecay.pid.bimax = gdecay.back.imax; 


  //cout << "after SuN DSSDs" << endl;
 
 //************* VETO **************************************************/
  if ( rEvent[gdecay.veto.energy.getId()].isValid() ) {
    if ((gdecay.veto.energy) > (bdecayv.veto.ithresh) &&
	(gdecay.veto.energy) < (bdecayv.veto.iuld)) {
      bdecayv.hit.veto = 1;
    }
   }

  
  /***** NERO *********************************************************/ 
 //cout << "Start of NERO" << endl; 
 long neromult = 0;
 nero.bit.quadAhitpattern = 0;
 nero.bit.quadBhitpattern = 0;
 nero.bit.quadChitpattern = 0;
 nero.bit.quadDhitpattern = 0;
 uint_64 nerohit =0;
 uint_64 BCStime = 0;
 uint_64 SUNtime = 0;
 uint_64 nerotime = 0;
 uint_64 neroANYtime = 0;
 uint_64 deltat = 0;


 for (i=1;i<61;i++) { 
//    cout << "in for loop: " << i << endl;
   if ( rEvent[nero.ecal[i].getId()].isValid() ) {
      if(nero.ecal[i] > nerov.nerothres.uthres[i]){
	nerov.nerohit.neroover = 1;
      }
      else if ((nero.ecal[i] >= nerov.nerothres.lthres[i]) && 
	  (nero.ecal[i] <= nerov.nerothres.uthres[i])) {
	nerohit = 1;
        if (i < 16) {
        nero.bit.quadAhitpattern += pow(2.0,(i-1.0));
        }
	else if (i < 31) {
        nero.bit.quadBhitpattern += pow(2.0,(i-16.0));
        }
	else if (i < 46) {
        nero.bit.quadChitpattern += pow(2.0,(i-31.0));
        }
	else if (i < 61) {
        nero.bit.quadDhitpattern += pow(2.0,(i-46.0));
        }
	neromult++; /* Increment multiplicity */
      }
    }

/* COMMENTED OUT ON 2/12 ************************
 ************************************************
       was causing a CTreeParamter[] operator Error 
        i wanna say it's because of the nero parameter declarations in Paramaters.cpp
 ************************************************
 ************************************************
*/
/*

    cout << "After if" << endl;
    BCStime = 0;
    SUNtime = 0;
    nerotime = 0;
    cout << "before testing" << endl; 

    if ( rEvent[nero.timecfd[i].getId()].isValid() &&
	 rEvent[nero.timelow[i].getId()].isValid() &&
         rEvent[nero.timehigh[i].getId()].isValid() && 
         rEvent[bdecay.front.dmaxtimecfd.getId()].isValid() &&
	 rEvent[bdecay.front.dmaxtimelow.getId()].isValid() &&
	 rEvent[bdecay.front.dmaxtimehigh.getId()].isValid() ) {

    cout << "in if" << endl;
	nerotime = ((nero.timecfd[i]/32768.) + nero.timelow[i] + (nero.timehigh[i]*4294967296.))*10.;   // In ns
        BCStime = ((bdecay.front.dmaxtimecfd/32768.) + bdecay.front.dmaxtimelow + (bdecay.front.dmaxtimehigh*4294967296.))*10.; // In ns

    cout << "in if" << endl;
        if (nerotime > BCStime - 25000) {
 	     deltat = nerotime - BCStime + 25000; 
        }
        else {
	     deltat = 0;
        }
    	nero.tdiffBCS[i] = deltat;
    }
    if ( rEvent[nero.timecfd[i].getId()].isValid() &&
	 rEvent[nero.timelow[i].getId()].isValid() &&
         rEvent[nero.timehigh[i].getId()].isValid() && 
         rEvent[gdecay.front.dmaxtimecfd.getId()].isValid() &&
	 rEvent[gdecay.front.dmaxtimelow.getId()].isValid() &&
	 rEvent[gdecay.front.dmaxtimehigh.getId()].isValid() ) {
   
	nerotime = ((nero.timecfd[i]/32768.) + nero.timelow[i] + (nero.timehigh[i]*4294967296.))*10.;    // In ns
        SUNtime = ((gdecay.front.dmaxtimecfd/32768.) + gdecay.front.dmaxtimelow + (gdecay.front.dmaxtimehigh*4294967296.))*10.;   // In ns

        if (nerotime > SUNtime - 25000) {
 	     deltat = nerotime - SUNtime + 25000; 
        }
        else {
	     deltat = 0;
        }
    	nero.tdiffSUN[i] = deltat;
    }
    if ( rEvent[nero.timecfd[i].getId()].isValid() &&
	 rEvent[nero.timelow[i].getId()].isValid() &&
         rEvent[nero.timehigh[i].getId()].isValid() ) {
         	neroANYtime = ((nero.timecfd[i]/32768.) + nero.timelow[i] + (nero.timehigh[i]*4294967296.)) *10.;  // In ns
    }


*/
 }
// cout << "after first for loop" << endl;
 nero.bit.multiplicity = neromult;
 nero.hit = nerohit;
/* if (neromult !=0 ) {
	cout << "neromult = " << neromult << endl;
  	cout << "nero.bit.multiplicity = " << nero.bit.multiplicity << endl;
 }*/
 
// cout << "after second for loop" << endl;

 /** Time differences ******************************************/ 




/* Calculate time difference between PIN01 and TACi2n*/


  uint_64 pin01time = 0;
  uint_64 tactime = 0;
 

  
  




    if (rEvent[bdecay.pin01.timecfd.getId()].isValid() &&
        rEvent[bdecay.pin01.timelow.getId()].isValid() &&
	rEvent[bdecay.pin01.timehigh.getId()].isValid() &&
	rEvent[bdecay.tac.i2ntoftimecfd.getId()].isValid() &&
	rEvent[bdecay.tac.i2ntoftimelow.getId()].isValid() &&
	rEvent[bdecay.tac.i2ntoftimehigh.getId()].isValid() ) { 



     
      pin01time = 0;
      tactime = 0;
      deltat = 0;

      if((bdecay.pin01.ecal>bdecayv.pin01.ithresh)&&(bdecay.pin01.ecal<bdecayv.pin01.iuld))
     {
      
      pin01time = ((bdecay.pin01.timecfd/65536.) + bdecay.pin01.timelow + (bdecay.pin01.timehigh*4294967296.))*10.;

      tactime =( (bdecay.tac.i2ntoftimecfd/65536.) + bdecay.tac.i2ntoftimelow+ (bdecay.tac.i2ntoftimehigh*4294967296.))*10.;

     
 
      
      deltat = tactime - pin01time +25000 ;

     
     
     
      bdecay.tac.dt_pin01 = deltat;
     }
 
     } 




 
/* Calculate time difference between PIN01 and front side of SuN DSSD with implant events*/


 
  uint_64 dssdtime = 0;
  




    if (rEvent[bdecay.pin01.timecfd.getId()].isValid() &&
        rEvent[bdecay.pin01.timelow.getId()].isValid() &&
	rEvent[bdecay.pin01.timehigh.getId()].isValid() &&
	rEvent[bdecay.front.imaxtimecfd.getId()].isValid() &&
	rEvent[bdecay.front.imaxtimelow.getId()].isValid() &&
	rEvent[bdecay.front.imaxtimehigh.getId()].isValid() ) { 



     
      pin01time = 0;
      dssdtime = 0;
      deltat = 0;

      if((bdecay.pin01.ecal>bdecayv.pin01.ithresh)&&(bdecay.pin01.ecal<bdecayv.pin01.iuld))
     {
      
      pin01time = ((bdecay.pin01.timecfd/65536.) + bdecay.pin01.timelow + (bdecay.pin01.timehigh*4294967296.))*10.;

      dssdtime = ((bdecay.front.imaxtimecfd/65536.) + bdecay.front.imaxtimelow+ (bdecay.front.imaxtimehigh*4294967296.))*10.;

     
 
      
      deltat = dssdtime - pin01time +25000 ;

     
     
     
      bdecay.pin01.dt_imf = deltat;
     }
 
     } 


/* Calculate time difference between PIN02 and front side of SuN DSSD with implant events*/


 uint_64 pin02time = 0;
  


    if (rEvent[bdecay.pin02.timecfd.getId()].isValid() &&
        rEvent[bdecay.pin02.timelow.getId()].isValid() &&
	rEvent[bdecay.pin02.timehigh.getId()].isValid() &&
	rEvent[bdecay.front.imaxtimecfd.getId()].isValid() &&
	rEvent[bdecay.front.imaxtimelow.getId()].isValid() &&
	rEvent[bdecay.front.imaxtimehigh.getId()].isValid() ) { 



     
      pin02time = 0;
      dssdtime = 0;
      deltat = 0;

      if((bdecay.pin02.ecal>bdecayv.pin02.ithresh)&&(bdecay.pin02.ecal<bdecayv.pin02.iuld))
     {
      
      pin02time = ((bdecay.pin02.timecfd/65536.) + bdecay.pin02.timelow + (bdecay.pin02.timehigh*4294967296.))*10.;

      dssdtime = ((bdecay.front.imaxtimecfd/65536.) + bdecay.front.imaxtimelow+ (bdecay.front.imaxtimehigh*4294967296.))*10.;

      
 
      
      deltat = dssdtime - pin02time +25000 ;

     
     
     
      bdecay.pin02.dt_imf = deltat;
     }
 
     } 

/* Calculate time difference between PIN01 and PIN02 */

     if (rEvent[bdecay.pin01.timecfd.getId()].isValid() &&
        rEvent[bdecay.pin01.timelow.getId()].isValid() &&
	rEvent[bdecay.pin01.timehigh.getId()].isValid() &&
	rEvent[bdecay.pin02.timecfd.getId()].isValid() &&
	rEvent[bdecay.pin02.timelow.getId()].isValid() &&
	rEvent[bdecay.pin02.timehigh.getId()].isValid() ) { 



     
      pin01time = 0;
      pin02time = 0;
      deltat = 0;

      if((bdecay.pin01.ecal>bdecayv.pin01.ithresh)&&(bdecay.pin01.ecal<bdecayv.pin01.iuld) && (bdecay.pin02.ecal>bdecayv.pin02.ithresh)&&(bdecay.pin02.ecal<bdecayv.pin02.iuld))
     {
      
      pin01time = ((bdecay.pin01.timecfd/65536.) + bdecay.pin01.timelow + (bdecay.pin01.timehigh*4294967296.))*10.;

      pin02time = ((bdecay.pin02.timecfd/65536.) + bdecay.pin02.timelow + (bdecay.pin02.timehigh*4294967296.))*10.;

     
 
      
      deltat = pin02time - pin01time +25000 ;

     
     
     
      bdecay.pin01.dt_pin01_pin02 = deltat;
     }
 
     } 


//Check time differences between pulsers
 uint_64 p1time = 0;
 uint_64 p2time = 0;
 uint_64 p3time = 0;
//Time diff between BCS pulser and NERO pulser

       if (rEvent[bdecay.raw.chanid[160].timecfd.getId()].isValid() &&
        rEvent[bdecay.raw.chanid[160].timelow.getId()].isValid() &&
	rEvent[bdecay.raw.chanid[160].timehigh.getId()].isValid() &&
	rEvent[bdecay.raw.chanid[191].timecfd.getId()].isValid() &&
	rEvent[bdecay.raw.chanid[191].timelow.getId()].isValid() &&
	rEvent[bdecay.raw.chanid[191].timehigh.getId()].isValid() ) { 

        
      p1time = (bdecay.raw.chanid[160].timelow + (bdecay.raw.chanid[160].timehigh*4294967296.))*10.;
      p2time = (bdecay.raw.chanid[191].timelow + (bdecay.raw.chanid[191].timehigh*4294967296.))*10.;
       bdecay.clock.dtCrate1Crate2 = p2time - p1time + 100;


    }
       if (rEvent[bdecay.raw.chanid[160].timecfd.getId()].isValid() &&
        rEvent[bdecay.raw.chanid[160].timelow.getId()].isValid() &&
	rEvent[bdecay.raw.chanid[160].timehigh.getId()].isValid() &&
	rEvent[bdecay.raw.chanid[285].timecfd.getId()].isValid() &&
	rEvent[bdecay.raw.chanid[285].timelow.getId()].isValid() &&
	rEvent[bdecay.raw.chanid[285].timehigh.getId()].isValid() ) { 

        
      p1time = (bdecay.raw.chanid[160].timelow + (bdecay.raw.chanid[160].timehigh*4294967296.))*10.;
      p2time = (bdecay.raw.chanid[285].timelow + (bdecay.raw.chanid[285].timehigh*4294967296.))*10.;
       bdecay.clock.dtCrate1Crate3 = p3time - p1time + 100;


    }

 /* Calculate the time difference between the SuN pmt and the  signal from the front of the DSSD max strip for decay events. */



 
 uint_64 pmttime = 0;
 uint_64 vetotime = 0;
 uint_64 lasttime;
 suntotal = 0;
 gmult = 0;
    
 xmatrix = 0;
 ymatrix = 0;
  
// cout << "after time diff calcs" << endl;


 for (i=0 ; i<24 ; i++) {
    
    if (rEvent[gdecay.sun.timecfd[i].getId()].isValid() &&
        rEvent[gdecay.sun.timelow[i].getId()].isValid() &&
	rEvent[gdecay.sun.timehigh[i].getId()].isValid() &&
	rEvent[gdecay.front.dmaxtimecfd.getId()].isValid() &&
	rEvent[gdecay.front.dmaxtimelow.getId()].isValid() &&
	rEvent[gdecay.front.dmaxtimehigh.getId()].isValid() ) {

     
      
      pmttime = 0;
      dssdtime = 0;
      deltat = 0;
      
      pmttime = ((gdecay.sun.timecfd[i]/32768.) + gdecay.sun.timelow[i]        // In ns
	+ (gdecay.sun.timehigh[i]*4294967296.)) *10.;
      dssdtime = ((gdecay.front.dmaxtimecfd/32768.) + gdecay.front.dmaxtimelow
	+ (gdecay.front.dmaxtimehigh*4294967296.)) *10.;
      
      if (dssdtime > pmttime - 25000) {
 	     deltat = dssdtime - pmttime + 25000; 
      }
      else {
	     deltat = 0;
      }
      gdecay.sun.dtdcf[i] = deltat;
  
    }

   

 /* Calculate the time difference between the SuN pmt and the signal from the front of the DSSD max strip for implant events. */


 
    if (rEvent[gdecay.sun.timecfd[i].getId()].isValid() &&
        rEvent[gdecay.sun.timelow[i].getId()].isValid() &&
	rEvent[gdecay.sun.timehigh[i].getId()].isValid() &&
	rEvent[gdecay.front.imaxtimecfd.getId()].isValid() &&
	rEvent[gdecay.front.imaxtimelow.getId()].isValid() &&
	rEvent[gdecay.front.imaxtimehigh.getId()].isValid() ) {

     
      
      pmttime = 0;
      dssdtime = 0;
      deltat = 0;
      
      pmttime = ((gdecay.sun.timecfd[i]/32768.) + gdecay.sun.timelow[i]        // In ns
	+ (gdecay.sun.timehigh[i]*4294967296.))*10.;
      dssdtime = ((gdecay.front.imaxtimecfd/32768.) + gdecay.front.imaxtimelow
	+ (gdecay.front.imaxtimehigh*4294967296.)) *10.;

      if (dssdtime > pmttime - 25000) {
 	     deltat = dssdtime - pmttime + 25000; 
      }
      else {
	     deltat = 0;
      }
     
      gdecay.sun.dtimf[i] = deltat;
    }

 /* Calculate the time difference between veto and the signal from the front of the DSSD max strip for decay events. */



    if (rEvent[gdecay.veto.timehigh.getId()].isValid() &&
        rEvent[gdecay.veto.timelow.getId()].isValid() &&
	    rEvent[gdecay.veto.timecfd.getId()].isValid() &&
        gammav.hit.fronthi == 1 && gammav.hit.backhi == 1) {        

        //rEvent[gdecay.front.dmaxtimecfd.getId()].isValid() &&
	    //rEvent[gdecay.front.dmaxtimelow.getId()].isValid() &&
	    //rEvent[gdecay.front.dmaxtimehigh.getId()].isValid() ) {
         
      
      vetotime = 0;
      dssdtime = 0;
      deltat = 0;
      
      vetotime = ((gdecay.veto.timecfd/32768.) + gdecay.veto.timelow        // In ns
	+ (gdecay.veto.timehigh*4294967296.)) *8.;
      dssdtime = ((gdecay.front.dmaxtimecfd/32768.) + gdecay.front.dmaxtimelow
	+ (gdecay.front.dmaxtimehigh*4294967296.)) *10.;
//      cout << "DSSD " << dssdtime << " " << "VETO " << vetotime << endl;
      if (dssdtime > vetotime - 25000) {
 	     deltat = dssdtime - vetotime + 25000; 
      }
      else {
	     deltat = 0;
      }
     
      gdecay.veto.dt_dcf = deltat;
    }


/* Calculate the time difference between the SuN pmt and NERO. */

    if (rEvent[gdecay.sun.timecfd[i].getId()].isValid() &&
        rEvent[gdecay.sun.timelow[i].getId()].isValid() &&
	rEvent[gdecay.sun.timehigh[i].getId()].isValid() &&
        neroANYtime != 0) {
      lasttime = pmttime;
      pmttime = 0;
      deltat = 0;
      
      pmttime = ((gdecay.sun.timecfd[i]/32768.) + gdecay.sun.timelow[i]        // In ns
	+ (gdecay.sun.timehigh[i]*4294967296.))*10.;
  
      //cout << "------------" << endl;
      //cout << "neroANYtime = " << neroANYtime << endl;     
      //cout << "pmttime = " << pmttime << endl;
      //if (neroANYtime > pmttime - 30000) {
 	     deltat = neroANYtime - pmttime + 25000; 
      //}
      //else {
	//     deltat = 20500;
      //}
            //if (deltat < 0) {
      //cout << "deltat = " << deltat << endl; 
      //} 
      gdecay.sun.dtNERO[i] = deltat;

    }
  

/* Calculate the time difference between the SuN pmt and the signal from the front of BCS DSSD max strip for decay events. */



  
    if (rEvent[gdecay.sun.timecfd[i].getId()].isValid() &&
        rEvent[gdecay.sun.timelow[i].getId()].isValid() &&
	rEvent[gdecay.sun.timehigh[i].getId()].isValid() &&
	rEvent[bdecay.front.dmaxtimecfd.getId()].isValid() &&
	rEvent[bdecay.front.dmaxtimelow.getId()].isValid() &&
	rEvent[bdecay.front.dmaxtimehigh.getId()].isValid() ) {

      
      
      pmttime = 0;
      dssdtime = 0;
      deltat = 0;
      
      pmttime = ((gdecay.sun.timecfd[i]/32768.) + gdecay.sun.timelow[i]        // In ns
	+ (gdecay.sun.timehigh[i]*4294967296.)) *10.;
      dssdtime = ((bdecay.front.dmaxtimecfd/32768.) + bdecay.front.dmaxtimelow
	+ (bdecay.front.dmaxtimehigh*4294967296.))*10.;
      
      deltat = dssdtime - pmttime + 25000; 
      gdecay.sun.dtdBCS[i] = deltat;
  
    }

     /* Calculate the time difference between the SuN pmt and the signal from the front of BCS DSSD max strip for implant events. */


    if (rEvent[gdecay.sun.timecfd[i].getId()].isValid() &&
        rEvent[gdecay.sun.timelow[i].getId()].isValid() &&
	rEvent[gdecay.sun.timehigh[i].getId()].isValid() &&
	rEvent[bdecay.front.imaxtimecfd.getId()].isValid() &&
	rEvent[bdecay.front.imaxtimelow.getId()].isValid() &&
	rEvent[bdecay.front.imaxtimehigh.getId()].isValid() ) {

     
      
      pmttime = 0;
      dssdtime = 0;
      deltat = 0;
      
      pmttime = ((gdecay.sun.timecfd[i]/32768.) + gdecay.sun.timelow[i]        // In ns
	+ (gdecay.sun.timehigh[i]*4294967296.))*10.;
      dssdtime = ((bdecay.front.imaxtimecfd/32768.) + bdecay.front.imaxtimelow
	+ (bdecay.front.imaxtimehigh*4294967296.)) *10.;

      deltat = dssdtime - pmttime + 25000; 
     
      gdecay.sun.dtiBCS[i] = deltat;
    }
 }
// cout << "after second to last for loop" << endl;
   
            for (i=0 ; i< 8; i++) {
              
            if ( rEvent[gdecay.sun.cseg[i].getId()].isValid() ) 
            {
             if (gdecay.sun.cseg[i] > gammav.SuN.thresh[i]) {
           
	      gammav.hit.sun = 1;
              gmult++;
              gdecay.suntotal.mult = gmult;
              suntotal += UInt_t(gdecay.sun.cseg[i]);
              gdecay.suntotal.total = suntotal;
              if ( rEvent[gdecay.suntotal.total.getId()].isValid() ) {
                gdecay.suntotal.total_cal =  gammav.SuN.tot_square * gdecay.suntotal.total * gdecay.suntotal.total + gammav.SuN.tot_slope * gdecay.suntotal.total + gammav.SuN.tot_intercept;
              } 
             }
            }
         }
 
   
//  cout << "End of Threshold" << endl;
 
  /* End of event */

  return kfTRUE; /* kfFALSE would abort pipeline */
};




























