/*      File: Parameters.h
	Parameter definitions for the beta-decay setup
	Author: Colin Morton
	Date: September 2001
	Altered to C++ class structure from C struct structure
	July09 by HLC
	Added waveforms - SNL 8/27/10
*/

#ifndef __BDECAYPARAMETERS_H
#define __BDECAYPARAMETERS_H

#include <TreeParameter.h>

extern class betadecay bdecay;
extern class gammadecay gdecay;
extern class Nero nero;
// Bit registers 

// define the total number of modules in the system
#define TOTMOD 26

//define the number of channels in a module
#define CHANPERMOD 16

#ifdef HAVE_STD_NAMESPACE
using namespace std;
#endif


//////////////////////////////// NERO /////////////////////////////////
///////////////////////////////////////////////////////////////////////
//////////////////////////////// NERO /////////////////////////////////
///////////////////////////////////////////////////////////////////////
//////////////////////////////// NERO /////////////////////////////////
///////////////////////////////////////////////////////////////////////


/* The entire nero set-up */


class neroBit
{
 private:
  Nero* top;

 public:
  CTreeParameter multiplicity;
  CTreeParameter nodatamask;
  CTreeParameter quadAhitpattern;
  CTreeParameter quadBhitpattern;
  CTreeParameter quadChitpattern;
  CTreeParameter quadDhitpattern;  
  
 public:
  void Initialize(Nero* top, STD(string) name);
  //void Initialize();
  void Reset();
};

class Nero
{
 public:
  neroBit bit;
  CTreeParameter hit;
  CTreeParameterArray energy;
  CTreeParameterArray ecal;
  CTreeParameterArray time;
  CTreeParameterArray timecfd;
  CTreeParameterArray timelow;
  CTreeParameterArray timehigh;
  CTreeParameterArray tdiffBCS;
  CTreeParameterArray tdiffSUN;

 public:
  Nero(STD(string) name);
  void Reset();
};

class bdecayBit
{
 private:
  betadecay* top;

 public:
  CTreeParameter calhitmask;
  CTreeParameter corrmask;
  CTreeParameter bcsmask;
  //long calhitmask;
  //long corrmask;

 public:
  void Initialize(betadecay* top, STD(string) name);
  //void Initialize();
  void Reset();
};

/* Clock */
class bdecayClock
{
 private:
  betadecay *top;

 public:
  CTreeParameter fast;
  CTreeParameter slow;
  CTreeParameter cfd;
  CTreeParameter current;
  CTreeParameter initial;
  CTreeParameter dtCrate1Crate2;
  CTreeParameter dtCrate1Crate3;

  //double fast;
  //double slow;
  //double cfd;
  //double current;
  //double initial;
  

 public: 
  void Initialize(betadecay* top, STD(string) name);
  //void Initialize();
  void Reset();
};

/* TACs */
class bdecayTac
{
 private:
  betadecay *top;
  
 public:
  CTreeParameter pin01rf;
  CTreeParameter pin01I2N;
  CTreeParameter pin01I2S;
  CTreeParameter pin02I2N;
  CTreeParameter pin02I2S;
  CTreeParameter pin01I2Ncorr;
  CTreeParameter pin01I2Scorr;
  CTreeParameter pin02I2Ncorr;
  CTreeParameter pin02I2Scorr;
  CTreeParameter pin01xfp;
  CTreeParameter pin01xfptimecfd;
  CTreeParameter pin01xfptimelow;
  CTreeParameter pin01xfptimehigh;
  CTreeParameter pin02xfp;
  CTreeParameter pin02xfptimecfd;
  CTreeParameter pin02xfptimelow;
  CTreeParameter pin02xfptimehigh;
  CTreeParameter i2pos;
  CTreeParameter i2ntof;
  CTreeParameter i2ntoftimecfd;
  CTreeParameter i2ntoftimelow;
  CTreeParameter i2ntoftimehigh;
  CTreeParameter i2stof;
  CTreeParameter i2ncorr;
  CTreeParameter i2poscorr;
  CTreeParameter i2scorr;
  CTreeParameter i2ne;
  CTreeParameter i2se;
  CTreeParameter dt_pin01;

