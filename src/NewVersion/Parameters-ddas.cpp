/*
  File:  bdecayP.h
  This file creates the parameter tree structure and must be
  edited in parallel with bdecayParameters_standalone.h
*/

#ifdef HAVE_STD_NAMESPACE
using namespace std;
#endif

#include <stdio.h>
#include <config.h>
#include <Event.h>
#include <string>
#include <cmath>
#include "Parameters-ddas.h"

betadecay::betadecay(STD(string) name)
{
  bit.Initialize(this, name+".bit");
  clock.Initialize(this, name+".clock");
  tac.Initialize(this, name+".tac");
  raw.Initialize(this, name+".raw");
  pin01.Initialize(this, name+".pin01");
  pin02.Initialize(this, name+".pin02");
  pin03.Initialize(this, name+".pin03");
  scint.Initialize(this, name+".scint");
  front.Initialize(this, name+".front");
  back.Initialize(this, name+".back");
  sssd01.Initialize(this, name+".sssd01");
  total.Initialize(this, name+".total");
  pid.Initialize(this, name+".pid");
  corr.Initialize(this, name+".corr");
  ddasdiagnostics.Initialize(this, name+".ddasdiagnostics");
}

void betadecay::Reset()
{
  bit.Reset();
  clock.Reset();
  tac.Reset();
  raw.Reset();
  pin01.Reset();
  pin02.Reset();
  pin03.Reset();
  scint.Reset();
  front.Reset();
  back.Reset();
  sssd01.Reset();
  total.Reset();
  pid.Reset();
  corr.Reset();
  ddasdiagnostics.Reset();
}

void bdecayBit::Initialize(betadecay* treetop, STD(string) name)
//void bdecayBit::Initialize()
{
  top = treetop;
  calhitmask.Initialize(name+".calhitmask", 12);
  corrmask.Initialize(name+".corrmask", 16);
  bcsmask.Initialize(name+".bcsmask", 8);
  //calhitmask = 0;
  //corrmask = 0;
}

void bdecayBit::Reset()
{
  calhitmask.Reset();
  corrmask.Reset();
  bcsmask.Reset();
  //calhitmask = 0;
  //corrmask = 0
}

void bdecayClock::Initialize(betadecay* treetop, STD(string) name)
//void bdecayClock::Initialize()
{
  top = treetop;
  fast.Initialize(name+".fast", 32);
  slow.Initialize(name+".slow", 16);
  cfd.Initialize(name+".cfd", 32);
  current.Initialize(name+".current", 32);
  initial.Initialize(name+".initial", 32);
  dtCrate1Crate3.Initialize(name+".dtCrate1Crate3",32);
  dtCrate1Crate2.Initialize(name+".dtCrate1Crate2",32);
}

void bdecayClock::Reset()
{
  fast.Reset();
  slow.Reset();
  cfd.Reset();
  current.Reset();
  initial.Reset();
  dtCrate1Crate3.Reset();
  dtCrate1Crate2.Reset();
}

