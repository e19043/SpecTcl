/***********************************************************************
   SpecTcl BCS Eventprocessor --> CALIBRATOR for DDAS
   Based on standard BCS SpecTcl codes

   S.N.Liddick/H.L.Crawford. Updated for DDAS 6/2/2010
***********************************************************************/

#ifndef __BDECAYCALIBRATOR_H
#define __BDECAYCALIBRATOR_H

#ifndef __EVENTPROCESSOR_H
#include <EventProcessor.h>
#endif

#ifndef __TRANSLATORPOINTER_H
#include <TranslatorPointer.h>
#endif

#ifndef __TCLANALYZER_H
#include <TCLAnalyzer.h>
#endif

class CBDecayCalibrator : public  CEventProcessor
{
public:
  unsigned long idum;
  double EqualDistr();
  virtual Bool_t operator()(const Address_t pEvent,
			    CEvent&         rEvent,
			    CAnalyzer&      rAnalyzer,
			    CBufferDecoder& rDecoder);
};

#endif