  double i2nt;
  double i2st;
  CTreeParameter i2posdigital;
 public:
  void Initialize(betadecay* top, STD(string) name);
  void Reset();
};

class bdecayChanID
{
 private:
  betadecay *top;

 public:
  CTreeParameter adc;
  CTreeParameter timehigh;
  CTreeParameter timelow;
  CTreeParameter timecfd;
  double time;
  CTreeParameter overflow;
  CTreeParameterArray esums;
  CTreeParameterArray qsums;

  // left for consistency but implementation will seriosu impact SpecTcl performance
  //  CTreeParameterArray trace;

 public:
  void Initialize(betadecay* top, STD(string) name);
  void Reset();
};

class bdecayRaw
{
 private:
  betadecay *top;
  
 public:
  bdecayChanID chanid[TOTMOD*CHANPERMOD];

  vector<int> chanidhit;

 public:
  void Initialize(betadecay* top, STD(string) name);
  void Reset();
};



/* PIN */
class bdecayPin
{
 private:
  betadecay* top;
  
 public:
  CTreeParameter energy;
  //CTreeParameter time;
  CTreeParameter ecal;
  CTreeParameter timecfd;
  CTreeParameter timelow;
  CTreeParameter timehigh;
  CTreeParameter dt_imf;
  CTreeParameter dt_pin01_pin02;

  double time;

 public:
  void Initialize(betadecay* top, STD(string) name);
  void Reset();
};

/* DSSD */
class bdecayDssd
{
 private:
  betadecay* top;
  
 public:
  vector<int> striphit;

  CTreeParameterArray hienergy;
  CTreeParameterArray hiecal;
  CTreeParameterArray hitimecfd;
  CTreeParameterArray hitimelow;
  CTreeParameterArray hitimehigh;
  CTreeParameterArray hieventtdc;
  CTreeParameterArray loenergy;
  CTreeParameterArray loecal;
  CTreeParameterArray lotimecfd;
  CTreeParameterArray lotimelow;
  CTreeParameterArray lotimehigh;
  CTreeParameter icent;
  CTreeParameter dcent;
  CTreeParameter imax;
  CTreeParameter imaxtimecfd;
  CTreeParameter imaxtimelow;
  CTreeParameter imaxtimehigh;
  CTreeParameter dmax;
  CTreeParameter dmaxtimecfd;
  CTreeParameter dmaxtimelow;
  CTreeParameter dmaxtimehigh;
  CTreeParameter dtdiff;
  CTreeParameter itdiff;
  CTreeParameter imaxch;
  CTreeParameter dmaxch;
  CTreeParameter imult;
  CTreeParameter dmult;
  CTreeParameter isum;
  CTreeParameter dsum;
  CTreeParameter dediff;
  CTreeParameter iediff;
  CTreeParameterArray stripsThresh;

 public:
  void Initialize(betadecay* top, STD(string) name);
  void Reset();
};

/* SSSD */
class bdecaySssd
{
 private:
  betadecay* top;
  
 public:
  CTreeParameterArray energy;
  CTreeParameterArray ecal;
  CTreeParameterArray time;
  CTreeParameter cent;
  CTreeParameter max;
  CTreeParameter maxch;
  CTreeParameter mult;
  CTreeParameter sum;

 public:
  void Initialize(betadecay* top, STD(string) name);
  void Reset();
};


/* Total */
class bdecayTotal
{
 private:
  betadecay* top;
  
 public:
  CTreeParameter dsum;
  CTreeParameter dmax;
  CTreeParameter isum;
  CTreeParameter imax;

 public:
  void Initialize(betadecay* top, STD(string) name);
  void Reset();
};