void bdecayTac::Initialize(betadecay* treetop, STD(string) name)
{
  pin01rf.Initialize(name+".pin01rf", 16);
  pin01I2N.Initialize(name+".pin01I2N", 16);
  pin01I2S.Initialize(name+".pin01I2S",16);
  pin02I2N.Initialize(name+".pin02I2N",16);
  pin02I2S.Initialize(name+".pin02I2S",16);
  pin01I2Ncorr.Initialize(name+".pin01I2Ncorr", 16);
  pin01I2Scorr.Initialize(name+".pin01I2Scorr",16);
  pin02I2Ncorr.Initialize(name+".pin02I2Ncorr",16);
  pin02I2Scorr.Initialize(name+".pin02I2Scorr",16);
  pin01xfp.Initialize(name+".pin01xfp",16);
  pin01xfptimecfd.Initialize(name+".pin01xfptimecfd", 32);
  pin01xfptimelow.Initialize(name+".pin01xfptimelow", 32);
  pin01xfptimehigh.Initialize(name+".pin01xfptimehigh", 32); 
  pin02xfp.Initialize(name+".pin02xfp",16);
  pin02xfptimecfd.Initialize(name+".pin02xfptimecfd", 32);
  pin02xfptimelow.Initialize(name+".pin02xfptimelow", 32);
  pin02xfptimehigh.Initialize(name+".pin02xfptimehigh", 32); 
  i2pos.Initialize(name+".i2pos", 16);
  i2poscorr.Initialize(name+".i2poscorr",16);
  i2ntof.Initialize(name+".i2ntof", 16);
  i2ntoftimecfd.Initialize(name+".i2ntoftimecfd", 16);
  i2ntoftimelow.Initialize(name+".i2ntoftimelow", 16);
  i2ntoftimehigh.Initialize(name+".i2ntoftimehigh", 16);
  i2stof.Initialize(name+".i2stof", 16);
  i2ncorr.Initialize(name+".i2ncorr", 16);
  i2scorr.Initialize(name+".i2scorr", 16);
  i2ne.Initialize(name+".i2ne", 16);
  i2se.Initialize(name+".i2se", 16);
  i2nt=0;
  i2st=0;
  i2posdigital.Initialize(name+".i2posdigital", 16);
  dt_pin01.Initialize(name+".dt_pin01", 16);
}
void bdecayTac::Reset()
{
  pin01rf.Reset();
  pin01I2N.Reset();
  pin01I2S.Reset();
  pin02I2N.Reset();
  pin02I2S.Reset();
  pin01I2Ncorr.Reset();
  pin01I2Scorr.Reset();
  pin02I2Ncorr.Reset();
  pin02I2Scorr.Reset();
  pin01xfp.Reset();
  pin01xfptimecfd.Reset();
  pin01xfptimelow.Reset();
  pin01xfptimehigh.Reset(); 
  pin02xfp.Reset();
  pin02xfptimecfd.Reset();
  pin02xfptimelow.Reset();
  pin02xfptimehigh.Reset(); 
  i2pos.Reset();
  i2poscorr.Reset();
  i2ntof.Reset();
  i2ntoftimecfd.Reset(); 
  i2ntoftimelow.Reset();
  i2ntoftimehigh.Reset();
  i2stof.Reset();
  i2ncorr.Reset();
  i2scorr.Reset();
  i2ne.Reset();
  i2se.Reset();
  i2nt=0;
  i2st=0;
  i2posdigital.Reset();
  dt_pin01.Reset(); 
}
void bdecayRaw::Initialize(betadecay* treetop, STD(string) name)
{
  top = treetop;
  for(int i=0; i<TOTMOD*CHANPERMOD; i++){
    Char_t detname[11];
    sprintf(detname,".chanid%03d",i);
    cout << "detname " << detname << endl;
    chanid[i].Initialize(top, name+detname);
  }
  
}

void bdecayRaw::Reset()
{
  cout << "reseting bdecayraw" << endl;

  for(int i=0; i<chanidhit.size(); i++){
    chanid[chanidhit[i]].Reset();
  }
  chanidhit.clear();
}


void bdecayChanID::Initialize(betadecay* treetop, STD(string) name)
{
  adc.Initialize(name+".adc",16);
  timehigh.Initialize(name+".timehigh", 32);
  timelow.Initialize(name+".timelow", 32);
  timecfd.Initialize(name+".timecfd", 32);
  //time.Initialize(name+".time", 32);
  time = 0;
  overflow.Initialize(name+".overflow",3);
}

void bdecayChanID::Reset()
{
  adc.Reset();
  timehigh.Reset();
  timelow.Reset();
  timecfd.Reset();
  time = 0;
  overflow.Reset();

}



void bdecayPin::Initialize(betadecay* treetop, STD(string) name)
{
  top = treetop;
  energy.Initialize(name+".energy", 16);
  //time.Initialize(name+".time", 32);
  ecal.Initialize(name+".ecal", 16);
  time = 0;
  timecfd.Initialize(name+".timecfd", 32);
  timelow.Initialize(name+".timelow", 32);
  timehigh.Initialize(name+".timehigh", 32); 
  dt_imf.Initialize(name+".dt_imf", 16); 
  dt_pin01_pin02.Initialize(name+".dt_pin01_pin02", 16);
}

void bdecayPin::Reset()
{
  energy.Reset();
  //time.Reset();
  ecal.Reset();
  time = 0;
  timecfd.Reset();
  timelow.Reset();
  timehigh.Reset();
  dt_imf.Reset();
  dt_pin01_pin02.Reset();
}


