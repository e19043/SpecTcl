/*****************************************************************/
/* Unpacker.cpp for DSSD Beta Decay - Digital Data Acquisition   */
/* Based on standard BCS SpecTcl codes                           */
/* Sean Liddick/Heather Crawford, June 2010                      */
/*****************************************************************/

/* Translater pointer is included to translate data buffer 
   representation used by the DAQ system to the internal 
   representation used by the hostsystem */

/***************** Data Structure ******************
 
   Data format is a time-ordered list of 
   individual channel events.  Each channel 
   event has the following format:

        # of event words (16 bits)
     Module identifications (32 bits - 2 words)
     Event header (32 bits - 2 words)
    Event time low (32 bits - 2 words)
    Event time high (16 bits - 1 word)
       CFD time (16 bits - 1 word)
        Energy (16 bits - 1 word)
     Trace length (16 bits - 1 word)
    
***************************************************/

/************** Crate/module/channel layout ***************
// 06/22/2015 Modifying for NERO/BCS in e17028
// We have three crates. Master crate has 11 modules. Slave crate 1 has 4 modules. Slave crate 2 has 7 modules. 
 
    Crate 1: 
	Module 1 (slot 2): DSSD front high gain 01-16
	Module 2 (slot 3): DSSD front high gain 17-32
	Module 3 (slot 4): DSSD front high gain 33-40, front low gain 40-33
	Module 4 (slot 5): DSSD front low gain 32-17
	Module 5 (slot 6): DSSD front low gain 16-01	
	Module 6 (slot 7): DSSD back high gain 01-16
	Module 7 (slot 8): DSSD back high gain 17-32
	Module 8 (slot 9): DSSD back high gain 33-40, back low gain 40-33
	Module 9 (slot 10): DSSD back low gain 32-17
	Module 10 (slot 11): DSSD back low gain 16-01
	Module 11 (slot 12): SSSD high gain 1-16

    Crate 2: 
	Module 1 (slot 2): NERO quad A
	Module 2 (slot 3): NERO quad B
	Module 3 (slot 4): NERO quad C
	Module 4 (slot 5): NERO quad D
    
    Crate 3: 
	Module 1 (slot 2): SuN upper half
	Module 2 (slot 3): SuN lower half
	Module 3 (slot 4): PINs + Veto + TACS
	Module 4 (slot 5): SuN DSSD front high gain 1-16 
	Module 5 (slot 6): SuN DSSD back high gain 1-16 
	Module 6 (slot 7): SuN DSSD front low gain 1-16 
	Module 7 (slot 8): SuN DSSD back low gain 1-16

**************************************************/

#ifdef HAVE_STD_NAMESPACE
using namespace std;
#endif

#include <config.h>
#include <Event.h> 
#include <stdint.h>
#include <iomanip>
#include <string>
#include <math.h>

#include "Parameters-ddas.h"
#include "Variables-ddas.h"
#include "Unpacker_ddas.h" 

//#include "ddaschannel.h"

#define BDECAY_PACKET 0x7100
#define SEGA_PACKET 0x2000

#define BdecayID BDECAY_PACKET
#define SeGAID SEGA_PACKET

#define SEGA_INCLUDED 0
#define ERROR_CHAN 0

#define CHANNELIDMASK             0xF  // Bits 0-3 inclusive
#define SLOTIDMASK               0xF0  // Bits 4-7 inclusive
#define CRATEIDMASK             0xF00  // Bits 8-11 inclusive
#define HEADERLENGTHMASK      0x1F000  // Bits 12-16 inclusive
#define CHANNELLENGTHMASK  0x3FFE0000  // Bits 17-29 inclusive
#define OVERFLOWMASK       0x40000000  // Bit 30 has overflow information (1 - overflow)
#define FINISHCODEMASK     0x80000000  // Bit 31 has pileup information (1 - pileup)
#define LOWER16BITMASK         0xFFFF  // Lower 16 bits
#define UPPER16BITMASK     0xFFFF0000  // Upper 16 bits
#define LOWER12BITMASK          0xFFF  // Lower 12 bits
// number of words added to pixie16 channel event header when energy sums
// and baselines are recorded
#define SIZEOFESUMS                 4
// number of words added to pixie16 channel event header when QDC sums
// are recorded
#define SIZEOFQDCSUMS               8