/* PID */
class bdecayPid
{
 private:
  betadecay* top;
  
 public:
  CTreeParameter de1;
  CTreeParameter de2;
  CTreeParameter de3;
  CTreeParameter rftof;
  CTreeParameter pin01rftof;
  CTreeParameter pin01xfptof;
  CTreeParameter pin02xfptof;
  CTreeParameter i2ntof;
  CTreeParameter i2stof;
  CTreeParameter isum;
  CTreeParameter imax;
  CTreeParameter bimax;
  CTreeParameter fimax;
  CTreeParameter bisum;
  CTreeParameter fisum;
  CTreeParameter sunbimax;
  CTreeParameter sunfimax;
  CTreeParameter sunbisum;
  CTreeParameter sunfisum;

 public:
  void Initialize(betadecay* top, STD(string) name);
  void Reset();
};

/* Correlator */
class bdecayCorr
{
 private:
  betadecay* top;
  
 public:
  CTreeParameter dtimplant;
  CTreeParameter itime;
  CTreeParameter ide1;
  CTreeParameter ide2;
  CTreeParameter ide3;
  CTreeParameter idescint;
  CTreeParameter iisum;
  CTreeParameter iimax;
  CTreeParameter itof;
  CTreeParameter gtimecal;
  CTreeParameter gtime;
  CTreeParameter gde1;
  CTreeParameter gde2;
  CTreeParameter gde3;
  CTreeParameter gisum;
  CTreeParameter gimax;
  CTreeParameter gtof;
  CTreeParameter dtimecal;
  CTreeParameter dtime;
  CTreeParameter dde1;
  CTreeParameter dde2;
  CTreeParameter dde3;
  CTreeParameter dneut;
  CTreeParameter ddescint;
  CTreeParameter disum;
  CTreeParameter dimax;
  CTreeParameter dbisum;
  CTreeParameter dfisum;
  CTreeParameter dtof;
  CTreeParameter flag;
  CTreeParameter mult;
  CTreeParameterArray dmult;
  CTreeParameterArray dmax;
  CTreeParameterArray dsum;

 public:
  void Initialize(betadecay* top, STD(string) name);
  void Reset();
};


/* DDAS diagnostics */
class bdecayDdasDiagnostics
{
 private:
  betadecay *top;

 public:
  CTreeParameter cmult;
  CTreeParameter eventlength;
  CTreeParameter adc01hit;
  CTreeParameter adc02hit;
  CTreeParameter adc03hit;
  CTreeParameter adc04hit;
  CTreeParameter adc05hit;
  CTreeParameter adc06hit;
  CTreeParameter adc07hit;
  CTreeParameter adc08hit;
  CTreeParameter adc09hit;
  CTreeParameter adc10hit;
  CTreeParameter adc11hit;
  CTreeParameter adc12hit;
  CTreeParameter adc13hit;
  CTreeParameter adc14hit;
  CTreeParameter adc15hit;
  CTreeParameter adc16hit;
  CTreeParameter adc17hit;
  CTreeParameter adc18hit;
  CTreeParameter adc19hit;
  CTreeParameter adc20hit;
  CTreeParameter front0116hihit;
  CTreeParameter front1732hihit;
  CTreeParameter front3348hihit;
  CTreeParameter front0116lohit;
  CTreeParameter front1732lohit;
  CTreeParameter front3348lohit;
  CTreeParameter back0116hihit;
  CTreeParameter back1732hihit;
  CTreeParameter back3348hihit;
  CTreeParameter back0116lohit;
  CTreeParameter back1732lohit;
  CTreeParameter back3348lohit;