void bdecayDssd::Initialize(betadecay* treetop, STD(string) name)
{
  top = treetop;
  hienergy.Initialize(name+".hienergy", 16, 41, 0);
  hiecal.Initialize(name+".hiecal", 16, 41, 0);
  hitimecfd.Initialize(name+".hitimecfd", 32, 41, 0);
  hitimelow.Initialize(name+".hitimelow", 32, 41, 0);
  hitimehigh.Initialize(name+".hitimehigh", 32, 41, 0);
  hieventtdc.Initialize(name+".hieventtdc", 16, 41, 0);
  loenergy.Initialize(name+".loenergy", 16, 41, 0);
  loecal.Initialize(name+".loecal", 16, 41, 0);
  lotimecfd.Initialize(name+".lotimecfd", 32, 41, 0);
  lotimelow.Initialize(name+".lotimelow", 32, 41, 0);
  lotimehigh.Initialize(name+".lotimehigh", 32, 41, 0);  
  icent.Initialize(name+".icent", 6);
  dcent.Initialize(name+".dcent", 6);
  imax.Initialize(name+".imax", 16);
  imaxtimecfd.Initialize(name+".imaxtimecfd", 32);
  imaxtimelow.Initialize(name+".imaxtimelow", 32);
  imaxtimehigh.Initialize(name+".imaxtimehigh", 32);
  dmax.Initialize(name+".dmax", 16);
  dmaxtimecfd.Initialize(name+".dmaxtimecfd", 32);
  dmaxtimelow.Initialize(name+".dmaxtimelow", 32);
  dmaxtimehigh.Initialize(name+".dmaxtimehigh", 32);
  dtdiff.Initialize(name+".dtdiff", 32);
  itdiff.Initialize(name+".itdiff", 32);
  imaxch.Initialize(name+".imaxch", 6);
  dmaxch.Initialize(name+".dmaxch", 6);
  imult.Initialize(name+".imult", 6);
  dmult.Initialize(name+".dmult", 6);
  isum.Initialize(name+".isum", 13);
  dsum.Initialize(name+".dsum", 13);
  dediff.Initialize(name+".dediff", 7);
  iediff.Initialize(name+".iediff", 7);
  stripsThresh.Initialize(name+".stripsThresh", 6, 41, 0);
}

void bdecayDssd::Reset()
{

  hienergy.Reset();
  hiecal.Reset();
  hitimecfd.Reset();
  hitimelow.Reset();
  hitimehigh.Reset();
  hieventtdc.Reset();
  loenergy.Reset();
  loecal.Reset();
  lotimecfd.Reset();
  lotimelow.Reset();
  lotimehigh.Reset();
  icent.Reset();
  dcent.Reset();
  imax.Reset();
  imaxtimecfd.Reset();
  imaxtimelow.Reset();
  imaxtimehigh.Reset();
  dmax.Reset();
  dmaxtimecfd.Reset();
  dmaxtimelow.Reset();
  dmaxtimehigh.Reset();
  dtdiff.Reset(); 
  itdiff.Reset();
  imaxch.Reset();
  dmaxch.Reset();
  imult.Reset();
  dmult.Reset();
  isum.Reset();
  dsum.Reset();
  dediff.Reset();
  iediff.Reset();
  stripsThresh.Reset();

}

void bdecaySssd::Initialize(betadecay* treetop, STD(string) name)
{
  top = treetop;
  energy.Initialize(name+".energy", 12, 17, 0);
  ecal.Initialize(name+".ecal", 12, 17, 0);
  time.Initialize(name+".time", 32, 17, 0);
  cent.Initialize(name+".cent", 5);
  max.Initialize(name+".max", 12);
  maxch.Initialize(name+".maxch", 5);
  mult.Initialize(name+".mult", 5);
  sum.Initialize(name+".sum", 13);
}

void bdecaySssd::Reset()
{
  energy.Reset();
  ecal.Reset();
  time.Reset();
  cent.Reset();
  max.Reset();
  maxch.Reset();
  mult.Reset();
  sum.Reset();
  
}

void bdecayTotal::Initialize(betadecay* treetop, STD(string) name)
{
  top = treetop;
  dsum.Initialize(name+".dsum", 16);
  dmax.Initialize(name+".dmax", 16);
  isum.Initialize(name+".isum", 16);
  imax.Initialize(name+".imax", 16);
}

void bdecayTotal::Reset()
{
  dsum.Reset();
  dmax.Reset();
  isum.Reset();
  imax.Reset();
}

