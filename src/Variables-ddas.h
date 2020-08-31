/*      File:  Variables.h
    	Variable definitions for the beta-decay setup
	The root variable name is bdecayv
	Author: D. Bazin
	Date: July 2001
	Altered to C++ class structure July09 by HLC
*/

#ifndef __TREEVARIABLE_H
#include <TreeParameter.h>
#endif

extern class betadecayvariables bdecayv;
extern class gammavariables gammav;
extern class nerovariables nerov;

///////////// BDECAY /////////////
///////////// BDECAY /////////////
///////////// BDECAY /////////////
// Clock Calibrator

class bdecayvClockCalibrator
{
 private:
  betadecayvariables* top;
  
 public:
  CTreeVariable calib;
  CTreeVariable scale;
  CTreeVariable max;
  CTreeVariable max_daughter;
  
 public:
  void Initialize(betadecayvariables* top, STD(string) name);
};

// Pin Calibrator

class bdecayvPinCalibrator 
{
 private:
  betadecayvariables* top;
  
 public:
  CTreeVariable slope;
  CTreeVariable intercept;
  CTreeVariable thresh;
  CTreeVariable ithresh;
  CTreeVariable iuld;

 public:
  void Initialize(betadecayvariables* top, STD(string) name);
};

// TAC Calibrator

class bdecayvTacCalibrator
{
 private:
  betadecayvariables* top;
  
 public:
  CTreeVariable i2ncorr;
  CTreeVariable i2scorr;
  CTreeVariable pin1corr;
  CTreeVariable i2sposcorr;
  CTreeVariable i2nposcorr;
  CTreeVariable pin1poscorr;

 public:
  void Initialize(betadecayvariables* top, STD(string) name);
};

// DSSD Calibrator

class bdecayvDSSDCalibrator
{
 private:
  betadecayvariables* top;
  
 public:
  CTreeVariableArray hioffset;
  CTreeVariableArray hislope;
  CTreeVariableArray loslope;

 public:
  void Initialize(betadecayvariables* top, STD(string) name);
};

// DSSD Threshold

class bdecayvDSSDThresh
{
 private:
  betadecayvariables* top;
  
 public:
  CTreeVariableArray hithresh;
  CTreeVariableArray lothresh;
  CTreeVariableArray duld;
  CTreeVariableArray loduld;

 public:
  void Initialize(betadecayvariables* top, STD(string) name);
};

// SSSD Calibration

class bdecayvSSSDCalibrator
{
 private:
  betadecayvariables* top;
  
 public:
  CTreeVariableArray offset;
  CTreeVariableArray slope;
  CTreeVariableArray thresh;
  CTreeVariableArray uld;

 public:
  void Initialize(betadecayvariables* top, STD(string) name);
};

// Hit flags

class bdecayvHitFlag 
{
 private:
  betadecayvariables* top;
  
 public:
  CTreeVariable pin01;
  CTreeVariable pin02;
  CTreeVariable pin03;
  CTreeVariable pin04;
  CTreeVariable pin05;
  CTreeVariable scint;
  CTreeVariable veto;
  CTreeVariable sssd01;
  CTreeVariable fronthi;
  CTreeVariable fronthiover;
  CTreeVariable frontlo;
  CTreeVariable backhi;
  CTreeVariable backhiover;
  CTreeVariable backlo;
  CTreeVariable taci2ntof;
  CTreeVariable taci2stof;
  CTreeVariable taci2pos;
  CTreeVariable tacpin01rf;
  CTreeVariable tacpin01xfp;
  CTreeVariable tacpin02xfp;

 public:
  void Initialize(betadecayvariables* top, STD(string) name);
};

// Correlation

class bdecayvCorrelation 
{
 private: 
  betadecayvariables* top;
  
 public:
  CTreeVariable reset;
  CTreeVariable resetclock; // Reset 50MHz clock
  CTreeVariable minimplant;

 public:
  void Initialize(betadecayvariables* top, STD(string) name);
};

// PID

class bdecayvPidCalibrator
{
 private:
  betadecayvariables* top;

 public:
  CTreeVariable de1_scale;
  CTreeVariable de1_offset;
  CTreeVariable de1_tof_corr;
  CTreeVariable de1_tof_offset;
  CTreeVariable de2_scale;
  CTreeVariable de2_offset;
  CTreeVariable de2_tof_corr;
  CTreeVariable de2_tof_offset;
  CTreeVariable de3_scale;
  CTreeVariable de3_offset;
  CTreeVariable de3_tof_corr;
  CTreeVariable de3_tof_offset;
  CTreeVariable isum_scale;
  CTreeVariable isum_offset;
  CTreeVariable isum_tof_corr;
  CTreeVariable isum_tof_offset;
  CTreeVariable imax_scale;
  CTreeVariable imax_offset;
  CTreeVariable imax_tof_corr;
  CTreeVariable imax_tof_offset;
  CTreeVariable fisumcorr;
  CTreeVariable bisumcorr;
  CTreeVariable fimaxcorr;
  CTreeVariable bimaxcorr;
  CTreeVariable i2posbimaxcorr;
  CTreeVariable i2posfimaxcorr;
  CTreeVariable i2posbisumcorr;
  CTreeVariable i2posfisumcorr;

 public:
  void Initialize(betadecayvariables* top, STD(string) name);
};

class bdecayvWaveform
{
 private:
  betadecayvariables* top;

 public:
  CTreeVariable get;
  CTreeVariable crate;
  CTreeVariable module;
  CTreeVariable channel;
  CTreeVariable elo;
  CTreeVariable ehi;