 public:
  void Initialize(betadecay* top, STD(string) name);
  void Reset();

};


 
/* The entire beta-decay set-up */
class betadecay
{
 public:
  bdecayBit bit;
  bdecayClock clock;
  bdecayTac tac;
  bdecayRaw raw;
  //bdecayAdc adc;
  // bdecayTdc tdc;
  //bdecayTime time;
  bdecayPin pin01;
  bdecayPin pin02;
  bdecayPin pin03;
  bdecayPin scint;
  bdecayDssd front;
  bdecayDssd back;
  bdecaySssd sssd01;
  bdecayTotal total;
  bdecayPid pid;
  bdecayCorr corr;
  bdecayDdasDiagnostics ddasdiagnostics;
 
public:
  betadecay(STD(string) name);
  void Reset();
};

//////////////////////////////// SUN /////////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////// SUN /////////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////// SUN /////////////////////////////////
//////////////////////////////////////////////////////////////////////

class gammaBit
{
 private:
  gammadecay* top;

 public:
  CTreeParameter calhitmask;
  CTreeParameter corrmask;
  //long calhitmask;
  //long corrmask;

 public:
  void Initialize(gammadecay* top, STD(string) name);
  //void Initialize();
  void Reset();
};

/* SuN Clock */
class gammaClock
{
 private:
  gammadecay *top;

 public:
  CTreeParameter fast;
  CTreeParameter slow;
  CTreeParameter cfd;
  CTreeParameter current;
  CTreeParameter initial;

  //double fast;
  //double slow;
  //double cfd;
  //double current;
  //double initial;
  

 public: 
  void Initialize(gammadecay* top, STD(string) name);
  //void Initialize();
  void Reset();
};

/* SuN Veto */

class gammaVeto
{
 private:
  gammadecay* top;
  
 public:
  CTreeParameter energy;
  CTreeParameter timecfd;
  CTreeParameter timelow;
  CTreeParameter timehigh;
  CTreeParameter dt_dcf;
  CTreeParameter dt_imf;

 public:
  void Initialize(gammadecay* top, STD(string) name);
  void Reset();
};

/* SuN DSSD */
class gammaDssd
{
 private:
  gammadecay* top;
  
 public:
  vector<int> striphit;

  CTreeParameterArray hienergy;
  CTreeParameterArray hiecal;  
  CTreeParameterArray hitimecfd;
  CTreeParameterArray hitimelow;
  CTreeParameterArray hitimehigh;
  CTreeParameterArray hieventtdc;
  CTreeParameterArray loenergy;
  CTreeParameterArray loecal;
  CTreeParameterArray lotimecfd;
  CTreeParameterArray lotimelow;
  CTreeParameterArray lotimehigh;
  CTreeParameterArray lotimeinseconds;
  CTreeParameterArray hitimeinseconds;
  CTreeParameterArray dmaxarray;
  CTreeParameterArray dmaxcharray;
  CTreeParameter icent;
  CTreeParameter dcent;
  CTreeParameter imax;
  CTreeParameter imaxtimecfd;
  CTreeParameter imaxtimelow;
  CTreeParameter imaxtimehigh;
  CTreeParameter dmax;
  CTreeParameter dmaxtimecfd;
  CTreeParameter dmaxtimelow;
  CTreeParameter dmaxtimehigh;
  CTreeParameter dtdiff;
  CTreeParameter itdiff;
  CTreeParameter imaxch;
  CTreeParameter dmaxch;
  CTreeParameter imult;
  CTreeParameter dmult;
  CTreeParameter isum;
  CTreeParameter dsum;
  CTreeParameter dediff;
  CTreeParameter iediff;

 public:
  void Initialize(gammadecay* top, STD(string) name);
  void Reset();
};

/* SuN DSSD Total */
class gammaTotal
{
 private:
  gammadecay* top;
  
 public:
  CTreeParameter dsum;
  CTreeParameter dmax;
  CTreeParameter isum;
  CTreeParameter imax;

 public:
  void Initialize(gammadecay* top, STD(string) name);
  void Reset();
};

/* SuN */
class gammaSuN
{
 private:
  gammadecay* top;
  
 public:
  