void bdecayPid::Initialize(betadecay* treetop, STD(string) name)
{
  top = treetop;
  de1.Initialize(name+".de1", 16);
  de2.Initialize(name+".de2", 16);
  de3.Initialize(name+".de3", 16);
  rftof.Initialize(name+".rftof", 16);
  pin01rftof.Initialize(name+".pin01rftof", 16);
  pin01xfptof.Initialize(name+".pin01xfptof",16);
  pin02xfptof.Initialize(name+".pin02xfptof",16);
  i2ntof.Initialize(name+".i2ntof", 16);
  i2stof.Initialize(name+".i2stof", 16);
  isum.Initialize(name+".isum", 13);
  imax.Initialize(name+".imax", 13);
  bisum.Initialize(name+".bisum", 16);
  bimax.Initialize(name+".bimax", 16);
  fisum.Initialize(name+".fisum", 16);
  fimax.Initialize(name+".fimax", 16);
  sunbisum.Initialize(name+".sunbisum", 16);
  sunbimax.Initialize(name+".sunbimax", 16);
  sunfisum.Initialize(name+".sunfisum", 16);
  sunfimax.Initialize(name+".sunfimax", 16);
  
}

void bdecayPid::Reset()
{
  de1.Reset();
  de2.Reset();
  de3.Reset();
  rftof.Reset();
  pin01rftof.Reset();
  pin01xfptof.Reset();
  pin02xfptof.Reset();
  i2ntof.Reset();
  i2stof.Reset();
  isum.Reset();
  imax.Reset();
  bisum.Reset();
  bimax.Reset();
  fisum.Reset();
  fimax.Reset();
  sunbisum.Reset(); 
  sunbimax.Reset();
  sunfisum.Reset();
  sunfimax.Reset();
}

void bdecayCorr::Initialize(betadecay* treetop, STD(string) name) 
{
  top = treetop;
  dtimplant.Initialize(name+".dtimplant", 16);
  itime.Initialize(name+".itime", 32);
  ide1.Initialize(name+".ide1", 16);
  ide2.Initialize(name+".ide2", 16);
  ide3.Initialize(name+".ide3", 16);
  idescint.Initialize(name+".idescint", 16);
  iisum.Initialize(name+".iisum", 13);
  iimax.Initialize(name+".iimax", 13);
  itof.Initialize(name+".itof", 16);
  gtimecal.Initialize(name+".gtimecal", 10);
  gtime.Initialize(name+".gtime", 32);
  gde1.Initialize(name+".gde1", 16);
  gde2.Initialize(name+".gde2", 16);
  gde3.Initialize(name+".gde3", 16);
  gisum.Initialize(name+".gisum", 13);
  gimax.Initialize(name+".gimax", 12);
  gtof.Initialize(name+".gtof", 16);
  dtimecal.Initialize(name+".dtimecal", 16);
  dtime.Initialize(name+".dtime", 32);
  dde1.Initialize(name+".dde1", 16);
  dde2.Initialize(name+".dde2", 16);
  dde3.Initialize(name+".dde3", 16);
  dneut.Initialize(name+".dneut", 16);
  ddescint.Initialize(name+".ddescint", 16);
  disum.Initialize(name+".disum", 13);
  dimax.Initialize(name+".dimax", 13);
  dbisum.Initialize(name+".dbisum", 13);
  dfisum.Initialize(name+".dfisum", 13);
  dtof.Initialize(name+".dtof", 16);
  flag.Initialize(name+".flag", 12);
  mult.Initialize(name+".mult", 12);
  dmult.Initialize(name+".dmult", 12, 4, 0);
  dmax.Initialize(name+".dmax", 12, 4, 0);
  dsum.Initialize(name+".dsum", 13, 4, 0);
}

void bdecayCorr::Reset()
{
  dtimplant.Reset();
  itime.Reset();
  ide1.Reset();
  ide2.Reset();
  ide3.Reset();
  idescint.Reset();
  iisum.Reset();
  iimax.Reset();
  itof.Reset();
  gtimecal.Reset();
  gtime.Reset();
  gde1.Reset();
  gde2.Reset();
  gde3.Reset();
  gisum.Reset();
  gimax.Reset();
  gtof.Reset();
  dtimecal.Reset();
  dtime.Reset();
  dde1.Reset();
  dde2.Reset();
  dde3.Reset();
  dneut.Reset();
  ddescint.Reset();
  disum.Reset();
  dimax.Reset();
  dbisum.Reset();
  dfisum.Reset();
  dtof.Reset();
  flag.Reset();
  mult.Reset();
  dmult.Reset();
  dmax.Reset();
  dsum.Reset();
}

