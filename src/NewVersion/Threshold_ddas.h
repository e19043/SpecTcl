/*************************************************************************** 
   SpecTcl BCS Eventprocessor --> THRESHOLD for DDAS
   Based on standard BCS SpecTcl codes
   
   J.Pereira. Last version 8/31/2005
   S.N.Liddick/H.L.Crawford. Updated for DDAS 6/2/2010
***************************************************************************/

#ifndef __BDECAYTHRESHOLD_H
#define __BDECAYTHRESHOLD_H

#ifndef __EVENTPROCESSOR_H
#include <EventProcessor.h>
#endif

#ifndef __TRANSLATORPOINTER_H
#include <TranslatorPointer.h>
#endif

#ifndef __TCLANALYZER_H
#include <TCLAnalyzer.h>
#endif

class CBDecayThreshold : public  CEventProcessor
{
public:
  virtual Bool_t operator()(const Address_t pEvent,
			    CEvent&         rEvent,
			    CAnalyzer&      rAnalyzer,
			    CBufferDecoder& rDecoder);

};

#endif