  CTreeParameterArray timecfd;
  CTreeParameterArray timelow;
  CTreeParameterArray timehigh;
  CTreeParameterArray timeinseconds;
  CTreeParameterArray rpmt;       // Raw PMT
  //CTreeParameterArray rpmt1;       // Raw PMT
  CTreeParameterArray gmpmt;      // Gain Matched PMT
  CTreeParameterArray tpmt;       // Time of PMT
  CTreeParameterArray rseg;       // Raw Segment
  CTreeParameterArray cseg;      // Calibrated Segment
  CTreeParameterArray dtdcf;      // Time diff between SuN DSSD front decay and sun 
  CTreeParameterArray dtimf;      // Time diff between SuN DSSD front implant and sun 
  CTreeParameterArray dtNERO;      // Time diff between NERO and sun 
  CTreeParameterArray dtdBCS;      // Time diff between BCS DSSD front decay and sun 
  CTreeParameterArray dtiBCS;      // Time diff between BCS DSSD front implant and sun 
  CTreeParameter cseg_tot;

 public:
  void Initialize(gammadecay* top, STD(string) name);
  void Reset();
};

/* SuN Total */
class gammaSuNTotal
{
 private:
  gammadecay* top;
  
 public:
  CTreeParameter mult;
  CTreeParameter total;
  CTreeParameter total_cal;

 public:
  void Initialize(gammadecay* top, STD(string) name);
  void Reset();
};

/* waveform  */
class gdecayWaveform
{
 private:
  gammadecay *top;

 public:
  CTreeParameter waveform;
  CTreeParameter i2posTacPulseArea;
  CTreeParameter Pin1I2NTofTacPulseArea;
  CTreeParameter Pin1I2STofTacPulseArea;
  CTreeParameter Pin1RFTofTacPulseArea;
  CTreeParameter Pin1SuNTofTacPulseArea;


 public:
  void Initialize(gammadecay* top, STD(string) name);
  void Reset();
  double PulseArea(UInt_t temptrace[]);
  double GeDSSDPulseArea(UInt_t temptrace[]);
  double RejectTest(UInt_t temptrace[], UInt_t tsize);

};

class gammaCorr_sun
{
 private:
  gammadecay* top;
  
 public:
  CTreeParameter dtimplant;
  CTreeParameter itime;
  CTreeParameter ide1;
  CTreeParameter ide2;
  CTreeParameter ide3;
  CTreeParameter iisum;
  CTreeParameter iimax;
  CTreeParameter itof;
  CTreeParameter gtimecal;
  CTreeParameter gtime;
  CTreeParameter gde1;
  CTreeParameter gde2;
  CTreeParameter gde3;
  CTreeParameter gisum;
  CTreeParameter gimax;
  CTreeParameter gtof;
  CTreeParameter dtimecal;
  CTreeParameter dtime;
  CTreeParameter dde1;
  CTreeParameter dde2;
  CTreeParameter dde3;
  CTreeParameter disum;
  CTreeParameter dimax;
  CTreeParameter dfisum;
  CTreeParameter dbisum;
  CTreeParameter dtof;
  CTreeParameter flag;
  CTreeParameter mult;
  CTreeParameter dmult;
  CTreeParameterArray dmax;
  CTreeParameterArray dsum;

 public:
  void Initialize(gammadecay* top, STD(string) name);
  void Reset();
};



/* SuN set-up */
class gammadecay
{
public:
  gammaBit bit;
  gammaClock clock;
  //bdecayAdc adc;
  // bdecayTdc tdc;
  //bdecayTime time;
  gammaDssd front;
  gammaDssd back;
  gammaTotal total;
  gammaVeto veto;
  gammaSuN sun;
  gammaSuNTotal suntotal;  
  gdecayWaveform waveform;
  gammaCorr_sun corr;

 public:
  gammadecay(STD(string) name);
  void Reset();
};



#endif