 public:
  void Initialize(betadecayvariables* top, STD(string) name);

};

class bdecayvDDAS
{
 private:
  betadecayvariables* top;

 public:
  CTreeVariable ncrates;
  CTreeVariableArray nmodc;
  CTreeVariable channelpermod;
  CTreeVariable totmod;
  CTreeVariable evtbuilt;

 public:
  void Initialize(betadecayvariables* top, STD(string) name);

};


/* The entire beta decay setup */
class betadecayvariables
{
 public:
  bdecayvClockCalibrator clock;
  bdecayvClockCalibrator clockisomer;
  bdecayvPinCalibrator pin01;
  bdecayvPinCalibrator pin02;
  bdecayvPinCalibrator pin03;
  bdecayvPinCalibrator scint;
  bdecayvPinCalibrator veto;
  bdecayvTacCalibrator tac;
  bdecayvDSSDCalibrator front;
  bdecayvDSSDCalibrator back;
  bdecayvDSSDThresh fthresh;
  bdecayvDSSDThresh bthresh;
  bdecayvSSSDCalibrator sssd01;
  bdecayvHitFlag hit;
  bdecayvCorrelation corr;
  bdecayvPidCalibrator pid;
  bdecayvWaveform waveform;
  bdecayvDDAS ddas;

 public:
  betadecayvariables(STD(string) name);
};

///////////// NERO /////////////
///////////// NERO /////////////
///////////// NERO /////////////
// NERO Hit flags

class nerovThresh
{
 private:
  nerovariables* top;
  
 public:
  CTreeVariableArray uthres;
  CTreeVariableArray lthres;

 public:
  void Initialize(nerovariables* top, STD(string) name);
};

class nerovHitFlag 
{
 private:
  nerovariables* top;
  
 public:
  CTreeVariable hit;
  CTreeVariable neroover;

 public:
  void Initialize(nerovariables* top, STD(string) name);
};



/* Nero setup */ 
class nerovariables
{
 public: 
  nerovHitFlag nerohit;
  nerovThresh nerothres;

 public:
  nerovariables(STD(string) name);
};

///////////// SUN /////////////
///////////// SUN /////////////
///////////// SUN /////////////

// SuN Clock Calibrator
class gammavClockCalibrator
{
 private:
  gammavariables* top;
  
 public:
  CTreeVariable calib;
  CTreeVariable scale;
  CTreeVariable max;
  CTreeVariable max_daughter;
  
 public:
  void Initialize(gammavariables* top, STD(string) name);
};

// SuN DSSD Calibrator

class gammavDSSDCalibrator
{
 private:
  gammavariables* top;
  
 public:
  CTreeVariableArray hioffset;
  CTreeVariableArray hislope;
  CTreeVariableArray loslope;

 public:
  void Initialize(gammavariables* top, STD(string) name);
};

// SuN DSSD Threshold

class gammavDSSDThresh
{
 private:
  gammavariables* top;
  
 public:
  CTreeVariableArray hithresh;
  CTreeVariableArray lothresh;
  CTreeVariableArray duld;
  CTreeVariableArray loduld;

 public:
  void Initialize(gammavariables* top, STD(string) name);
};

// SuN Correlator
class gammavCorrelation 
{
 private: 
  gammavariables* top;
  
 public:
  CTreeVariable reset;
  CTreeVariable resetclock; // Reset 50MHz clock
  CTreeVariable minimplant;

 public:
  void Initialize(gammavariables* top, STD(string) name);
};

// SuN Hit Flags 
class gammavHitFlag 
{
 private:
  gammavariables* top;
  
 public:
  CTreeVariable fronthi;
  CTreeVariable fronthiover;
  CTreeVariable frontlo;
  CTreeVariable backhi;
  CTreeVariable backhiover;
  CTreeVariable backlo;
  CTreeVariable sun;

 public:
  void Initialize(gammavariables* top, STD(string) name);
};

// SuN Calibrator
class gammavSuNCalibrator
{
 private:
  gammavariables* top;

 public:
  CTreeVariableArray square;
  CTreeVariableArray slope;
  CTreeVariableArray intercept;
  CTreeVariableArray thresh;
  CTreeVariableArray uld;
  CTreeVariableArray pslope;
  CTreeVariableArray pintercept;
  CTreeVariable lotime;                     // Lower limit for the time window to look for a gamma ray in SuN after and implant or beta decay
  CTreeVariable hitime;                     // Upper limit for the time window to look for a gamma ray in SuN after an implantation or beta decay
  CTreeVariable tot_square;
  CTreeVariable tot_slope;
  CTreeVariable tot_intercept;

 public:
  void Initialize(gammavariables* top, STD(string) name);
};

// Waveform
class gammavWaveform
{
 private:
  gammavariables* top;

 public:
  CTreeVariable get;
  CTreeVariable crate;
  CTreeVariable module;
  CTreeVariable channel;
  CTreeVariable elo;
  CTreeVariable ehi;

 public:
  void Initialize(gammavariables* top, STD(string) name);

};

class gammavariables
{
 public:
  gammavClockCalibrator clock;
  gammavClockCalibrator clockisomer;
  gammavDSSDCalibrator front;
  gammavDSSDCalibrator back;
  gammavDSSDThresh fthresh;
  gammavDSSDThresh bthresh;
  gammavHitFlag hit;
  gammavCorrelation corr;
  //bdecayvPidCalibrator pid;
  gammavSuNCalibrator SuN;
  gammavWaveform waveform;

 public:
  gammavariables(STD(string) name);
};

