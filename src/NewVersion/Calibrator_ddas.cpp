/*****************************************************************/
/* Calibrator.cpp for DSSD Beta Decay - Digital Data Acquisition */
/* Based on standard BCS SpecTcl codes                           */
/* Scott Suchyta/Sean Liddick, June 2010                      */
/*****************************************************************/

#include <config.h>
#include <EventProcessor.h>
#include <TCLAnalyzer.h>
#include <Event.h> 
#include <math.h> 
#include <iomanip>
#include "Parameters-ddas.h"
#include "Variables-ddas.h"

#include "Calibrator_ddas.h"

#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/* New includes for SpecTcl gate access */
#include <Globals.h>
#include <Histogrammer.h>
#include <GateContainer.h>
#include <Contour.h>

/*****************************************************************/
/* Channel list for e19043 - BCS/NERO/SuN with DDAS              */
/* Three-crate system                                            */
/* Master (crate id 1): BCS DSSD + SSSD  (Wiener crate)          */
/* Slave 1 (crate id 2): NERO            (Elma crate)            */
/* Slave 2 (crate id 3): SuN, SuNDSSD, TACs, PINs + veto (Wiener)*/
/* Crate 1 mod 00 / slot 02 - BCSDSSD FH01-16             000-015*/
/* Crate 1 mod 01 / slot 03 - BCSDSSD FH17-32             016-031*/
/* Crate 1 mod 02 / slot 04 - BCSDSSD FH33-40 FL40-33     032-047*/
/* Crate 1 mod 03 / slot 05 - BCSDSSD FL32-17             048-063*/
/* Crate 1 mod 04 / slot 06 - BCSDSSD FL16-01             064-079*/
/* Crate 1 mod 05 / slot 07 - BCSDSSD BH01-16             080-095*/
/* Crate 1 mod 06 / slot 08 - BCSDSSD BH17-32             096-111*/
/* Crate 1 mod 07 / slot 09 - BCSDSSD BH33-40 BL40-33     112-127*/
/* Crate 1 mod 08 / slot 10 - BCSDSSD BL32-17             128-143*/
/* Crate 1 mod 09 / slot 11 - BCSDSSD BL16-01             144-159*/
/* Crate 1 mod 10 / slot 12 - BCSSSSD 01-16               160-175*/
/* Crate 2 mod 00 / slot 02 - NERO Quad A                 176-191*/
/* Crate 2 mod 01 / slot 03 - NERO Quad B                 192-207*/
/* Crate 2 mod 02 / slot 04 - NERO Quad C                 208-223*/
/* Crate 2 mod 03 / slot 05 - NERO Quad D                 224-239*/
/* Crate 3 mod 00 / slot 02 - SuN Upper Half              240-255*/
/* Crate 3 mod 01 / slot 03 - SuN Lower Half              256-271*/
/* Crate 3 mod 02 / slot 04 - TACs, PINs, Veto            272-287*/
/* Crate 3 mod 03 / slot 05 - SuNDSSD FH                  288-303*/
/* Crate 3 mod 04 / slot 06 - SuNDSSD BH                  304-319*/
/* Crate 3 mod 05 / slot 07 - SuNDSSD FL                  320-335*/
/* Crate 3 mod 06 / slot 08 - SuNDSSD BL                  336-351*/
/*****************************************************************/

#ifdef HAVE_STD_NAMESPACE
using namespace std;
#endif
typedef unsigned long long uint_64;

