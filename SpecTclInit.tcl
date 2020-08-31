# SpecTclInit.tcl -- SpecTcl initialization file
# Last modified 2012/06/12
# Last modified 2005/01/09 by JPC
# Variables are initialized in bdecayV_standalone.h include file
# Set display memory for Xamine
# Last modified 2006/24/04 by JPC
set DisplayMegabytes 100

# Load Tcl utilities
source utils.tcl
source SuNInit.tcl
source SuN_DSSDInit.tcl

# Start variable initialization

# Set clock (Time) parameter
set bdecayv.clock.scale 1.0 

# Set for 1 ms per channel
set bdecayv.clock.calib 1.0

# Set for 2 ms per channel
#set bdecayv.clock.calib 0.16384
# Set for 5 ms per channel
#set bdecayv.clock.calib 0.065536
# Set for 10 ms per channel
#set bdecayv.clock.calib 0.032768

set bdecayv.clock.max 500.0
set bdecayv.corr.minimplant 1



# Isomer time parameters

# Set for 40 us maximum correlation
set bdecayv.clockisomer.max 200
# Set for 40 ns per channel
set bdecayv.clockisomer.calib 1.0


#Variables for SuN DSSD Correlator


# Set clock (Time) parameter
set gammav.clock.scale 1.0 
# Set for 1 ms per channel
set gammav.clock.calib 1.0

# Set for milliseconds
set gammav.clock.max 500.0
set gammav.corr.minimplant 1.0

# Set for 40 us maximum correlation
set gammav.clockisomer.max 200
# Set for 40 ns per channel
set gammav.clockisomer.calib 1.0

# Set PIN parameters 
set bdecayv.pin01.slope 1.0
set bdecayv.pin01.intercept 0.0
set bdecayv.pin01.thresh 90.0
set bdecayv.pin01.ithresh 2000.0
set bdecayv.pin01.iuld 30000.

set bdecayv.pin02.slope 1.0
set bdecayv.pin02.intercept 0.0
set bdecayv.pin02.thresh 90.0 
set bdecayv.pin02.ithresh 2000.0
set bdecayv.pin02.iuld 30000.

set bdecayv.pin03.slope 1.0
set bdecayv.pin03.intercept 0.0
set bdecayv.pin03.thresh 90.0

set bdecayv.pin04.slope 1.0
set bdecayv.pin04.intercept 0.0
set bdecayv.pin04.thresh 90.0

# Set DSSD variables
source DSSDInit.tcl
source SSSDInit.tcl
source SeGAInit.tcl

# seed initialization
set bdecayv.seed.reset 0

#set varaible for trace extraction
set bdecayv.waveform.get 1
set bdecayv.waveform.crate 1
set bdecayv.waveform.module 6
set bdecayv.waveform.channel 3

#set LaBR3 variables
set bdecayv.labr3.slope.01 1.0
set bdecayv.labr3.slope.02 1.0

set bdecayv.labr3.intercept.01 0.0
set bdecayv.labr3.intercept.02 0.

#set DDAS variables
set bdecayv.ddas.ncrates 2
set bdecayv.ddas.nmodc.0 13
set bdecayv.ddas.nmodc.1  4
set bdecayv.ddas.nmodc.2  9
set bdecayv.ddas.channelpermod 16
set bdecayv.ddas.totmod 0

set bdecayv.ddas.evtbuilt 1
# This command is necessary to initialize the spectra!
#sbind -all
# end Initializing Spectra