///////////////////////////////// SUN /////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////// SUN /////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////// SUN /////////////////////////////////
///////////////////////////////////////////////////////////////////////


gammadecay::gammadecay(STD(string) name)
{
  bit.Initialize(this, name+".bit");
  clock.Initialize(this, name+".clock");
  //adc.Initialize(this, name+".adc");
  //tdc.Initialize(this, name+".tdc");
  //time.Initialize(this, name+".time");
  front.Initialize(this, name+".front");
  back.Initialize(this, name+".back");
  veto.Initialize(this, name+".veto");
  sun.Initialize(this, name+".sun");
  suntotal.Initialize(this,name+".suntotal");
  total.Initialize(this, name+".total");
  corr.Initialize(this, name+".corr");
}

void gammadecay::Reset()
{
  bit.Reset();
  clock.Reset();
  //adc.Reset();
  //tdc.Reset();
  //time.Reset();
  front.Reset();
  back.Reset();
  total.Reset();
  sun.Reset();
  veto.Reset();
  suntotal.Reset();
  corr.Reset();
}

void gammaBit::Initialize(gammadecay* treetop, STD(string) name)
//void bdecayBit::Initialize()
{
  top = treetop;
  calhitmask.Initialize(name+".calhitmask", 12);
  corrmask.Initialize(name+".corrmask", 16);
  //calhitmask = 0;
  //corrmask = 0;
}

void gammaBit::Reset()
{
  calhitmask.Reset();
  corrmask.Reset();
  //calhitmask = 0;
  //corrmask = 0
}

void gammaClock::Initialize(gammadecay* treetop, STD(string) name)
{
  top = treetop;
  fast.Initialize(name+".fast", 32);
  slow.Initialize(name+".slow", 16);
  cfd.Initialize(name+".cfd", 32);
  current.Initialize(name+".current", 32);
  initial.Initialize(name+".initial", 32);

  //fast = 0;
  //slow = 0;
  //cfd = 0;
  //current = 0;
  //initial = 0;
}

void gammaClock::Reset()
{
  fast.Reset();
  slow.Reset();
  cfd.Reset();
  current.Reset();
  initial.Reset();

  //fast = 0;
  //slow = 0;
  //cfd = 0;
  //current = 0;
  //initial = 0;
}


void gammaSuN::Initialize(gammadecay* treetop, STD(string) name) 
{
  top = treetop;
  timecfd.Initialize(name+".timecfd", 32, 24, 0); 
  timelow.Initialize(name+".timelow", 32, 24, 0);
  timehigh.Initialize(name+".timehigh", 32, 24, 0);
  timeinseconds.Initialize(name+".timeinseconds", 16, 24, 0);
  dtNERO.Initialize(name+".dtNERO", 20, 24, 0);
  dtdcf.Initialize(name+".dtdcf", 16, 24, 0);
  dtimf.Initialize(name+".dtimf", 16, 24, 0);
  dtdBCS.Initialize(name+".dtdBCS", 16, 24, 0);
  dtiBCS.Initialize(name+".dtiBCS", 16, 24, 0);
  rpmt.Initialize(name+".rpmt",16,24, 0);
  //rpmt1.Initialize(name+".rpmt1",16,24, 0);
  tpmt.Initialize(name+".tpmt", 16, 24, 0);
  gmpmt.Initialize(name+".gmpmt", 16, 24, 0);
  rseg.Initialize(name+".rseg", 16, 8, 0);
  cseg.Initialize(name+".cseg", 16, 8, 0);
  cseg_tot.Initialize(name+".cseg_tot", 16);
} 


void gammaSuN::Reset()
{
  timecfd.Reset();
  timelow.Reset();
  timehigh.Reset();
  timeinseconds.Reset();
  dtNERO.Reset();
  dtdcf.Reset();
  dtimf.Reset();
  dtdBCS.Reset();
  dtiBCS.Reset();
  rpmt.Reset();
  //rpmt1.Reset();
  tpmt.Reset();
  gmpmt.Reset();
  rseg.Reset();
  cseg.Reset();
  cseg_tot.Reset();
}

