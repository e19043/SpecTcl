#include <tcl.h>

proc writeSSSD.tcl {runnum} {
	exec mkdir -p SSSDSpectra/run$runnum
	swrite -format ascii SSSDSpectra/run$runnum/SSSD-Ch01 SSSD-01\ Energy     
	swrite -format ascii SSSDSpectra/run$runnum/SSSD-Ch02 SSSD-02\ Energy
	swrite -format ascii SSSDSpectra/run$runnum/SSSD-Ch03 SSSD-03\ Energy
	swrite -format ascii SSSDSpectra/run$runnum/SSSD-Ch04 SSSD-04\ Energy
	swrite -format ascii SSSDSpectra/run$runnum/SSSD-Ch05 SSSD-05\ Energy
	swrite -format ascii SSSDSpectra/run$runnum/SSSD-Ch06 SSSD-06\ Energy
	swrite -format ascii SSSDSpectra/run$runnum/SSSD-Ch07 SSSD-07\ Energy
	swrite -format ascii SSSDSpectra/run$runnum/SSSD-Ch08 SSSD-08\ Energy
	swrite -format ascii SSSDSpectra/run$runnum/SSSD-Ch09 SSSD-09\ Energy
	swrite -format ascii SSSDSpectra/run$runnum/SSSD-Ch10 SSSD-10\ Energy
	swrite -format ascii SSSDSpectra/run$runnum/SSSD-Ch11 SSSD-11\ Energy
	swrite -format ascii SSSDSpectra/run$runnum/SSSD-Ch12 SSSD-12\ Energy
	swrite -format ascii SSSDSpectra/run$runnum/SSSD-Ch13 SSSD-13\ Energy
	swrite -format ascii SSSDSpectra/run$runnum/SSSD-Ch14 SSSD-14\ Energy
	swrite -format ascii SSSDSpectra/run$runnum/SSSD-Ch15 SSSD-15\ Energy
	swrite -format ascii SSSDSpectra/run$runnum/SSSD-Ch16 SSSD-16\ Energy
}
