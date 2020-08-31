/*************************************************************************** 
   COMPACT SpecTcl BCS Eventprocessor --> CORRELATOR for DDAS
   Based on standard BCS SpecTcl codes
   
   J.Pereira. Last version 9/1/2005
   S.N.Liddick/H.L.Crawford. Updated for DDAS 6/2/2010
***************************************************************************/

#ifndef __BDECAYCORRELATOR_H
#define __BDECAYCORRELATOR_H

#ifndef __EVENTPROCESSOR_H
#include <EventProcessor.h>
#endif

#ifndef __TRANSLATORPOINTER_H
#include <TranslatorPointer.h>
#endif

#ifndef __TCLANALYZER_H
#include <TCLAnalyzer.h>
#endif

class CBDecayCorrelator : public  CEventProcessor
{
public:
  virtual Bool_t operator()(const Address_t pEvent,
			    CEvent&         rEvent,
			    CAnalyzer&      rAnalyzer,
			    CBufferDecoder& rDecoder);

};

#endif