void gammaSuNTotal::Initialize(gammadecay* treetop, STD(string) name) 
{
  top = treetop;
  mult.Initialize(name+".mult", 12);
  total.Initialize(name+".total", 16);
  total_cal.Initialize(name+".total_cal", 16);
}


void gammaSuNTotal::Reset()
{
  mult.Reset();
  total.Reset();
  total_cal.Reset();
}
// Class for the SuN veto detector

void gammaVeto::Initialize(gammadecay* treetop, STD(string) name)
{
  top = treetop;
  energy.Initialize(name+".energy", 16);
  timecfd.Initialize(name+".timecfd", 32);
  timelow.Initialize(name+".timelow", 32);
  timehigh.Initialize(name+".timehigh", 32);  
  dt_dcf.Initialize(name+".dt_dcf", 16);
  dt_imf.Initialize(name+".dt_imf", 16);
}

void gammaVeto::Reset()
{
  energy.Reset();
  timecfd.Reset();
  timelow.Reset();
  timehigh.Reset();
  dt_dcf.Reset();
  dt_imf.Reset();
}

void gammaDssd::Initialize(gammadecay* treetop, STD(string) name)
{
  top = treetop;
  hienergy.Initialize(name+".hienergy", 16, 41, 0);
  hiecal.Initialize(name+".hiecal", 16, 41, 0);
  hitimecfd.Initialize(name+".hitimecfd", 32, 41, 0);
  hitimelow.Initialize(name+".hitimelow", 32, 41, 0);
  hitimehigh.Initialize(name+".hitimehigh", 32, 41, 0);
  hieventtdc.Initialize(name+".hieventtdc", 16, 41, 0);
  loenergy.Initialize(name+".loenergy", 16, 41, 0);
  loecal.Initialize(name+".loecal", 16, 41, 0);
  lotimecfd.Initialize(name+".lotimecfd", 32, 41, 0);
  lotimelow.Initialize(name+".lotimelow", 32, 41, 0);
  lotimehigh.Initialize(name+".lotimehigh", 32, 41, 0);  
  icent.Initialize(name+".icent", 6);
  dcent.Initialize(name+".dcent", 6);
  imax.Initialize(name+".imax", 16);
  imaxtimecfd.Initialize(name+".imaxtimecfd", 32);
  imaxtimelow.Initialize(name+".imaxtimelow", 32);
  imaxtimehigh.Initialize(name+".imaxtimehigh", 32);
  dmax.Initialize(name+".dmax", 16);
  dmaxarray.Initialize(name+".dmaxarray", 16, 4, 0);
  dmaxcharray.Initialize(name+".dmaxcharray", 16, 4, 0);
  dmaxtimecfd.Initialize(name+".dmaxtimecfd", 32);
  dmaxtimelow.Initialize(name+".dmaxtimelow", 32);
  dmaxtimehigh.Initialize(name+".dmaxtimehigh", 32);
  dtdiff.Initialize(name+".dtdiff", 32);
  itdiff.Initialize(name+".itdiff", 32);
  imaxch.Initialize(name+".imaxch", 6);
  dmaxch.Initialize(name+".dmaxch", 6);
  imult.Initialize(name+".imult", 6);
  dmult.Initialize(name+".dmult", 6);
  isum.Initialize(name+".isum", 13);
  dsum.Initialize(name+".dsum", 13);
  dediff.Initialize(name+".dediff", 7);
  iediff.Initialize(name+".iediff", 7);
}  

void gammaDssd::Reset()
{
  hienergy.Reset();
  hiecal.Reset();
  hitimecfd.Reset();
  hitimelow.Reset();
  hitimehigh.Reset();
  hieventtdc.Reset();
  loenergy.Reset();
  loecal.Reset();
  lotimecfd.Reset();
  lotimelow.Reset();
  lotimehigh.Reset();
  icent.Reset();
  dcent.Reset();
  imax.Reset();
  imaxtimecfd.Reset(); 
  imaxtimelow.Reset();
  imaxtimehigh.Reset();
  dmax.Reset();
  dmaxarray.Reset();
  dmaxcharray.Reset();
  dmaxtimecfd.Reset();
  dmaxtimelow.Reset();
  dmaxtimehigh.Reset();
  dtdiff.Reset();
  itdiff.Reset(); 
  imaxch.Reset();
  dmaxch.Reset();
  imult.Reset(); 
  dmult.Reset();
  isum.Reset(); 
  dsum.Reset();
  dediff.Reset();
  iediff.Reset();
}


