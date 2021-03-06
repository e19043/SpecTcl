#include <tcl.h>

proc writeDSSD.tcl {runnum} {
	exec mkdir -p SuNDSSDSpectra/run$runnum
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-FH-Ch01 Front\ High\ Raw\ ch01
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-FH-Ch02 Front\ High\ Raw\ ch02 
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-FH-Ch03 Front\ High\ Raw\ ch03
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-FH-Ch04 Front\ High\ Raw\ ch04
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-FH-Ch05 Front\ High\ Raw\ ch05
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-FH-Ch06 Front\ High\ Raw\ ch06
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-FH-Ch07 Front\ High\ Raw\ ch07
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-FH-Ch08 Front\ High\ Raw\ ch08
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-FH-Ch09 Front\ High\ Raw\ ch09
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-FH-Ch10 Front\ High\ Raw\ ch10
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-FH-Ch11 Front\ High\ Raw\ ch11
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-FH-Ch12 Front\ High\ Raw\ ch12
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-FH-Ch13 Front\ High\ Raw\ ch13
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-FH-Ch14 Front\ High\ Raw\ ch14  
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-FH-Ch15 Front\ High\ Raw\ ch15
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-FH-Ch16 Front\ High\ Raw\ ch16
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-FH-Ch17 Front\ High\ Raw\ ch17
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-FH-Ch18 Front\ High\ Raw\ ch18
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-FH-Ch19 Front\ High\ Raw\ ch19
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-FH-Ch20 Front\ High\ Raw\ ch20
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-FH-Ch21 Front\ High\ Raw\ ch21
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-FH-Ch22 Front\ High\ Raw\ ch22 
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-FH-Ch23 Front\ High\ Raw\ ch23
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-FH-Ch24 Front\ High\ Raw\ ch24
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-FH-Ch25 Front\ High\ Raw\ ch25
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-FH-Ch26 Front\ High\ Raw\ ch26
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-FH-Ch27 Front\ High\ Raw\ ch27
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-FH-Ch28 Front\ High\ Raw\ ch28
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-FH-Ch29 Front\ High\ Raw\ ch29
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-FH-Ch30 Front\ High\ Raw\ ch30
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-FH-Ch31 Front\ High\ Raw\ ch31
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-FH-Ch32 Front\ High\ Raw\ ch32
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-FH-Ch33 Front\ High\ Raw\ ch33
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-FH-Ch34 Front\ High\ Raw\ ch34
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-FH-Ch35 Front\ High\ Raw\ ch35
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-FH-Ch36 Front\ High\ Raw\ ch36
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-FH-Ch37 Front\ High\ Raw\ ch37
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-FH-Ch38 Front\ High\ Raw\ ch38
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-FH-Ch39 Front\ High\ Raw\ ch39
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-FH-Ch40 Front\ High\ Raw\ ch40
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-BH-Ch01 Back\ High\ Raw\ ch01
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-BH-Ch02 Back\ High\ Raw\ ch02 
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-BH-Ch03 Back\ High\ Raw\ ch03
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-BH-Ch04 Back\ High\ Raw\ ch04
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-BH-Ch05 Back\ High\ Raw\ ch05
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-BH-Ch06 Back\ High\ Raw\ ch06
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-BH-Ch07 Back\ High\ Raw\ ch07
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-BH-Ch08 Back\ High\ Raw\ ch08
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-BH-Ch09 Back\ High\ Raw\ ch09
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-BH-Ch10 Back\ High\ Raw\ ch10
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-BH-Ch11 Back\ High\ Raw\ ch11
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-BH-Ch12 Back\ High\ Raw\ ch12
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-BH-Ch13 Back\ High\ Raw\ ch13
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-BH-Ch14 Back\ High\ Raw\ ch14  
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-BH-Ch15 Back\ High\ Raw\ ch15
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-BH-Ch16 Back\ High\ Raw\ ch16
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-BH-Ch17 Back\ High\ Raw\ ch17
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-BH-Ch18 Back\ High\ Raw\ ch18
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-BH-Ch19 Back\ High\ Raw\ ch19
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-BH-Ch20 Back\ High\ Raw\ ch20
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-BH-Ch21 Back\ High\ Raw\ ch21
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-BH-Ch22 Back\ High\ Raw\ ch22 
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-BH-Ch23 Back\ High\ Raw\ ch23
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-BH-Ch24 Back\ High\ Raw\ ch24
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-BH-Ch25 Back\ High\ Raw\ ch25
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-BH-Ch26 Back\ High\ Raw\ ch26
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-BH-Ch27 Back\ High\ Raw\ ch27
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-BH-Ch28 Back\ High\ Raw\ ch28
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-BH-Ch29 Back\ High\ Raw\ ch29
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-BH-Ch30 Back\ High\ Raw\ ch30
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-BH-Ch31 Back\ High\ Raw\ ch31
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-BH-Ch32 Back\ High\ Raw\ ch32
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-BH-Ch33 Back\ High\ Raw\ ch33
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-BH-Ch34 Back\ High\ Raw\ ch34
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-BH-Ch35 Back\ High\ Raw\ ch35
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-BH-Ch36 Back\ High\ Raw\ ch36
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-BH-Ch37 Back\ High\ Raw\ ch37
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-BH-Ch38 Back\ High\ Raw\ ch38
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-BH-Ch39 Back\ High\ Raw\ ch39
	swrite -format ascii SuNDSSDSpectra/run$runnum/DSSD-BH-Ch40 Back\ High\ Raw\ ch40
}