Bool_t
CBDecayCalibrator::operator()(const Address_t pEvent,
				CEvent&         rEvent,
				CAnalyzer&      rAnalyzer,
				CBufferDecoder& rDecoder)
{
//  cout << "BEGIN CALIBRATOR" << endl;

  int i,j,k,kk,l,m,n,p,q, npmt;
  float clock23bit=0.0;
  static int clockover;
  static unsigned int tempclock;
  float fenergy,fecal;

  if (bdecayv.corr.reset !=0) {
    clockover = 0;
    srand(time(NULL));
  }

  /***** Clock ***************************************************/
  if ( rEvent[bdecay.clock.fast.getId()].isValid() && 
       rEvent[bdecay.clock.slow.getId()].isValid()  ) {
 
     /* Filling the clock parameters in gamma(SuN) class */
    
     gdecay.clock.fast = bdecay.clock.fast;
    
     gdecay.clock.slow = bdecay.clock.slow;

    /* Use fast clock word as 32-bit clock time for DDAS 100MHz clock */
    //bdecay.clock.initial = bdecay.clock.fast;
    
    /* Scale down clock to 23 bits for 100 MHz operation */
    //clock23bit = bdecay.clock.initial/512.0;
    
    /* Check to see how many times fast 32-bit clock has turned over -
       this is given by the value of bdecay.clock.slow essentially */
    //clockover = bdecay.clock.slow;
        
    /*  The next line is for 100 MHz clock operation */
    // bdecay.clock.current = (long)(clock23bit+clockover*65536*128);


    //uint_64 temptime = bdecay.clock.fast*10. + 4294967296.*bdecay.clock.slow*10.; //time in nanoseconds!!!!!
    
    //bdecay.clock.current = (long)(floor)(temptime/1000000.);
    
    //gdecay.clock.current = (long)(floor)(temptime/1000000.); 
    gdecay.clock.current = bdecay.clock.current;
  }
     
  /***** Assign specific ADC/TDC channels (ADC/TDC18) **********/

  //loop over the channels that have data and assign them to useful parameters
  //cout << "new event, size " << bdecay.raw.chanidhit.size() << endl;

  //cout << "New EventBuffer" << endl;
  for(int i= 0; i<bdecay.raw.chanidhit.size(); i++){

//    cout << bdecay.raw.chanidhit.size() << endl;

    int id = bdecay.raw.chanidhit[i];

    if (i==0) {
    	double time_ini = bdecay.raw.chanid[id].time;
    }

    //double ran = (double)( rand() / RAND_MAX);
    double ran = ( static_cast<double>(rand())) / (static_cast<double>(RAND_MAX));
    //cout << "      id in event " << id << " e " << bdecay.raw.chanid[id].adc << endl;

    //cout << "  Time diff " << setprecision(20) << bdecay.raw.chanid[id].time - bdecay.raw.chanid[bdecay.raw.chanidhit[0]].time << endl;
    
//    cout << "  Starting BCS Calib " << endl;

    /************************ BCS ***********************/
    /************************ BCS ***********************/
    /************************ BCS ***********************/
    
    //BCS DSSD front hi gain, channels 0 - 39
    if( (id>=0) && (id < 40)){
      int strip;
      strip = id + 1;
//      cout << "front "<< strip << "\t" << id << endl;

      bdecay.front.hienergy[strip]   = (bdecay.raw.chanid[id].adc + ran) + 0.0;
      bdecay.front.hiecal[strip]     = (bdecayv.front.hislope[strip]*bdecay.front.hienergy[strip]) + 
								     bdecayv.front.hioffset[strip];
      bdecay.front.hitimecfd[strip]  = bdecay.raw.chanid[id].timecfd + 0.0;
      bdecay.front.hitimelow[strip]  = bdecay.raw.chanid[id].timelow + 0.0;
      bdecay.front.hitimehigh[strip] = bdecay.raw.chanid[id].timehigh + 0.0;

    }

    //BCS DSSD front lo gain, channels 40 - 79
    if( (id >= 40) && (id < 80) ){
      int strip;
      strip = 80-id;

      bdecay.front.loenergy[strip]     = (bdecay.raw.chanid[id].adc + ran) + 0.0;
      bdecay.front.loecal[strip]       = (bdecayv.front.loslope[strip]*bdecay.front.loenergy[strip]);
      bdecay.front.lotimecfd[strip]    = bdecay.raw.chanid[id].timecfd + 0.0;
      bdecay.front.lotimelow[strip]    = bdecay.raw.chanid[id].timelow + 0.0;
      bdecay.front.lotimehigh[strip]   = bdecay.raw.chanid[id].timehigh + 0.0;
     }

    //BCS DSSD back hi gain, channels 80 - 119
    if( ((id >= 80) && (id < 120)) ){ //|| id == 208 ){
      int strip;
      strip = (id - 80) + 1;
     
      bdecay.back.hienergy[strip]   = (bdecay.raw.chanid[id].adc + ran) + 0.0;
      bdecay.back.hiecal[strip]     = bdecayv.back.hislope[strip]*bdecay.back.hienergy[strip]+bdecayv.front.hioffset[strip];
      bdecay.back.hitimecfd[strip]  = bdecay.raw.chanid[id].timecfd + 0.0;
      bdecay.back.hitimelow[strip]  = bdecay.raw.chanid[id].timelow + 0.0;
      bdecay.back.hitimehigh[strip] = bdecay.raw.chanid[id].timehigh + 0.0;     
    }

    //BCS DSSD back lo gain, channels 120 - 159

    if( (id >= 120) && (id < 160)){
      int strip;
      strip = 160 - id; 

      bdecay.back.loenergy[strip]   = (bdecay.raw.chanid[id].adc + ran) + 0.0;
      bdecay.back.loecal[strip]     = bdecayv.back.loslope[strip]*bdecay.back.loenergy[strip];
      bdecay.back.lotimecfd[strip]  = bdecay.raw.chanid[id].timecfd + 0.0;
      bdecay.back.lotimelow[strip]  = bdecay.raw.chanid[id].timelow + 0.0;
      bdecay.back.lotimehigh[strip] = bdecay.raw.chanid[id].timehigh + 0.0;  
    }

    //BCS SSSD channel 1-16, channels 160 - 175
    
    if( (id >= 160) && (id < 176) ) {
      int strip = (id - 160) + 1;
      bdecay.sssd01.energy[strip]   = (bdecay.raw.chanid[id].adc + ran) + 0.0;
      bdecay.sssd01.ecal[strip]     = bdecayv.sssd01.slope[strip]*bdecay.sssd01.energy[strip];
      bdecay.sssd01.time[strip]  = bdecay.raw.chanid[id].time + 0.0;
    }

    
 /*KEEP FOR NOW OR FERNANDO WILL FROWN MORE
        
    // PIN01 - RF TAC
    if( id == 196) {
      bdecay.tac.pin01rf = bdecay.raw.chanid[id].adc + 0.0;
    }

    // Pin01 - XFP TAC
    if(id == 197) {
      bdecay.tac.pin01xfp = bdecay.raw.chanid[id].adc + 0.0;
    }

    // Pin02 - XFP TAC
    if(id == 198) {
      bdecay.tac.pin02xfp = bdecay.raw.chanid[id].adc + 0.0;
    }
    
    // I2N - I2S TAC
    if(id == 199) {
      bdecay.tac.i2pos = bdecay.raw.chanid[id].adc + 0.0;
    }

    // I2N - PIN01 TAC
    if(id == 200) {
      bdecay.tac.i2ntof = bdecay.raw.chanid[id].adc + 0.0;
    }

    // I2S - PIN01 TAC
    if(id == 201) {
      bdecay.tac.i2stof = bdecay.raw.chanid[id].adc + 0.0;
    }
     
    // Veto scintillator
    if(id == 202) {
      bdecay.scint.energy = (bdecay.raw.chanid[id].adc + ran) + 0.0;
      bdecay.scint.ecal = (bdecayv.scint.slope*bdecay.scint.energy + 
			   bdecayv.scint.intercept);
      bdecay.scint.time = bdecay.raw.chanid[id].time + 0.0;
    }
   */
//    cout << "  Starting NERO Calib" << endl;

    /************************ NERO ***********************/
    /************************ NERO ***********************/
    /************************ NERO ***********************/
    //NERO chans are 176-239
    if( (id >= 176) && (id < 192) ) {
      int chan = (id - 176) + 1;
      nero.energy[chan] = (bdecay.raw.chanid[id].adc + ran);
      nero.ecal[chan] = nero.energy[chan];
//      nero.timecfd[chan] = bdecay.raw.chanid[id].timecfd + 0.0;
//      cout << "after cfd" << endl;
//      nero.timelow[chan] = bdecay.raw.chanid[id].timelow + 0.0;
//      nero.timehigh[chan] = bdecay.raw.chanid[id].timehigh + 0.0;
      //cout << "channel = " << chan << " energy = " << nero.energy[chan] << endl;
    }
    if( (id >= 192) && (id < 207) ) {
      int chan = (id - 192) + 16;
      nero.energy[chan] = (bdecay.raw.chanid[id].adc + ran);
      nero.ecal[chan] = nero.energy[chan];
//      nero.timecfd[chan] = bdecay.raw.chanid[id].timecfd + 0.0;
//      nero.timelow[chan] = bdecay.raw.chanid[id].timelow + 0.0;
//      cout << "after lo" << endl;
//      nero.timehigh[chan] = bdecay.raw.chanid[id].timehigh + 0.0;
      //cout << "channel = " << chan << " energy = " << nero.energy[chan] << endl;
    }
    if( (id >= 208) && (id < 223) ) {
      int chan = (id - 208) + 31;
      nero.energy[chan] = (bdecay.raw.chanid[id].adc + ran);
      nero.ecal[chan] = nero.energy[chan];
//    nero.timecfd[chan] = bdecay.raw.chanid[id].timecfd + 0.0;
//    nero.timelow[chan] = bdecay.raw.chanid[id].timelow + 0.0;
//    nero.timehigh[chan] = bdecay.raw.chanid[id].timehigh + 0.0;
   
      //cout << "channel = " << chan << " energy = " << nero.energy[chan] << endl;
    }
    if( (id >= 224) && (id < 239) ) {
      int chan = (id - 224) + 46;
      nero.energy[chan] = (bdecay.raw.chanid[id].adc + ran);
      nero.ecal[chan] = nero.energy[chan];
//      nero.timecfd[chan] = bdecay.raw.chanid[id].timecfd + 0.0;
//      nero.timelow[chan] = bdecay.raw.chanid[id].timelow + 0.0;
//      nero.timehigh[chan] = bdecay.raw.chanid[id].timehigh + 0.0;
      //cout << "channel = " << chan << " energy = " << nero.energy[chan] << endl;
    }

//    cout << "  Starting SuN Calib" << endl;    

    /************************ SuN ***********************/
    /************************ SuN ***********************/
    /************************ SuN ***********************/
    
    // SuN , channels from 240-251 and 256-267 
    
    if( ((id >= 240) && (id < 252)) || ((id >= 256) && (id < 268)) ) { 

      if( (id >= 240) && (id < 252) ) {
          npmt = 12 + (id-252);
      }

      else {
         npmt = id-244;
      }
      //     cout<<"ID:"<<id<<"npmt:"<<npmt<<endl;

      if ( rEvent[bdecay.raw.chanid[id].adc.getId()].isValid() ) {
	gdecay.sun.rpmt[npmt] = (bdecay.raw.chanid[id].adc + ran);
        gdecay.sun.tpmt[npmt] = bdecay.raw.chanid[id].time + 0.0;    // In clock ticks
      }

      if ( rEvent[bdecay.raw.chanid[id].timecfd.getId()].isValid() ) {
        gdecay.sun.timecfd[npmt] = bdecay.raw.chanid[id].timecfd + 0.0;
      }

      if ( rEvent[bdecay.raw.chanid[id].timelow.getId()].isValid() ) {
        gdecay.sun.timelow[npmt] = bdecay.raw.chanid[id].timelow + 0.0;
      }

      if ( rEvent[bdecay.raw.chanid[id].timelow.getId()].isValid() ) {
        gdecay.sun.timehigh[npmt] =bdecay.raw.chanid[id].timehigh+ 0.0;
      }

      if( (rEvent[bdecay.raw.chanid[id].timehigh.getId()].isValid()) && (rEvent[bdecay.raw.chanid[id].timelow.getId()].isValid()) ){

       uint_64 suntemptime = (gdecay.sun.timehigh[npmt]*4294967296. + gdecay.sun.timelow[npmt])*10.;
       gdecay.sun.timeinseconds[npmt] = (long)(floor)(suntemptime/1000000000.); // time in seconds
      }


      if ( rEvent[gdecay.sun.rpmt[npmt].getId()].isValid() && gdecay.sun.rpmt[npmt] <28000) { 
  //      cout<< " Value: "<<gdecay.sun.rpmt[npmt]<< endl; 
	gdecay.sun.gmpmt[npmt] =gammav.SuN.pslope[npmt] * gdecay.sun.rpmt[npmt] + gammav.SuN.pintercept[npmt];
      }

    }       
    
    /************************ TACs ***********************/
    /************************ TACs ***********************/
    /************************ TACs ***********************/
    // 272-287 
    //I2N-I2S   
    //TAC ORDER NOT DECIDED YET, COMMENT OUT FOR NOW
    /*
    if(id == 275) {
      bdecay.tac.i2pos = bdecay.raw.chanid[id].adc + 0.0;
    } 
    */

    // Pin01 - RF TAC
    if(id == 277) {
      bdecay.tac.pin01rf = bdecay.raw.chanid[id].adc + 0.0;
    }
      
    // Pin01 - XFP TAC   
    if(id == 275) {            
      bdecay.tac.pin01xfp = bdecay.raw.chanid[id].adc + 0.0;
      bdecay.pid.pin01xfptof = bdecay.tac.pin01xfp;

     if ( rEvent[bdecay.raw.chanid[id].timecfd.getId()].isValid() ) {
       bdecay.tac.pin01xfptimecfd = bdecay.raw.chanid[id].timecfd + 0.0;
     }
       
     if ( rEvent[bdecay.raw.chanid[id].timelow.getId()].isValid() ) {
       bdecay.tac.pin01xfptimelow = bdecay.raw.chanid[id].timelow + 0.0;
     }

     if ( rEvent[bdecay.raw.chanid[id].timehigh.getId()].isValid() ) {
       bdecay.tac.pin01xfptimehigh =bdecay.raw.chanid[id].timehigh + 0.0;
     }
    }

    // Pin02 - XFP TAC
    if(id == 276) {            
      bdecay.tac.pin02xfp = bdecay.raw.chanid[id].adc + 0.0;
     
     if ( rEvent[bdecay.raw.chanid[id].timecfd.getId()].isValid() ) {
       bdecay.tac.pin02xfptimecfd = bdecay.raw.chanid[id].timecfd + 0.0;
     }

     if ( rEvent[bdecay.raw.chanid[id].timelow.getId()].isValid() ) {
       bdecay.tac.pin02xfptimelow = bdecay.raw.chanid[id].timelow + 0.0;
     }

     if ( rEvent[bdecay.raw.chanid[id].timehigh.getId()].isValid() ) {
       bdecay.tac.pin02xfptimehigh =bdecay.raw.chanid[id].timehigh + 0.0;
     }
    }
    //THe following are unused but leave them in so old evt files still work
    // Pin01 - I2S TAC 
    if( id == 277 ) {
      bdecay.tac.pin01I2S = bdecay.raw.chanid[id].adc + 0.0;
    }
    
    // Pin01 - I2N TAC  
    if( id == 276 ) {
      bdecay.tac.pin01I2N = bdecay.raw.chanid[id].adc + 0.0;
     if ( rEvent[bdecay.raw.chanid[id].timecfd.getId()].isValid() ) {
       bdecay.tac.i2ntoftimecfd = bdecay.raw.chanid[id].timecfd + 0.0;
     }

     if ( rEvent[bdecay.raw.chanid[id].timelow.getId()].isValid() ) {
       bdecay.tac.i2ntoftimelow = bdecay.raw.chanid[id].timelow + 0.0;
     }

     if ( rEvent[bdecay.raw.chanid[id].timehigh.getId()].isValid() ) {
       bdecay.tac.i2ntoftimehigh =bdecay.raw.chanid[id].timehigh + 0.0;
     }

    } 
    
    // Pin02 - I2S TAC 
    if( id == 279 ) {
      bdecay.tac.pin02I2S = bdecay.raw.chanid[id].adc + 0.0;
    }
    
    // Pin01 - I2N TAC  
    if( id == 278 ) {
      bdecay.tac.pin02I2N = bdecay.raw.chanid[id].adc + 0.0;
    }  

   //cout << "  Starting SuN DSSD Calib" << endl;    

    //SuN DSSD front high gain, channels 288 - 303 
    if( (id>=288) && (id < 304) ){
      
      //cout << "  SuN DSSD 0" << endl; 
      
      int strip =  (id - 288) ;
      //if ( rEvent[bdecay.raw.chanid[id].adc.getId()].isValid() ) {
	      gdecay.front.hienergy[strip]   = (bdecay.raw.chanid[id].adc + ran) + 0.0;
     // }
      //cout << "  SuN DSSD 1" << endl;
      
     if ( rEvent[gdecay.front.hienergy[strip].getId()].isValid() ) {
       gdecay.front.hiecal[strip]     = gammav.front.hislope[strip]*(gdecay.front.hienergy[strip]) + gammav.front.hioffset[strip];
     }
	//cout << "Set ecal" << endl;
     if ( rEvent[bdecay.raw.chanid[id].timecfd.getId()].isValid() ) {
       gdecay.front.hitimecfd[strip]  = bdecay.raw.chanid[id].timecfd + 0.0;
     }
	//cout << "set cfd time" << endl;
     if ( rEvent[bdecay.raw.chanid[id].timelow.getId()].isValid() ) {
       gdecay.front.hitimelow[strip]  = bdecay.raw.chanid[id].timelow + 0.0;
     }
	//cout << "set low time" << endl;
     if ( rEvent[bdecay.raw.chanid[id].timehigh.getId()].isValid() ) {
       gdecay.front.hitimehigh[strip] = bdecay.raw.chanid[id].timehigh + 0.0;
     }
	//cout << "set high time" << endl;
     //cout << "  SuN DSSD 2" << endl;       

     if( (rEvent[bdecay.raw.chanid[id].timehigh.getId()].isValid()) && (rEvent[bdecay.raw.chanid[id].timelow.getId()].isValid()) ){
       uint_64 fronthitime = (gdecay.front.hitimehigh[strip]*4294967296. + gdecay.front.hitimelow[strip])*10.;
       //gdecay.front.hitimeinseconds[strip] = (long)(floor)(fronthitime/1000000000.);
     }
	//cout << "set front hittime" << endl;
    }

    //cout << "  Starting SuN DSSD back hi Calib" << endl;    

    //SuN DSSD back high gain, channels 304 - 319 
    if( (id >= 304) && (id < 320)){
      //cout << "  SuN DSSD 0" << endl; 

      int strip = (id - 304) ;
	//cout << "BH ID: " << id << " and strip: " << strip << endl;
      if ( rEvent[bdecay.raw.chanid[id].adc.getId()].isValid() ) {
         gdecay.back.hienergy[strip]     = (bdecay.raw.chanid[id].adc + ran) + 0.0;
      }
    // cout << "  SuN DSSD 1" << endl; 

     if ( rEvent[gdecay.back.hienergy[strip].getId()].isValid() ) {
	gdecay.back.hiecal[strip]       = gammav.back.hislope[strip]*(gdecay.back.hienergy[strip] + gammav.back.hioffset[strip]);
     }
     if ( rEvent[bdecay.raw.chanid[id].timecfd.getId()].isValid() ) {
	gdecay.back.hitimecfd[strip]    = bdecay.raw.chanid[id].timecfd + 0.0;
     }
      
     if ( rEvent[bdecay.raw.chanid[id].timelow.getId()].isValid() ) {
        gdecay.back.hitimelow[strip]    = bdecay.raw.chanid[id].timelow + 0.0;
     }
      
     if ( rEvent[bdecay.raw.chanid[id].timehigh.getId()].isValid() ) {
        gdecay.back.hitimehigh[strip]   = bdecay.raw.chanid[id].timehigh + 0.0;
     }
     
     //cout << "  SuN DSSD 2" << endl; 

     if( (rEvent[bdecay.raw.chanid[id].timehigh.getId()].isValid()) && (rEvent[bdecay.raw.chanid[id].timelow.getId()].isValid()) ) {
	uint_64 backhitime = (gdecay.back.hitimehigh[strip]*4294967296.+ gdecay.back.hitimelow[strip])*10.;
      	//gdecay.back.hitimeinseconds[strip] = (long)(floor)(backhitime/1000000000.);
     }
    }

   //cout << "  Starting SuN DSSD front lo Calib" << endl;

    //SuN DSSD front low gain, channels 320-335
    if( (id >= 320) && (id < 336) ){
      int strip = (id - 320) ;

     if ( rEvent[bdecay.raw.chanid[id].adc.getId()].isValid() ) {
          gdecay.front.loenergy[strip]   = (bdecay.raw.chanid[id].adc + ran) + 0.0;
     }   

     if ( rEvent[gdecay.front.loenergy[strip].getId()].isValid() ) {
	gdecay.front.loecal[strip]     = gammav.front.loslope[strip]*gdecay.front.loenergy[strip];
     }

     if ( rEvent[bdecay.raw.chanid[id].timecfd.getId()].isValid() ) {
        gdecay.front.lotimecfd[strip]  = bdecay.raw.chanid[id].timecfd + 0.0;
     }
      
     if ( rEvent[bdecay.raw.chanid[id].timelow.getId()].isValid() ) { 
        gdecay.front.lotimelow[strip]  = bdecay.raw.chanid[id].timelow + 0.0;
     }

     if ( rEvent[bdecay.raw.chanid[id].timehigh.getId()].isValid() ) {
        gdecay.front.lotimehigh[strip] = bdecay.raw.chanid[id].timehigh + 0.0; 
     }
     
     if( (rEvent[bdecay.raw.chanid[id].timehigh.getId()].isValid()) && (rEvent[bdecay.raw.chanid[id].timelow.getId()].isValid()) ){
	uint_64 frontlotime = (gdecay.front.lotimehigh[strip]*4294967296. + gdecay.front.lotimelow[strip])*10.;
      	//gdecay.front.lotimeinseconds[strip] = (long)(floor)(frontlotime/1000000000.);
     }
    }

    //DSSD back lo gain, channels 368 - 383
    if( (id >= 336) && (id < 352)){ 
      int strip = (id - 336) ; 

     if ( rEvent[bdecay.raw.chanid[id].adc.getId()].isValid() ) {
         gdecay.back.loenergy[strip]   = (bdecay.raw.chanid[id].adc + ran) + 0.0;
     }   
  
     if ( rEvent[gdecay.back.loenergy[strip].getId()].isValid() ) {
      gdecay.back.loecal[strip]     = gammav.back.loslope[strip]*gdecay.back.loenergy[strip];
     }
     
     if ( rEvent[bdecay.raw.chanid[id].timecfd.getId()].isValid() ) {
      gdecay.back.lotimecfd[strip]  = bdecay.raw.chanid[id].timecfd + 0.0;
     }
      
     if ( rEvent[bdecay.raw.chanid[id].timelow.getId()].isValid() ) {
      gdecay.back.lotimelow[strip]    = bdecay.raw.chanid[id].timelow + 0.0;
     }
      
     if ( rEvent[bdecay.raw.chanid[id].timehigh.getId()].isValid() ) {
      gdecay.back.lotimehigh[strip]   = bdecay.raw.chanid[id].timehigh + 0.0;
     }
      
     if( (rEvent[bdecay.raw.chanid[id].timehigh.getId()].isValid()) && (rEvent[bdecay.raw.chanid[id].timelow.getId()].isValid()) ){
 	uint_64 backlotime = (gdecay.back.lotimehigh[strip]*4294967296. + gdecay.back.lotimelow[strip])*10.;
     	//gdecay.back.lotimeinseconds[strip] = (long)(floor)(backlotime/1000000000.);
     }
    }  

    //cout << "  Starting PINs Calib" << endl;  
    //PINS NOT DECIDED YET, COMMENT OUT
    //PIN01, channel 272
    if( id == 272 ) {
      bdecay.pin01.energy = (bdecay.raw.chanid[id].adc + ran) + 0.0;
      bdecay.pin01.ecal = (bdecayv.pin01.slope*bdecay.pin01.energy) + 
			   bdecayv.pin01.intercept;
      //bdecay.pid.de1 = bdecay.pin01.ecal;
      bdecay.pin01.time = bdecay.raw.chanid[id].time + 0.0;
      
     if ( rEvent[bdecay.raw.chanid[id].timecfd.getId()].isValid() ) {
      bdecay.pin01.timecfd = bdecay.raw.chanid[id].timecfd + 0.0;
     }
  
     if ( rEvent[bdecay.raw.chanid[id].timelow.getId()].isValid() ) {
      bdecay.pin01.timelow = bdecay.raw.chanid[id].timelow + 0.0;
     }

     if ( rEvent[bdecay.raw.chanid[id].timehigh.getId()].isValid() ) {
      bdecay.pin01.timehigh =bdecay.raw.chanid[id].timehigh+ 0.0;
     }
    }

    //PIN02, channel 273
    if( id == 273 ) {
      bdecay.pin02.energy = (bdecay.raw.chanid[id].adc + ran) + 0.0;
      bdecay.pin02.ecal = (bdecayv.pin02.slope*bdecay.pin02.energy) + 
			   bdecayv.pin02.intercept;
      bdecay.pid.de2 = bdecay.pin02.ecal;
      bdecay.pin02.time = bdecay.raw.chanid[id].time + 0.0;
    if ( rEvent[bdecay.raw.chanid[id].timecfd.getId()].isValid() ) {
      bdecay.pin02.timecfd = bdecay.raw.chanid[id].timecfd + 0.0;
     }
  
     if ( rEvent[bdecay.raw.chanid[id].timelow.getId()].isValid() ) {
      bdecay.pin02.timelow = bdecay.raw.chanid[id].timelow + 0.0;
     }

     if ( rEvent[bdecay.raw.chanid[id].timehigh.getId()].isValid() ) {
      bdecay.pin02.timehigh =bdecay.raw.chanid[id].timehigh+ 0.0;
     }
    }
   
    //PIN03, channel 286
    if( id == 286 ) {
      bdecay.pin03.energy = (bdecay.raw.chanid[id].adc + ran) + 0.0;
      bdecay.pin03.ecal = (bdecayv.pin03.slope*bdecay.pin03.energy) + 
			   bdecayv.pin03.intercept;
      bdecay.pid.de3 = bdecay.pin03.ecal;
      bdecay.pin03.time = bdecay.raw.chanid[id].time + 0.0;
    if ( rEvent[bdecay.raw.chanid[id].timecfd.getId()].isValid() ) {
      bdecay.pin03.timecfd = bdecay.raw.chanid[id].timecfd + 0.0;
     }
  
     if ( rEvent[bdecay.raw.chanid[id].timelow.getId()].isValid() ) {
      bdecay.pin03.timelow = bdecay.raw.chanid[id].timelow + 0.0;
     }

     if ( rEvent[bdecay.raw.chanid[id].timehigh.getId()].isValid() ) {
      bdecay.pin03.timehigh =bdecay.raw.chanid[id].timehigh+ 0.0;
     }
    }
    
    //SuN Veto, channel 274 
    if(id == 274) {
      gdecay.veto.energy = bdecay.raw.chanid[id].adc + 0.0;
    
     if ( rEvent[bdecay.raw.chanid[id].timecfd.getId()].isValid() ) {
      gdecay.veto.timecfd = bdecay.raw.chanid[id].timecfd + 0.0;
     }
       
     if ( rEvent[bdecay.raw.chanid[id].timelow.getId()].isValid() ) {
      gdecay.veto.timelow = bdecay.raw.chanid[id].timelow + 0.0;
     }

     if ( rEvent[bdecay.raw.chanid[id].timehigh.getId()].isValid() ) {
      gdecay.veto.timehigh =bdecay.raw.chanid[id].timehigh+ 0.0;
     }
    } 
    
    
   //Scintillator, channel 287
   if( id == 287 ) {
      bdecay.scint.energy = (bdecay.raw.chanid[id].adc + ran) + 0.0;
      bdecay.scint.ecal = (bdecayv.scint.slope*bdecay.scint.energy) + 
			   bdecayv.scint.intercept;
      bdecay.scint.time = bdecay.raw.chanid[id].time + 0.0;
   }
   
   //Pulser timing checks
   
    
  } // end loop over size of event

    //Calibrate SuN
     if(rEvent[gdecay.sun.gmpmt[0].getId()].isValid() && rEvent[gdecay.sun.gmpmt[1].getId()].isValid() && rEvent[gdecay.sun.gmpmt[2].getId()].isValid() ) { 
      gdecay.sun.rseg[0] = gdecay.sun.gmpmt[0]+ gdecay.sun.gmpmt[1] + gdecay.sun.gmpmt[2];
     }

     if(rEvent[gdecay.sun.gmpmt[3].getId()].isValid() && rEvent[gdecay.sun.gmpmt[4].getId()].isValid() && rEvent[gdecay.sun.gmpmt[5].getId()].isValid()) { 
      gdecay.sun.rseg[1] = gdecay.sun.gmpmt[3] + gdecay.sun.gmpmt[4] + gdecay.sun.gmpmt[5] ;
     }
     
     if(rEvent[gdecay.sun.gmpmt[6].getId()].isValid() && rEvent[gdecay.sun.gmpmt[7].getId()].isValid() && rEvent[gdecay.sun.gmpmt[8].getId()].isValid()) { 
      gdecay.sun.rseg[2] = gdecay.sun.gmpmt[6] + gdecay.sun.gmpmt[7] + gdecay.sun.gmpmt[8] ;
     }

     if(rEvent[gdecay.sun.gmpmt[9].getId()].isValid() && rEvent[gdecay.sun.gmpmt[10].getId()].isValid() && rEvent[gdecay.sun.gmpmt[11].getId()].isValid()) { 
      gdecay.sun.rseg[3] = gdecay.sun.gmpmt[9] + gdecay.sun.gmpmt[10] + gdecay.sun.gmpmt[11] ;
     }
     
     if(rEvent[gdecay.sun.gmpmt[12].getId()].isValid() && rEvent[gdecay.sun.gmpmt[13].getId()].isValid() && rEvent[gdecay.sun.gmpmt[14].getId()].isValid()) { 
      gdecay.sun.rseg[4] = gdecay.sun.gmpmt[12] + gdecay.sun.gmpmt[13] + gdecay.sun.gmpmt[14] ;
     }
      
     if(rEvent[gdecay.sun.gmpmt[15].getId()].isValid() && rEvent[gdecay.sun.gmpmt[16].getId()].isValid() && rEvent[gdecay.sun.gmpmt[17].getId()].isValid()) { 
      gdecay.sun.rseg[5] = gdecay.sun.gmpmt[15] + gdecay.sun.gmpmt[16] + gdecay.sun.gmpmt[17] ;
     }

     if(rEvent[gdecay.sun.gmpmt[18].getId()].isValid() && rEvent[gdecay.sun.gmpmt[19].getId()].isValid() && rEvent[gdecay.sun.gmpmt[20].getId()].isValid()) { 
      gdecay.sun.rseg[6] = gdecay.sun.gmpmt[18] + gdecay.sun.gmpmt[19] + gdecay.sun.gmpmt[20] ;
     }
      
     if(rEvent[gdecay.sun.gmpmt[21].getId()].isValid() && rEvent[gdecay.sun.gmpmt[22].getId()].isValid() && rEvent[gdecay.sun.gmpmt[23].getId()].isValid()) {  
      gdecay.sun.rseg[7] = gdecay.sun.gmpmt[21] + gdecay.sun.gmpmt[22] + gdecay.sun.gmpmt[23] ; 
     }

     
    // Calibrating the SuN segments
     for(int i=0;i<8;i++){
      if ( (rEvent[gdecay.sun.rseg[i].getId()].isValid()) && (gdecay.sun.rseg[i]>30.0) ) {
      gdecay.sun.cseg[i] =gammav.SuN.square[i] * gdecay.sun.rseg[i] * gdecay.sun.rseg[i] + gammav.SuN.slope[i] * gdecay.sun.rseg[i] + gammav.SuN.intercept[i];}
     }
   
    // Calibrate I2NTOF based on I2POS
     if ( rEvent[bdecay.tac.pin01I2N.getId()].isValid() ) {
       if ( rEvent[bdecay.tac.i2pos.getId()].isValid() ) {
	bdecay.pid.i2ntof = bdecay.tac.pin01I2N*bdecayv.tac.i2ncorr-(bdecayv.tac.i2nposcorr*bdecay.tac.i2pos) + 1500;
       }
       else {
       bdecay.pid.i2ntof = (bdecay.tac.pin01I2N*bdecayv.tac.i2ncorr)+1500;
       }
       //bdecay.tac.i2poscorr = (bdecay.tac.i2ntof*bdecayv.tac.i2nposcorr) +(bdecayv.tac.i2ncorr*bdecay.tac.i2pos)+1500;
     }

    // Calibrate I2STOF based on I2POS
     if ( rEvent[bdecay.tac.pin01I2S.getId()].isValid() ) {
       if ( rEvent[bdecay.tac.i2pos.getId()].isValid() ) {
	bdecay.pid.i2stof = (bdecay.tac.pin01I2S*bdecayv.tac.i2scorr)-(bdecayv.tac.i2sposcorr*bdecay.tac.i2pos) + 1500;
       }
       else {
       bdecay.pid.i2stof = (bdecay.tac.pin01I2S*bdecayv.tac.i2scorr)+1500;
       }
     }
    // Calibrate pin1 energy by I2position
    if ( rEvent[bdecay.pin01.energy.getId()].isValid() ) {
       if ( rEvent[bdecay.tac.i2pos.getId()].isValid() ) {
	     bdecay.pid.de1 = bdecay.pin01.energy*bdecayv.tac.pin1corr-(bdecayv.tac.pin1poscorr*bdecay.tac.i2pos);
       }
       else {
         bdecay.pid.de1 = (bdecay.pin01.energy*bdecayv.tac.pin1corr);
       }
    }



    // Correct BCS front.isum and BCS front.imax based on i2 position
     if ( rEvent[bdecay.front.isum.getId()].isValid() ) {
       bdecay.pid.fisum = (bdecay.front.isum*bdecayv.pid.fisumcorr) - (bdecayv.pid.i2posfisumcorr*bdecay.tac.i2poscorr);
       bdecay.pid.fimax = (bdecay.front.imax*bdecayv.pid.fimaxcorr) - (bdecayv.pid.i2posfimaxcorr*bdecay.tac.i2poscorr);
     }
 
     // Correct BCS back.isum and BCS back.imax  based on i2 position
     if ( rEvent[bdecay.back.isum.getId()].isValid() ) {
       bdecay.pid.bisum = (bdecay.back.isum*bdecayv.pid.bisumcorr) - (bdecayv.pid.i2posbisumcorr*bdecay.tac.i2poscorr);
       bdecay.pid.bimax = (bdecay.back.imax*bdecayv.pid.bimaxcorr) - (bdecayv.pid.i2posbimaxcorr*bdecay.tac.i2poscorr);
     }

    // Correct SuN front.isum and SuN front.imax based on i2 position
     if ( rEvent[gdecay.front.isum.getId()].isValid() ) {
       bdecay.pid.sunfisum = (gdecay.front.isum*bdecayv.pid.fisumcorr) - (bdecayv.pid.i2posfisumcorr*bdecay.tac.i2poscorr);
       bdecay.pid.sunfimax = (gdecay.front.imax*bdecayv.pid.fimaxcorr) - (bdecayv.pid.i2posfimaxcorr*bdecay.tac.i2poscorr);
     }
 
     // Correct SuN back.isum and SuN back.imax  based on i2 position
     if ( rEvent[gdecay.back.isum.getId()].isValid() ) {
       bdecay.pid.sunbisum = (gdecay.back.isum*bdecayv.pid.bisumcorr) - (bdecayv.pid.i2posbisumcorr*bdecay.tac.i2poscorr);
       bdecay.pid.sunbimax = (gdecay.back.imax*bdecayv.pid.bimaxcorr) - (bdecayv.pid.i2posbimaxcorr*bdecay.tac.i2poscorr);
     }

  // determine if tacs need to be calibrated
//   if ( rEvent[bdecay.tac.i2ntof.getId()].isValid()  && rEvent[bdecay.pin01.energy.getId()].isValid() ) {
//     bdecay.tac.i2ncorr = bdecay.pin01.time-( bdecay.front.hitimecfd[1]/65536. + bdecay.front.hitimelow[1] + bdecay.front.hitimehigh[1]*4294967296.) +1000 ;   
//     cout << "time " << bdecay.pin01.time << " " <<  bdecay.front.hitimecfd[1] << " " <<  bdecay.front.hitimelow[1] << " " <<  bdecay.front.hitimehigh[1] << " " << bdecay.front.hitimecfd[1]/65536. + bdecay.front.hitimelow[1] + bdecay.front.hitimehigh[1]*4294967296. << " " <<  bdecay.tac.i2ncorr << endl;

//     bdecay.pid.i2ntof = bdecay.tac.i2ncorr;
//   }

  /* //not using these spectra
  // determine if tacs need to be calibrated
  if ( rEvent[bdecay.tac.i2stof.getId()].isValid()  && rEvent[bdecay.tac.i2pos.getId()].isValid() ) {
    bdecay.tac.i2scorr = bdecay.tac.i2stof + 
      (bdecayv.tac.i2scorr*bdecay.tac.i2pos);
    bdecay.pid.i2stof = bdecay.tac.i2scorr;
  }

  if ( rEvent[bdecay.tac.i2stof.getId()].isValid() ) 
    bdecay.pid.i2stof = bdecay.tac.i2stof;
  */

   //cout << "Almost end of Calib" << endl; 
  bdecay.raw.chanidhit.clear();
 
// cout << "  End of calib." << endl; 

 return kfTRUE; /* kfFALSE would abort pipeline */  
 
};

double
CBDecayCalibrator::EqualDistr() 
{
  unsigned long itemp;
  float rand;
  static unsigned long jflone = 0x3f800000;
  static unsigned long jflmsk = 0x007fffff;
  
  idum = 166454L*idum + 1013904223L;
  itemp = jflone | (jflmsk & idum);
  rand = (*(float*)&itemp) - 1.0;

  return rand;
}
