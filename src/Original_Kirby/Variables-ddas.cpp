#ifdef HAVE_STD_NAMESPACE
using namespace std;
#endif

#include <config.h>
#include <Event.h>
#include <string>

#include "Variables-ddas.h"

betadecayvariables::betadecayvariables(STD(string) name)
{
  clock.Initialize(this, name+".clock");
  clockisomer.Initialize(this, name+".clockisomer");
  pin01.Initialize(this, name+".pin01");
  pin02.Initialize(this, name+".pin02");
  pin03.Initialize(this, name+".pin03");
  scint.Initialize(this, name+".scint");
  veto.Initialize(this, name+".veto");
  tac.Initialize(this, name+".tac");
  front.Initialize(this, name+".front");
  back.Initialize(this, name+".back");
  fthresh.Initialize(this, name+".fthresh");
  bthresh.Initialize(this, name+".bthresh");
  sssd01.Initialize(this, name+".sssd01");
  hit.Initialize(this, name+".hit");
  corr.Initialize(this, name+".corr");
  pid.Initialize(this, name+".pid");
  waveform.Initialize(this, name+".waveform");
  ddas.Initialize(this,name+".ddas");
}

void bdecayvClockCalibrator::Initialize(betadecayvariables* treetop, STD(string) name)
{
  top = treetop;
  calib.Initialize(name+".calib", 0.1952, "");
  scale.Initialize(name+".scale", 32768, "");
  max.Initialize(name+".max", 10, "");
  max_daughter.Initialize(name+".max_daughter", 10, "");
}

void bdecayvPinCalibrator::Initialize(betadecayvariables* treetop, STD(string) name)
{
  top = treetop;
  slope.Initialize(name+".slope", 1, "");
  intercept.Initialize(name+".intercept", 0, "");
  thresh.Initialize(name+".thresh", 0, "");
  ithresh.Initialize(name+".ithresh", 5000, "");
  iuld.Initialize(name+".iuld",30000,"");
}

void bdecayvTacCalibrator::Initialize(betadecayvariables* treetop, STD(string) name) 
{
  top = treetop;
  i2ncorr.Initialize(name+".i2ncorr", 1, "");
  i2scorr.Initialize(name+".i2scorr", 1, "");
  pin1corr.Initialize(name+".pin1corr", 1, "");
  i2sposcorr.Initialize(name+".i2sposcorr", 0, "");
  i2nposcorr.Initialize(name+".i2nposcorr", 0, "");
  pin1poscorr.Initialize(name+".pin1poscorr", 0, "");
}

void bdecayvDSSDCalibrator::Initialize(betadecayvariables* treetop, STD(string) name)
{
  top = treetop;
  hioffset.Initialize(name+".hioffset", 0, "", 41, 0);
  hislope.Initialize(name+".hislope", 1, "", 41, 0);
  loslope.Initialize(name+".loslope", 1, "", 41, 0);
}

void bdecayvDSSDThresh::Initialize(betadecayvariables* treetop, STD(string) name)
{
  top = treetop;
  hithresh.Initialize(name+".hithresh", 0, "", 41, 0);
  lothresh.Initialize(name+".lothresh", 0, "", 41, 0);
  duld.Initialize(name+".duld", 4095, "", 41, 0);
  loduld.Initialize(name+".loduld", 25000, "", 41, 0);
}

void bdecayvSSSDCalibrator::Initialize(betadecayvariables* treetop, STD(string) name)
{
  top = treetop;
  offset.Initialize(name+".offset", 0, "", 17, 0);
  slope.Initialize(name+".slope", 1, "", 17, 0);
  thresh.Initialize(name+".thresh", 0, "", 17, 0);
  uld.Initialize(name+".uld", 4095, "", 17, 0);
}