void gammaTotal::Initialize(gammadecay* treetop, STD(string) name)
{
  top = treetop;
  dsum.Initialize(name+".dsum", 16);
  dmax.Initialize(name+".dmax", 16);
  isum.Initialize(name+".isum", 16);
  imax.Initialize(name+".imax", 16);
}

void gammaTotal::Reset()
{
  dsum.Reset();
  dmax.Reset();
  isum.Reset();
  imax.Reset();
}

void gammaCorr_sun::Initialize(gammadecay* treetop, STD(string) name) 
{
  top = treetop;
  dtimplant.Initialize(name+".dtimplant", 16);
  itime.Initialize(name+".itime", 32);
  ide1.Initialize(name+".ide1", 16);
  ide2.Initialize(name+".ide2", 16);
  ide3.Initialize(name+".ide3", 16);
  iisum.Initialize(name+".iisum", 13);
  iimax.Initialize(name+".iimax", 13);
  itof.Initialize(name+".itof", 16);
  gtimecal.Initialize(name+".gtimecal", 10);
  gtime.Initialize(name+".gtime", 32);
  gde1.Initialize(name+".gde1", 16);
  gde2.Initialize(name+".gde2", 16);
  gde3.Initialize(name+".gde3", 16);
  gisum.Initialize(name+".gisum", 13);
  gimax.Initialize(name+".gimax", 12);
  gtof.Initialize(name+".gtof", 16);
  dtimecal.Initialize(name+".dtimecal", 16);
  dtime.Initialize(name+".dtime", 32);
  dde1.Initialize(name+".dde1", 16);
  dde2.Initialize(name+".dde2", 16);
  dde3.Initialize(name+".dde3", 16);
  disum.Initialize(name+".disum", 13);
  dimax.Initialize(name+".dimax", 13);
  dbisum.Initialize(name+".dbisum", 13);
  dfisum.Initialize(name+".dfisum", 13);
  dtof.Initialize(name+".dtof", 16);
  flag.Initialize(name+".flag", 12);
  mult.Initialize(name+".mult", 12);
  dmult.Initialize(name+".dmult", 12);
  dmax.Initialize(name+".dmax", 12, 4, 0);
  dsum.Initialize(name+".dsum", 13, 4, 0);
}

void gammaCorr_sun::Reset()
{
  dtimplant.Reset();
  itime.Reset();
  ide1.Reset();
  ide2.Reset();
  ide3.Reset();
  iisum.Reset();
  iimax.Reset();
  itof.Reset();
  gtimecal.Reset();
  gtime.Reset();
  gde1.Reset();
  gde2.Reset();
  gde3.Reset();
  gisum.Reset();
  gimax.Reset();
  gtof.Reset();
  dtimecal.Reset();
  dtime.Reset();
  dde1.Reset();
  dde2.Reset();
  dde3.Reset();
  disum.Reset();
  dimax.Reset();
  dbisum.Reset();
  dfisum.Reset();
  dtof.Reset();
  flag.Reset();
  mult.Reset();
  dmult.Reset();
  dmax.Reset();
  dsum.Reset();
}





///////////////////////////////////////// DDAS DIAGNOSTICS /////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////// DDAS DIAGNOSTICS /////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////// DDAS DIAGNOSTICS /////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