// ddaschannel::ddaschannel()
// {
//   chanid = 0; 
//   slotid = 0;
//   crateid = 0;
//   id = 0;

//   channelheaderlength = 0;
//   channellength = 0;
//   finishcode = 0;
//   overflowcode = 0;
//   tracelength = 0;
  
//   timelow = 0;
//   timehigh = 0;
//   timecfd = 0;
//   energy = 0;
 
//   time = 0;
//   cfd = 0;

//   Energysum.clear();
//   QDCsum.clear();
//   trace.clear();
// }

// ddaschannel::~ddaschannel(){

//   //delete Energysum;
//   //delete QDCsum;
//   //delete trace;

// }

// (09/27/2010) DTM - reset last timestamp when something new is attached
int countingevt;
int badevt;

Bool_t CBDecayUnpacker::OnAttach(CAnalyzer& rAnalyzer)
{
  cout << "attaching event processor to spectcl and zeroing last timestamp." << endl;
  m_lasttime_low = m_lasttime_high = 0;
  countingevt = 0; //zeroing evt count
  badevt = 0; //zeroing bad evt count 
  return kfTRUE;
}
// Bool_t CBDecayUnpacker::OnAttach(CAnalyzer& rAnalyzer){

//   cout << "attaching event processpr to spectcl " 
//        << bdecayv.ddas.totmod << " " << bdecayv.ddas.ncrates 
//        << " " << bdecayv.ddas.nmodc[0] << endl;

//   for(int i =0; i < bdecayv.ddas.ncrates; i++){
//     bdecayv.ddas.totmod = bdecayv.ddas.totmod + bdecayv.ddas.nmodc[i];
//     cout << "number of modules on attach ******************************** " << bdecayv.ddas.totmod << endl;
//   }

//   return kfTRUE;

// }

Bool_t CBDecayUnpacker::OnBegin(CAnalyzer& rAnalyzer,CBufferDecoder& rDecoder)
{

  cout << " SpecTcl found data, on begin function " << endl;
  cout << " is this printed " << endl;

  m_currenttime_low = 0;
  m_currenttime_high = 0;
  
  m_lasttime_low = 0;
  m_lasttime_high = 0;
  countingevt = 0;
  badevt = 0;
  m_timewindow = 20000; // Coincidence window in Pixie16 (100 MHz) clock ticks, 
                       // this parameter is defined twice

  //retrieve singleton spectcl
  mylocalspec->getInstance(); 
  numchans = 0;
  timeskip = 0;
  fragcount1 = 0;
  fragcount2 = 0;

  //eventbuilt = 1;

  return kfTRUE;

}

void CBDecayUnpacker::ResetChannelList()
{
  // cout << "Reseting channel list. Size = " << channellist.size() << endl;

  for(channellist_it = channellist.begin(); channellist_it < channellist.end(); channellist_it++) {
    delete *channellist_it;
  }

  channellist.clear();
//  cout << "did it make it to reset" << endl;
}