void bdecayvHitFlag::Initialize(betadecayvariables* treetop, STD(string) name)
{
  top = treetop;
  pin01.Initialize(name+".pin01", 0, "");
  pin02.Initialize(name+".pin02", 0, "");
  pin03.Initialize(name+".pin03", 0, "");
  scint.Initialize(name+".scint", 0, "");
  veto.Initialize(name+".veto", 0, "");
  sssd01.Initialize(name+".sssd01", 0, "");
  fronthi.Initialize(name+".fronthi", 0, "");
  fronthiover.Initialize(name+".fronthiover",0,"");
  frontlo.Initialize(name+".frontlo", 0, "");
  backhi.Initialize(name+".backhi", 0, "");
  backhiover.Initialize(name+".backhiover",0,"");
  backlo.Initialize(name+".backlo", 0, "");
  taci2ntof.Initialize(name+".taci2ntof", 0, "");
  taci2stof.Initialize(name+".taci2stof", 0, "");
  taci2pos.Initialize(name+".taci2pos", 0, "");
  tacpin01xfp.Initialize(name+".tacpin01xfp", 0, "");
  tacpin02xfp.Initialize(name+".tacpin02xfp", 0, "");

}  
void bdecayvCorrelation::Initialize(betadecayvariables* treetop, STD(string) name)
{
  top = treetop;
  reset.Initialize(name+".reset", 0, "");
  resetclock.Initialize(name+".resetclock", 0, "");
  minimplant.Initialize(name+".minimplant", 0, "");
}
void bdecayvPidCalibrator::Initialize(betadecayvariables* treetop, STD(string) name)
{
  top = treetop;
  de1_scale.Initialize(name+".de1_scale", 1, "");
  de1_offset.Initialize(name+".de1_offset", 0, "");
  de1_tof_corr.Initialize(name+".de1_tof_corr", 0, "");
  de1_tof_offset.Initialize(name+".de1_tof_offset", 0, "");
  de2_scale.Initialize(name+".de2_scale", 1, "");
  de2_offset.Initialize(name+".de2_offset", 0, "");
  de2_tof_corr.Initialize(name+".de2_tof_corr", 0, "");
  de2_tof_offset.Initialize(name+".de2_tof_offset", 0, "");
  de3_scale.Initialize(name+".de3_scale", 1, "");
  de3_offset.Initialize(name+".de3_offset", 0, "");
  de3_tof_corr.Initialize(name+".de3_tof_corr", 0, "");
  de3_tof_offset.Initialize(name+".de3_tof_offset", 0, "");
  isum_scale.Initialize(name+".isum_scale", 1, "");
  isum_offset.Initialize(name+".isum_offset", 0, "");
  isum_tof_corr.Initialize(name+".isum_tof_corr", 0, "");
  isum_tof_offset.Initialize(name+".isum_tof_offset", 0, "");
  imax_scale.Initialize(name+".imax_scale", 1, "");
  imax_offset.Initialize(name+".imax_offset", 0, "");
  imax_tof_corr.Initialize(name+".imax_tof_corr", 0, "");
  imax_tof_offset.Initialize(name+".imax_tof_offset", 0, "");
  fisumcorr.Initialize(name+".fisumcorr", 1, "");
  fimaxcorr.Initialize(name+".fimaxcorr", 1, "");
  bisumcorr.Initialize(name+".bisumcorr", 1, "");
  bimaxcorr.Initialize(name+".bimaxcorr", 1, "");
  i2posfisumcorr.Initialize(name+".i2posfisumcorr", 0, "");
  i2posfimaxcorr.Initialize(name+".i2posfimaxcorr", 0, "");
  i2posbisumcorr.Initialize(name+".i2posbisumcorr", 0, "");
  i2posbimaxcorr.Initialize(name+".i2posbimaxcorr", 0, "");
}


void bdecayvWaveform::Initialize(betadecayvariables *treetop,
				 STD(string) name)
{
  top = treetop;

  get.Initialize(name+".get", 0, "");
  crate.Initialize(name+".crate", 0, "");
  module.Initialize(name+".module", 0, "");
  channel.Initialize(name+".channel", 0, "");
  elo.Initialize(name+".elo",0,"");
  ehi.Initialize(name+".ehi",32768,"");
}

void bdecayvDDAS::Initialize(betadecayvariables *treetop,
			     STD(string) name)
{
  top = treetop;

  ncrates.Initialize(name+".ncrates", 0, "");
  nmodc.Initialize(name+".nmodc", 0, "", 5, 0);
  channelpermod.Initialize(name+".channelpermod", 0, "");
  totmod.Initialize(name+".totmod", 0, "");
  evtbuilt.Initialize(name+".evtbuilt",0,"");
}
 
/* NERO STARTS HERE */

nerovariables::nerovariables(STD(string) name)
{
  nerothres.Initialize(this, name+".nerothres");
  nerohit.Initialize(this, name+".nerohit");
}


void nerovHitFlag::Initialize(nerovariables* treetop, STD(string) name)
{
  top = treetop;
  neroover.Initialize(name+".neroover", 0, "");
  hit.Initialize(name+".hit", 0, "");
}  

void nerovThresh::Initialize(nerovariables* treetop, STD(string) name)
{
  top = treetop;
  lthres.Initialize(name+".lthres", 0, "", 61, 0);
  uthres.Initialize(name+".uthres", 65536, "", 61, 0);
}