void bdecayDdasDiagnostics::Initialize(betadecay* treetop, STD(string) name)
{
  top = treetop;
  cmult.Initialize(name+".cmult",9);
  eventlength.Initialize(name+".timelength",11);
  adc01hit.Initialize(name+".adc01hit", 16);
  adc02hit.Initialize(name+".adc02hit", 16);
  adc03hit.Initialize(name+".adc03hit", 16);
  adc04hit.Initialize(name+".adc04hit", 16);
  adc05hit.Initialize(name+".adc05hit", 16);
  adc06hit.Initialize(name+".adc06hit", 16);
  adc07hit.Initialize(name+".adc07hit", 16);
  adc08hit.Initialize(name+".adc08hit", 16);
  adc09hit.Initialize(name+".adc09hit", 16);
  adc10hit.Initialize(name+".adc10hit", 16);
  adc11hit.Initialize(name+".adc11hit", 16);
  adc12hit.Initialize(name+".adc12hit", 16);
  adc13hit.Initialize(name+".adc13hit", 16);
  adc14hit.Initialize(name+".adc14hit", 16);
  adc15hit.Initialize(name+".adc15hit", 16);
  adc16hit.Initialize(name+".adc16hit", 16);
  adc17hit.Initialize(name+".adc17hit", 16);
  adc18hit.Initialize(name+".adc18hit", 16);
  adc19hit.Initialize(name+".adc19hit", 16);
  adc20hit.Initialize(name+".adc20hit", 16);
  front0116hihit.Initialize(name+".front0116hihit",16); 
  front1732hihit.Initialize(name+".front1732hihit",16); 
  front3348hihit.Initialize(name+".front3348hihit",16); 
  front0116lohit.Initialize(name+".front0116lohit",16); 
  front1732lohit.Initialize(name+".front1732lohit",16); 
  front3348lohit.Initialize(name+".front3348lohit",16); 
  back0116hihit.Initialize(name+".back0116hihit",16); 
  back1732hihit.Initialize(name+".back1732hihit",16); 
  back3348hihit.Initialize(name+".back3348hihit",16); 
  back0116lohit.Initialize(name+".back0116lohit",16); 
  back1732lohit.Initialize(name+".back1732lohit",16); 
  back3348lohit.Initialize(name+".back3348lohit",16); 
} 

void bdecayDdasDiagnostics::Reset()
{
  cmult.Reset();
  eventlength.Reset();
  adc01hit.Reset();
  adc02hit.Reset();
  adc03hit.Reset();
  adc04hit.Reset();
  adc05hit.Reset();
  adc06hit.Reset();
  adc07hit.Reset();
  adc08hit.Reset();
  adc09hit.Reset();
  adc10hit.Reset();
  adc11hit.Reset();
  adc12hit.Reset();
  adc13hit.Reset();
  adc14hit.Reset();
  adc15hit.Reset();
  adc16hit.Reset();
  adc17hit.Reset();
  adc18hit.Reset();
  adc19hit.Reset();
  adc20hit.Reset();
  front0116hihit.Reset(); 
  front1732hihit.Reset();
  front3348hihit.Reset();
  front0116lohit.Reset();
  front1732lohit.Reset();
  front3348lohit.Reset();
  back0116hihit.Reset();  
  back1732hihit.Reset();
  back3348hihit.Reset();
  back0116lohit.Reset();
  back1732lohit.Reset();
  back3348lohit.Reset();
} 

/////////////////////////////////// NERO //////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/////////////////////////////////// NERO //////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/////////////////////////////////// NERO //////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

Nero::Nero(STD(string) name)
{
  bit.Initialize(this, name+".bit");
  hit.Initialize(name+".hit");
  energy.Initialize(name+".energy", 12, 61, 0);
  ecal.Initialize(name+".ecal", 12, 61, 0);
  time.Initialize(name+".time", 20, 61, 0);
  tdiffBCS.Initialize(name+".tdiffBCS", 20, 61, 0);
  tdiffSUN.Initialize(name+".tdiffSUN", 20, 61, 0); // SuN DSSD - NERO time difference
}

void Nero::Reset()
{
  bit.Reset();
  hit.Reset();
  energy.Reset();
  ecal.Reset();
  time.Reset();
  tdiffBCS.Reset();
  tdiffSUN.Reset();
}


void neroBit::Initialize(Nero* treetop, STD(string) name)
{
  top = treetop;
  multiplicity.Initialize(name+".multiplicity", 6);
  nodatamask.Initialize(name+".nodatamask", 16);
  quadAhitpattern.Initialize(name+".quadAhitpattern", 16);
  quadBhitpattern.Initialize(name+".quadBhitpattern", 16);
  quadChitpattern.Initialize(name+".quadChitpattern", 16);
  quadDhitpattern.Initialize(name+".quadDhitpattern", 16);
}

void neroBit::Reset()
{
  multiplicity.Reset();
  nodatamask.Reset();
  quadAhitpattern.Reset();
  quadBhitpattern.Reset();
  quadChitpattern.Reset();
  quadDhitpattern.Reset();
}


