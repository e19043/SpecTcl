#include <tcl.h>

proc writeDTcal.tcl {runnum} {
	exec mkdir -p DTcal/run$runnum
	swrite -format ascii DTcal/run$runnum/ele1a corr.dtimecali!ele1a_dec_sun
	swrite -format ascii DTcal/run$runnum/ele1b corr.dtimecali!ele1b_dec_sun
	swrite -format ascii DTcal/run$runnum/ele2a corr.dtimecali!ele2a_dec_sun
	swrite -format ascii DTcal/run$runnum/ele2b corr.dtimecali!ele2b_dec_sun
	swrite -format ascii DTcal/run$runnum/ele2c corr.dtimecali!ele2c_dec_sun
	swrite -format ascii DTcal/run$runnum/ele3a corr.dtimecali!ele3a_dec_sun
	swrite -format ascii DTcal/run$runnum/ele3b corr.dtimecali!ele3b_dec_sun
	swrite -format ascii DTcal/run$runnum/ele3c corr.dtimecali!ele3c_dec_sun
	swrite -format ascii DTcal/run$runnum/ele4b corr.dtimecali!ele4b_dec_sun
	swrite -format ascii DTcal/run$runnum/ele4c corr.dtimecali!ele4c_dec_sun
	swrite -format ascii DTcal/run$runnum/ele4d corr.dtimecali!ele4d_dec_sun
	swrite -format ascii DTcal/run$runnum/ele5b corr.dtimecali!ele5b_dec_sun
	swrite -format ascii DTcal/run$runnum/ele5c corr.dtimecali!ele5c_dec_sun
	swrite -format ascii DTcal/run$runnum/ele5d corr.dtimecali!ele5d_dec_sun
}