/* SUN STARTS HERE */

gammavariables::gammavariables(STD(string) name)
{
  clock.Initialize(this, name+".clock");
  clockisomer.Initialize(this, name+".clockisomer");
  front.Initialize(this, name+".front");
  back.Initialize(this, name+".back");
  fthresh.Initialize(this, name+".fthresh");
  bthresh.Initialize(this, name+".bthresh");
  hit.Initialize(this, name+".hit");
  corr.Initialize(this, name+".corr");
  //pid.Initialize(this, name+".pid");
  SuN.Initialize(this, name+".SuN");
  waveform.Initialize(this, name+".waveform");
  //ddas.Initialize(this,name+".ddas");
}

void gammavClockCalibrator::Initialize(gammavariables* treetop, STD(string) name)
{
  top = treetop;
  calib.Initialize(name+".calib", 0.1952, "");
  scale.Initialize(name+".scale", 32768, "");
  max.Initialize(name+".max", 10, "");
  max_daughter.Initialize(name+".max_daughter", 10, "");
}

/*void gammavPinCalibrator::Initialize(gammavariables* treetop, STD(string) name)
{
  top = treetop;
  slope.Initialize(name+".slope", 1, "");
  intercept.Initialize(name+".intercept", 0, "");
  thresh.Initialize(name+".thresh", 0, "");
  ithresh.Initialize(name+".ithresh", 5000, "");
  iuld.Initialize(name+".iuld",30000,"");
  decorr.Initialize(name+".decorr",1,"");
}*/

void gammavDSSDCalibrator::Initialize(gammavariables* treetop, STD(string) name)
{
  top = treetop;
  hioffset.Initialize(name+".hioffset", 0, "", 41, 0);
  hislope.Initialize(name+".hislope", 1, "", 41, 0);
  loslope.Initialize(name+".loslope", 1, "", 41, 0);
}

void gammavDSSDThresh::Initialize(gammavariables* treetop, STD(string) name)
{
  top = treetop;
  hithresh.Initialize(name+".hithresh", 0, "", 41, 0);
  lothresh.Initialize(name+".lothresh", 0, "", 41, 0);
  duld.Initialize(name+".duld", 4095, "", 41, 0);
  loduld.Initialize(name+".loduld", 25000, "", 41, 0);
}


void gammavHitFlag::Initialize(gammavariables* treetop, STD(string) name)
{
  top = treetop;
  fronthi.Initialize(name+".fronthi", 0, "");
  fronthiover.Initialize(name+".fronthiover",0,"");
  frontlo.Initialize(name+".frontlo", 0, "");
  backhi.Initialize(name+".backhi", 0, "");
  backhiover.Initialize(name+".backhiover",0,"");
  backlo.Initialize(name+".backlo", 0, "");
  sun.Initialize(name+".sun", 0, "");
}  

void gammavCorrelation::Initialize(gammavariables* treetop, STD(string) name)
{
  top = treetop;
  reset.Initialize(name+".reset", 0, "");
  resetclock.Initialize(name+".resetclock", 0, "");
  minimplant.Initialize(name+".minimplant", 0, "");
}
 
void gammavSuNCalibrator::Initialize(gammavariables* treetop,
				       STD(string) name)
{
  top = treetop;
  square.Initialize(name+".square", 0, "", 8, 0);
  slope.Initialize(name+".slope", 1, "", 8, 0);
  intercept.Initialize(name+".intercept", 0, "", 8, 0);
  thresh.Initialize(name+".thresh", 0, "", 8, 0);
  uld.Initialize(name+".uld", 65536, "", 24, 0);
  lotime.Initialize(name+".lotime", 0, "");
  hitime.Initialize(name+".hitime", 8192, "");
  pslope.Initialize(name+".pslope", 1, "", 24, 0);
  pintercept.Initialize(name+".pintercept", 0, "", 24, 0);
  tot_square.Initialize(name+".tot_square", 0, "");
  tot_slope.Initialize(name+".tot_slope", 1, "");
  tot_intercept.Initialize(name+".tot_intercept", 0, "");
}

void gammavWaveform::Initialize(gammavariables *treetop,
				 STD(string) name)
{
  top = treetop;

  get.Initialize(name+".get", 0, "");
  crate.Initialize(name+".crate", 0, "");
  module.Initialize(name+".module", 0, "");
  channel.Initialize(name+".channel", 0, "");
  elo.Initialize(name+".elo",0,"");
  ehi.Initialize(name+".ehi",32768,"");
}

