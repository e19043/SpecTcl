/*************************************************************************** 
   SpecTcl BCS Eventprocessor --> UNPACKER for Digital Data Acquisition
   Based on standard BCS SpecTcl codes

   S.N.Liddick/H.L.Crawford. Updated for DDAS 6/2/2010
***************************************************************************/


#ifndef __BDECAYUNPACKER_H
#define __BDECAYUNPACKER_H

#ifndef __EVENTPROCESSOR_H
#include <EventProcessor.h>
#endif

#ifndef __TRANSLATORPOINTER_H
#include <TranslatorPointer.h>
#endif

#ifndef __TCLANALYZER_H
#include <TCLAnalyzer.h>
#endif

#include <vector>
#include "SpecTcl.h"
#include "ddaschannel.h"
using namespace std;

/* Define a class known only to Unpacker that can accumulate 
   ddas channels sorted into true events. */

/*! \brief DDAS channel object
 *
 *  The ddaschannel object takes the data from the Pixie16 data stream
 *  on a channel-by-channel basis.  All information processing in the 
 *  unpacker is performed on the basis of individual channels firing
 *  or lists of channels firing.  All channels triggering within a
 *  user-defined coincidence window are grouped together in a vector
 *  and once a break in time is found the vector of channels is treated
 *  as an event for subsequent processing.
 */

/* class ddaschannel  */
/* { */
/*  public: */

/*   /\********** Variables **********\/ */
/*   // A channel event always has the following information */
/*   Int_t chanid;                //!< channel number */
/*   Int_t finishcode;            //!< pileup identifier - firmware dependent */
/*   Int_t overflowcode;          //!< overflow identifier - possibly firmware */
/*                                //!< dependent */
/*   Int_t channellength;         //!< Inclusive event size */
/*   Int_t channelheaderlength;   //!< Inclusive header length (includes all */
/*                                //!< available information except trace data */
/*   Int_t slotid;                //!< location of the module slot */
/*   Int_t crateid;               //!< crate number */
/*   Int_t id;                    //!< global channel identifier */

/*   unsigned long energy;        //!< channel energy */
/*   unsigned long timehigh;      //!< most significant bits of time stamp (16 bit) */
/*   unsigned long timelow;       //!< least significant bits of time stamp (32 bit) */
/*   unsigned long timecfd;       //!< constant fraction timing */
/*   Int_t tracelength;           //!< number of 12-bit trace data following header */
  
/*   double  time;                //!< reconstructed time (use with caution) */
/*   double  cfd;                 //!< reconstructed time with cfd (use with caution) */
  
/*   // A channel sometimes has extra information to be stored here */
/*   vector<UInt_t> Energysum;    //!< energy sums from pixie16 */
/*   vector<UInt_t> QDCsum;       //!< qdc sums from pixie16 */

/*   // A waveform (or trace) may be stored here */
/*   vector<UInt_t> trace;        //!< trace data from pixie16 */


/*   /\********** Functions **********\/ */
/*   //! \brief Default constructor, misc. initializations */
/*   ddaschannel(); */
/*   //! \brief Default destructor, currently empty */
/*   ~ddaschannel(); */

/* }; */

class ddaschannel;

class CBDecayUnpacker : public  CEventProcessor
{
  
 public:
  vector<ddaschannel*>  channellist;               //!< collection of channels within one event
  vector<ddaschannel*>::iterator channellist_it;   //!< iterator over channels in an event
  vector<ddaschannel*>  previousevent;             //!< obsolete
  vector<ddaschannel*>::iterator previousevent_it; //!< obsolete
 
  unsigned long m_currenttime_low;                 //!< portion of timestamp from current event
  unsigned long m_currenttime_high;                //!< portion of timestamp from current event
  
  unsigned long m_lasttime_low;                    //!< portion of timestamp from last event
  unsigned long m_lasttime_high;                   //!< portion of timestamp from last event

  unsigned long numchans, timeskip;                //!< number of channels in an event

  //  unsigned int eventbuilt;                             //!< flag, set to one to indicate data was
                                                   //!< built by an external program
  ddaschannel *chan;                               //!< pointer to a channel of ddas data
  UInt_t m_timewindow;                             //!< user defined channel coincidence window for event
  unsigned long fragcount1;
  unsigned long fragcount2;
  SpecTcl *mylocalspec;                            //!< obsolete
  CSpectrum *swaveform;                            //!< force spectcl to display traces

  virtual Bool_t operator()(const Address_t pEvent,
			    CEvent&         rEvent,
			    CAnalyzer&      rAnalyzer,
			    CBufferDecoder& rDecoder);
  
  virtual Bool_t OnAttach(CAnalyzer& rAnalyzer);
  virtual Bool_t OnBegin(CAnalyzer& rAnalyzer,CBufferDecoder& rDecoder);
  virtual Bool_t OnEnd(CAnalyzer& rAnalyzer,CBufferDecoder& rDecoder);
  
 protected:
  void ResetChannelList();
  void ResetPreviousEvent();
  void ddastospectcl(vector<ddaschannel*> &, CEvent &rEvent);

};

#endif