Bool_t 
CBDecayUnpacker::operator()(const Address_t pEvent,
			    CEvent&         rEvent,
			    CAnalyzer&      rAnalyzer,
			    CBufferDecoder& rDecoder)
{
  //must check to see if total number of modules in system has been set
  //if this calculation is performed in the OnBegin method then SpecTcl MUST be started before 
  //readout commences so that SpecTcl can catch a begin run buffer
  //if this calculation is performed in the OnAttach method the initialization tcl scripts have
  //not been run so that the required varaibles are not set.

  int sourceid, sourceid1;

//  cout << "number of modules " << bdecayv.ddas.totmod << endl;

  if(bdecayv.ddas.totmod == 0){
    for(int i =0; i < bdecayv.ddas.ncrates; i++){
      bdecayv.ddas.totmod = bdecayv.ddas.totmod + bdecayv.ddas.nmodc[i];
    }
    cout << "number of modules " << bdecayv.ddas.totmod << endl;
  }
  //cout << "unpack " << endl;
  m_timewindow = 200000;

  /* Translates pointer pEvent pointing to raw data into pointer p */
  TranslatorPointer<uint32_t> p(*(rDecoder.getBufferTranslator()), pEvent);
  CTclAnalyzer& rAna((CTclAnalyzer&)rAnalyzer);

  uint32_t totwords;
  //--p;
  totwords = *p/2;//totwords = (*(--p))/2; //converts total #bytes "words" into total number (inclusive) of 16-bits in event
  
//  cout << "tot words begin " << totwords << " *p " << *p << endl;

  p++; //back to starting point

  //p++;
  rAna.SetEventSize(/*nWords*/totwords*sizeof(uint16_t)); /* Set event size */

  totwords = totwords - 2; // subtract off size and type
  //cout << " data " << p[0] << " " << p[1] << " " <<p[2] << " " <<p[3] << " " <<p[4] << " " <<p[5] << " " <<p[6] << " " <<p[7] << endl;
  if (totwords == 4) {
    //cout << "Ring buffer with only header info?" << endl;
  }
  //  Loop over all fragments
  //cout << "-------------------------------" << endl;
  //cout << "Entering data after EVB header" << endl;
  countingevt +=1; 
  //cout << "This is event number " << dec << countingevt << endl;
  /*if ((countingevt==40110) || (countingevt==40111) ){
  	cout << " data " << hex << p[0] << " " << hex << p[1] << " " << hex << p[2] << " " << hex << p[3] << " " << hex << p[4] << " " << hex << p[5] << " " << hex << p[6] << " " << hex << p[7] << " " << hex << p[8] << " " << hex << p[9] << " " << hex << p[10] << " " << hex << p[11] << endl;
  }*/
  while(totwords !=0){
  //while(totwords != 0){
    //cout << "Valid number of words ----------------------------------------" << endl;
    //item has a 64-bit timestamp
    ++p; ++p;
    totwords = totwords - 4;
    //cout << "---" << endl;
    //cout << totwords << endl;      

    //event has a 32-bit source id
    //if ((*p!=1)){
    //cout << "source id " << dec << *p << endl;
	//sourceid = *p;	
	//}
    sourceid = (*p & LOWER16BITMASK); //this gets the data source ID
    ++p;
    totwords = totwords - 2;
    //cout << totwords << endl;      
  
    //event has a 32-bit payload
    // subtract 4 to get the total number of 16-bit things
    uint32_t totwords1 = *p++; //++p;
    totwords = totwords - 2;
    //cout << totwords << endl;      
    //if(totwords > 24) cout << " totwords " << totwords << endl;
    
    //already passed 8 words of data
    //totwords = totwords - 8;
    
    //event has a barrier
    ++p;
    totwords = totwords - 2;
    //cout << totwords << endl;      
    
    //loop over fragments within event

    //first fragment
    //Ring Item header
    ++p;++p;++p;
    totwords = totwords - 6;
    //cout << totwords << endl;      
    p+=2;
    totwords = totwords - 4;// subtract offf 64-bit fragment timestamp
    
    sourceid1 = (*p & LOWER16BITMASK); //this gets the fragment source ID
    //cout<<"fragment sourceid1 = "<<hex<<sourceid1<<endl;
    ++p; //skip source id1
    totwords = totwords - 2;// subtract off source id1
    
    ++p;//skip fragment body header/ barrier (?)
    totwords = totwords - 2;// subtract off fragment body header/ barrier (?)
    /////////////////////////////////////////////////////////////////////////
    
    //cout<<" I am the size of the fragment "<<dec<<*p<<"  words"<<endl;
    uint32_t ChannelWordsCount = *p;//++; /* Word counter in this item*/
  
    uint32_t nWords = *p;//++; /* Word counter in this item*/
    //totwords = totwords - 2;
    //cout << totwords << endl;      

    //cout << "Number of words in event: " << nWords << endl;

    //nWords--; /* Already, we are past the event size */

    // should in principle stick new stuff here
    chan = new ddaschannel();
    // Unpack the channel data into a vector until an event is accumulated
    chan->UnpackChannelData(p);
    totwords = totwords - nWords; //advance counter to new spot
    //cout << dec << "totwords= " << totwords << ", nWords= " << nWords << endl;
    
    // determine global channel number of this channel
    // number of channels in previous crate (if any)
    
    chan->id = 0;
    //cout << "chan->id = " << chan->id << endl;
    chan->crateid = chan->crateid - 1; 
    for(int z =0; z < chan->crateid; z++){
//      cout << bdecayv.ddas.nmodc[z] << "\t \t " << bdecayv.ddas.channelpermod << endl;
//      cout << chan->crateid << "\t \t " << chan->chanid << endl;
      chan->id += bdecayv.ddas.nmodc[z] * bdecayv.ddas.channelpermod;
    }
    //cout << "chan->id after for = " << chan->id << endl; 
    //number of channels in previous module
    //chan->id += (chan->slotid - 2)*bdecayv.ddas.channelpermod;
    //cout << "chan->id after slot = " << chan->id << endl; 
    //number of previous channels within module
    chan->id += chan->chanid;
    chan->id = (chan->id +16*((chan->slotid) -2));
   /*if (chan->id < 0) {
   	chan->id = 287;
        badevt += 1; 
    }*/
//    if ((chan->id == 226 )
//      break; 
    /*if ((chan->crateid == 0) && chan->slotid == 3 ) 
    {
    cout << "chan->id final = " << chan->id << endl;    
    cout << "chan->crateid = " << dec << chan->crateid << endl; 
    cout << "chan->slotid = " << dec << chan->slotid << endl;  
    cout << "chan->chanid = " << dec << chan->chanid << endl; 
    cout << "chan->chanenergy = " << dec << chan->energy << endl; 
    //cout << dec << countingevt << endl;//
    }
    */
    if ((chan->id == 412)) {
    cout << "???????" << endl;
    }
    m_currenttime_low = chan->timelow;
    m_currenttime_high = chan->timehigh;
    
    numchans++;
    
    
    
    
    //if events have already been built by NSCL DAQ just send for processing and 
    // clear vector.  If not don't do anything, it'll be handled by code below.
    if(bdecayv.ddas.evtbuilt){
      channellist.push_back(chan);
    }
    
  } // end while loop over event size.

  //cout << " out of loop " << endl;

  if(bdecayv.ddas.evtbuilt){
    // cout << " inside " << endl;
    ddastospectcl(channellist, rEvent);
    ResetChannelList();
  }
  else {
    
    //Calculate time difference between current time and previous time
    double deltaT = 0;
    if (m_currenttime_high == m_lasttime_high) {
      
      if ( (m_currenttime_low < m_lasttime_low) ) {
	//cout << " ****** PROBLEMS WITH TIME ****** " << m_currenttime_low 
	//   << "  " << m_lasttime_low << endl;
	timeskip++;
      } else {
	deltaT = m_currenttime_low - m_lasttime_low;
      }
      
    } else if (m_currenttime_high < m_lasttime_high) {
      
      //cout << " ******** PROBLEMS WITH TIME ******* " << endl;
      timeskip++;
      
    } else if (m_currenttime_high > m_lasttime_high) {
      
      long dT = m_lasttime_low - m_currenttime_low;
      deltaT = 4294967296. - dT;
      
    }
    
    if( (deltaT) > m_timewindow ) {
      
      // We have finished accumulating a new event, send it for processing
      ddastospectcl(channellist, rEvent);
      
      // Clear channel list array
      ResetChannelList();
      
      // Add current channel to channellist to begin accumulation of new event
      channellist.push_back(chan);
      
      // Update lasttime
      m_lasttime_low = m_currenttime_low;
      m_lasttime_high = m_currenttime_high;
      
      return kfTRUE;  // continue the spectcl processing
      
    } else {
      
      /* This is the continuation of a previous event, add current channel 
	 to channellist */
      channellist.push_back(chan);
      cout << "does it break in else?" << endl;
      return kfFALSE;  // do not continue the spectcl processing (no event yet)
      
    }
  
  }

//  cout << "did it make it here" << endl;
  return kfTRUE;  
}


/******************************************************************/
/******************************************************************/
/******************** DDAS UNPACKING FUNCTION *********************/
/******************************************************************/
/******************************************************************/

void CBDecayUnpacker::ddastospectcl(vector<ddaschannel *> &channellist, 
				    CEvent &rEvent)
{
  //cout << "Unpacking channel list.  Size: " << channellist.size() << endl;

  Int_t eventsize = channellist.size();
  bdecay.ddasdiagnostics.cmult = eventsize;

  double starttime_low, endtime_low;
  double starttime_high, endtime_high;

  channellist_it = channellist.begin();
  //cout << "after channellist.begin()" << endl;
  bdecay.ddasdiagnostics.adc01hit = 0;
  bdecay.ddasdiagnostics.adc02hit = 0;
  bdecay.ddasdiagnostics.adc03hit = 0;
  bdecay.ddasdiagnostics.adc04hit = 0;
  bdecay.ddasdiagnostics.adc05hit = 0;
  bdecay.ddasdiagnostics.adc06hit = 0;
  bdecay.ddasdiagnostics.adc07hit = 0;
  bdecay.ddasdiagnostics.adc08hit = 0;
  bdecay.ddasdiagnostics.adc09hit = 0;
  bdecay.ddasdiagnostics.adc10hit = 0;
  bdecay.ddasdiagnostics.adc11hit = 0;
  bdecay.ddasdiagnostics.adc12hit = 0;
  bdecay.ddasdiagnostics.adc13hit = 0;
  bdecay.ddasdiagnostics.adc14hit = 0;
  bdecay.ddasdiagnostics.adc15hit = 0;
  bdecay.ddasdiagnostics.adc16hit = 0;
  bdecay.ddasdiagnostics.adc17hit = 0;
  bdecay.ddasdiagnostics.adc18hit = 0;
  bdecay.ddasdiagnostics.adc19hit = 0;
  bdecay.ddasdiagnostics.adc20hit = 0;
  
  //bdecay.raw.chanidhit.clear();

//  cout << "did it make it here" << endl;

  for (channellist_it = channellist.begin(); 
       channellist_it < channellist.end(); channellist_it++) {
    /* The time of an event will be taken as the time of the first 
       channel in the event */
    //cout << "do we enter for loop?" << endl;
    //cout << "(*channellist_it)->id = "  << (*channellist_it)->id << endl;
    if(channellist_it == channellist.begin()){
      //cout << "do we go into if?" << endl;
      starttime_low = (*channellist_it)->timelow;
      starttime_high = (*channellist_it)->timehigh;
      bdecay.clock.fast = (*channellist_it)->timelow;
      bdecay.clock.slow = (*channellist_it)->timehigh;
      bdecay.clock.current = (*channellist_it)->time; 
      bdecay.clock.cfd  = (*channellist_it)->cfd;
      // bdecay.clock.initial = (*channellist_it)->time;
    }

    //Unpack the data according to the channel id number
    bdecay.raw.chanidhit.push_back((*channellist_it)->id);
    //cout << "push back broken?" << endl;	
    bdecay.raw.chanid[(*channellist_it)->id].adc       = ((*channellist_it)->energy);
//    cout << (*channellist_it) << ((*channellist_it)->energy) << endl;
    //cout << "adc broken?" << endl;
    //cout << "(*channellist_it)->id " << (*channellist_it)->id << "   (*channellist_it)->energy " << (*channellist_it)->energy << endl;
    bdecay.raw.chanid[(*channellist_it)->id].timehigh  = ((*channellist_it)->timehigh);
    //cout << "timehigh broken?" << endl;
    bdecay.raw.chanid[(*channellist_it)->id].timelow   = ((*channellist_it)->timelow);
    //cout << "timelow broken?" << endl;
    bdecay.raw.chanid[(*channellist_it)->id].timecfd   = ((*channellist_it)->timecfd);
    //cout << "timecfd broken?" << endl;
    bdecay.raw.chanid[(*channellist_it)->id].time      = ((*channellist_it)->time);
 //   cout << (*channellist_it) << ((*channellist_it)->time);
    bdecay.raw.chanid[(*channellist_it)->id].overflow      = ((*channellist_it)->overflowcode);
    //cout << "time broken?" << endl;
    endtime_low = (*channellist_it)->timelow;
    endtime_high = (*channellist_it)->timehigh;
    
/*
    if ( ((*channellist_it)->id ==211 || (*channellist_it)->id == 227) || 
         (*channellist_it)->id ==275  ) {
        cout << "channel= " << dec << (*channellist_it)->id << endl;
	cout << "time = " << dec << setprecision(15) << bdecay.raw.chanid[(*channellist_it)->id].time << endl;
	cout << "energy = " << bdecay.raw.chanid[(*channellist_it)->id].adc << endl;
    }
*/
      }
//  cout << "did it make it here" << endl;
  bdecay.ddasdiagnostics.eventlength = (endtime_low - starttime_low) * 10;
  /* add by SAS 01-10-2012 to see where crate data goes */
  int q;
  for(q=0; q<16; q++){
    if (rEvent[bdecay.raw.chanid[q].timehigh.getId()].isValid()) {
       bdecay.ddasdiagnostics.adc01hit += pow(2.0,q);
    }
  }

  for(q=16; q<32; q++){
    if (rEvent[bdecay.raw.chanid[q].timehigh.getId()].isValid()) {
       bdecay.ddasdiagnostics.adc02hit += pow(2.0,(q-16.0));
    }
  }
  
  for(q=32; q<48; q++){
    if (rEvent[bdecay.raw.chanid[q].timehigh.getId()].isValid()) {
       bdecay.ddasdiagnostics.adc03hit += pow(2.0,(q-32.0));
    }
  }
  
  for(q=48; q<64; q++){
    if (rEvent[bdecay.raw.chanid[q].timehigh.getId()].isValid()) {
       bdecay.ddasdiagnostics.adc04hit += pow(2.0,(q-48.0));
    }
  }
  
  for(q=64; q<80; q++){
    if (rEvent[bdecay.raw.chanid[q].timehigh.getId()].isValid()) {
       bdecay.ddasdiagnostics.adc05hit += pow(2.0,(q-64.0));
    }
  }
  
  for(q=80; q<96; q++){
    if (rEvent[bdecay.raw.chanid[q].timehigh.getId()].isValid()) {
       bdecay.ddasdiagnostics.adc06hit += pow(2.0,(q-80.0));
    }
  }
  
  for(q=96; q<112; q++){
    if (rEvent[bdecay.raw.chanid[q].timehigh.getId()].isValid()) {
       bdecay.ddasdiagnostics.adc07hit += pow(2.0,(q-96.0));
    }
  }
  
  for(q=112; q<128; q++){
    if (rEvent[bdecay.raw.chanid[q].timehigh.getId()].isValid()) {
       bdecay.ddasdiagnostics.adc08hit += pow(2.0,(q-112.0));
    }
  }
  
  for(q=128; q<144; q++){
    if (rEvent[bdecay.raw.chanid[q].timehigh.getId()].isValid()) {
       bdecay.ddasdiagnostics.adc09hit += pow(2.0,(q-128.0));
    }
  }
  
  for(q=144; q<160; q++){
    if (rEvent[bdecay.raw.chanid[q].timehigh.getId()].isValid()) {
       bdecay.ddasdiagnostics.adc10hit += pow(2.0,(q-144.0));
    }
  }
  
  for(q=160; q<176; q++){
    if (rEvent[bdecay.raw.chanid[q].timehigh.getId()].isValid()) {
       bdecay.ddasdiagnostics.adc11hit += pow(2.0,(q-160.0));
    }
  }
  
  for(q=176; q<192; q++){
    if (rEvent[bdecay.raw.chanid[q].timehigh.getId()].isValid()) {
       bdecay.ddasdiagnostics.adc12hit += pow(2.0,(q-176.0));
    }
  }
  
  for(q=192; q<208; q++){
    if (rEvent[bdecay.raw.chanid[q].timehigh.getId()].isValid()) {
       bdecay.ddasdiagnostics.adc13hit += pow(2.0,(q-192.0));
    }
  }
//  cout << "did it make it here" << endl;
}


// Just printout something when an end of run is seen:

Bool_t
CBDecayUnpacker::OnEnd(CAnalyzer& rAnalyzer,CBufferDecoder& rDecoder)
{
  cout << "Number of events = " << dec << countingevt << " and number of bad events = " << dec << badevt << "." << endl;
  cerr << "End of run encountered on data source\n";\
    return kfTRUE;
}
