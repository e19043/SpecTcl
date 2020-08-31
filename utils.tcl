##########################################
# dump all spectra defined into one file.
# However, it doesn't work for binary yet!
########################################## 
proc svall {fname} {
    set spectra [spectrum -list]
    set fd [open $fname w]
    foreach spectrum $spectra {
	set sname [lindex $spectrum 1]
	swrite -format ascii $fd $sname
    }
    close $fd
}

########################################
# read all spectra written in one file
#######################################
proc rdall {fname} {
    unbind -all
    set fd [open $fname r]
    while {![eof $fd]} {sread $fd}
    close $fd
}

########################################
# save 2D spectra to ascii file
########################################
proc sv2d {sname fname x y} {
    set fd [open $fname w]
    for { set i 0 } { $i < $x } { incr i } {
	for { set j 0 } { $j < $y } { incr j } {
	    set counts [channel -get $sname "$i $j"]
	    if {$counts > 0}  {puts $fd "$i $j $counts"}
	    flush $fd
	}   
    }   
}   


############################################



########################################
# save 1D spectra to ascii file
########################################
proc sv1d {sname fname} {
    set fd [open $fname w]
    for { set i 1 } { $i < 10000 } { incr i } {
	    set counts [channel -get $sname "$i"]
	    if {$counts > 0}  {puts $fd "$i $counts"}
	    flush $fd
	}   
    }



############################################
# projection to y axis for 2D histo        #
# pfm - 28dec2001                          #
# updated 28jan2002 by pfm                 #
############################################
proc projy {2dname x1 x2 1dname xtnt} {
    set fd [open $1dname w]
    swrite -format ascii $fd $1dname
    seek $fd -8 end
    for { set j 0 } { $j < $xtnt } { incr j } {
	set sum [expr 0]
        for { set i $x1 } { $i < $x2 } { incr i } {
	    set counts [channel -get $2dname "$i $j"]
	    set sum [expr {$sum + $counts}]
	}
	if {$sum > 0} {puts $fd "($j) $sum"}
	flush $fd
    }
    puts $fd "(-1) -1"
    close $fd
    set fd [open $1dname r]
    sread $fd
    close $fd
}

############################################
# projection to x axis for 2D histo        #
# pfm - 28dec2001                          #
# updated 28jan2002 by pfm                 #
############################################
proc projx {2dname y1 y2 1dname xtnt} {
    set fd [open $1dname w]
    swrite -format ascii $fd $1dname
    seek $fd -8 end
    for { set i 0 } { $i < $xtnt } { incr i } {
	set sum [expr 0]
        for { set j $y1 } { $j < $y2 } { incr j } {
	    set counts [channel -get $2dname "$i $j"]
	    set sum [expr {$sum + $counts}]
	}
	if {$sum > 0} {puts $fd "($i) $sum"}
	flush $fd
    }
    puts $fd "(-1) -1"
    close $fd
    set fd [open $1dname r]
    sread $fd
    close $fd
}
            
############################################
# Procedure for sorting multiple files
# fstart - run number to start with
# fstop - run number to stop with (inclusive)
#
# Written by M.Karny for experiment 01027, April 2003
# Modified for more general use by ACM, May 2003
# Modified to insert run number into analysis program, May29, 2003
############################################

proc bsort {dirname fstart fstop} {
    global RunState
    global bdecayv.corr.reset
    global bdecayv.runnum.run

# location of the event files 
	    
    set jj [expr $fstop - $fstart]
    for { set i  0} {$i <= $jj} {incr i} {
    set runnum [expr $fstart + $i]
    set fname $dirname
    append fname /run
    append fname $runnum /run
    append fname $runnum -4096.evt
    puts  -nonewline $fname
    set bdecayv.corr.reset 1
    set bdecayv.runnum.run $runnum
    attach -file $fname 
    start

# vwait  waits for variable to be set to 0 to proceed
    vwait RunState
    puts  "    SORTED"

    }
}


#######################################################
#  Procedure for saving channels 00-39 of the DSSD
#  Written May 2006 by J B Stoker 
#
#  Entry format saveall 
#    [detectorname]   -  identification number on detector
#    [side]           -  either F or B for Front or Back
#    [minchannel]     -  lowest channel number of loop (0 not needed for <10)
#                     ie type 0, 1, 9; not 00, 01, 09, etc.  
#    [maxchannel]     -  highest channel number of loop
#    [spectra]        -  name of spectra window without .# (ie front.hienergy)

#######################################################


proc saveall {detector side minchannel maxchannel spectra} {

    global hold
    set j $maxchannel
    for {set i $minchannel} {$i <= $j} {incr i} {
	if {$i < 10} {
	    set n $i
	    set fname $detector
	    append fname DSSD $side 0 $n .asc 
	    set spectranum $spectra
	    append spectranum .0 $n
	    set entry "swrite -format ascii $fname $spectranum"
	    puts "saved...$entry" 
	    uplevel 1 $entry
	   
	} else {
	    set n $i
	    set fname $detector
	    append fname DSSD $side $n .asc
	    set spectranum $spectra
	    append spectranum . $n
	    set entry "swrite -format ascii $fname $spectranum"
	    puts "saved...$entry"	   
	    uplevel 1 $entry	   
	}
#vwait until the file is saved
	after 1500
    }
}
    
#############################################################
#                                                           #
#   Procedure to read "good" cumulative spectra back for    #
#   Expt 08020   -   written 18 Mar 10                      #
#                                                           #
#############################################################

proc quickreade11503 {} {
    global RunState
    global bdecayv.corr.reset
    global bdecayv.runnum.run
    global bdecayv.sega.slope.11
    global bdecayv.sega.slope.13
    global bdecayv.sega.intercept.11
    global bdecayv.sega.intercept.13

    source SeGAInit.tcl

    set EVT "/events/e11503/complete"
    set RunList {0115-00 0115-01 0115-02 0115-03 0115-04 0116-00 0116-01 0116-02 0116-03 0116-04 0116-05}
    foreach RunNum $RunList {
        set entry $EVT
        append entry /run-
        append entry $RunNum .evt
        set bdecayv.corr.reset 1
        set bdecayv.runnum.run $RunNum
        puts -nonewline $entry
        attach -format ring -file $entry
        start
	
	#    vwait for next run
        vwait RunState
        puts "    SORTED"
    }
}


proc reade11503 {} {
    global RunState
    global bdecayv.corr.reset
    global bdecayv.runnum.run
    global bdecayv.sega.slope.11
    global bdecayv.sega.slope.13
    global bdecayv.sega.intercept.11
    global bdecayv.sega.intercept.13

    source SeGAInit.tcl

    set EVT "/events/e11503/complete"
    set RunList {0115-00 0115-01 0115-02 0115-03 0115-04 0116-00 0116-01 0116-02 0116-03 0116-04 0116-05 0117-00 0117-01 0117-02 0117-03 0117-04}
    foreach RunNum $RunList {
        set entry $EVT
        append entry /run-
        append entry $RunNum .evt
        set bdecayv.corr.reset 1
        set bdecayv.runnum.run $RunNum
        puts -nonewline $entry
        attach -format ring -file $entry
        start
	
	#    vwait for next run
        vwait RunState
        puts "    SORTED"
    }

    set bdecayv.sega.slope.11 0.139154
    set bdecayv.sega.intercept.11 -3.05993
    set EVT "/events/e11503/complete"
    set RunList {0118-00 0118-01 0118-02 0118-03 0118-04}
    foreach RunNum $RunList {
        set entry $EVT
        append entry /run-
        append entry $RunNum .evt
        set bdecayv.corr.reset 1
        set bdecayv.runnum.run $RunNum
        puts -nonewline $entry
        attach -format ring -file $entry
        start
	
	#    vwait for next run
        vwait RunState
        puts "    SORTED"
    }

    set bdecayv.sega.slope.13 0.134609
    set bdecayv.sega.intercept.13 -1.58078


    set EVT "/events/e11503/complete"
    set RunList {0119-00 0119-01 0119-02 0119-03 0119-04 0119-05 0120-00 0120-01 0120-02 0120-03 0120-04 0120-05 0120-06 0120-07 0120-08 0120-09 0121-00 0121-01 0121-02 0121-03 0121-04 0121-05 0123-00 0123-01 0123-02 0123-03}
    foreach RunNum $RunList {
        set entry $EVT
        append entry /run-
        append entry $RunNum .evt
        set bdecayv.corr.reset 1
        set bdecayv.runnum.run $RunNum
        puts -nonewline $entry
        attach -format ring -file $entry
        start
	
	#    vwait for next run
        vwait RunState
        puts "    SORTED"
    }










#    source SeGAInit-1.tcl

#    set EVT "/events/e11503/complete"
#    set RunList {0124-00 0124-01 0124-02 0124-03 0124-04 0126-00 0126-01 0126-02 0126-03 0127-00 0127-01 0127-02 0127-03}
 #   foreach RunNum $RunList {
  #      set entry $EVT
   #     append entry /run-
    #    append entry $RunNum .evt
     #   set bdecayv.corr.reset 1
      #  set bdecayv.runnum.run $RunNum
       # puts -nonewline $entry
#        attach -format ring -file $entry
 #       start
	
	#    vwait for next run
  #      vwait RunState
   #     puts "    SORTED"
	
   # }

}






proc readAll {runnum} {
    set begin [clock seconds]
    global RunState
    global bdecayv.corr.reset
    global bdecayv.runnum.run

    set EVT "/events/e17028/experiment/run$runnum/"
    set RunList [llength [glob ~/stagearea/experiment/run$runnum/*.evt]]
    set EVTList [list]
    for {set RunNum 0} {$RunNum < $RunList} {incr RunNum} {
#    foreach RunNum $RunList 
        set entry $EVT
        append entry run-$runnum
        if {$RunNum < 10} {
            append entry -0$RunNum .evt
        } else {
            append entry -$RunNum .evt
        }
    	set bdecayv.corr.reset 1
        set bdecayv.runnum.run $RunNum
        lappend EVTList $entry	
	#    vwait for next run
    }
    puts -nonewline $EVTList
    attach -format ring -pipe cat $EVTList
    start
    vwait RunState
    puts "    SORTED"
    set end [clock seconds]
    set dt [expr { $end - $begin }]
    puts -nonewline "Time to sort in seconds: "
    puts $dt

}

proc readAll_ft {runnum} {
    set begin [clock seconds]
    global RunState
    global bdecayv.corr.reset
    global bdecayv.runnum.run

    set EVT "/mnt/rawdata/e17028/experiment/run$runnum/"
    set RunList [llength [glob /mnt/rawdata/e17028/experiment/run$runnum/*.evt]]
    set EVTList [list]
    for {set RunNum 0} {$RunNum < $RunList} {incr RunNum} {
#    foreach RunNum $RunList 
        set entry $EVT
        append entry run-$runnum
        if {$RunNum < 10} {
            append entry -0$RunNum .evt
        } else {
            append entry -$RunNum .evt
        }
	    set bdecayv.corr.reset 1
        set bdecayv.runnum.run $RunNum
        lappend EVTList $entry	
	#    vwait for next run
    }
    puts -nonewline $EVTList
    attach -format ring -pipe cat $EVTList
    start
    vwait RunState
    puts "    SORTED"
    set end [clock seconds]
    set dt [expr { $end - $begin }]
    puts -nonewline "Time to sort in seconds: "
    puts $dt

}

proc readAll2 {runnum} {
    global RunState
    global bdecayv.corr.reset
    global bdecayv.runnum.run

    set EVT "/events/e17028/experiment/$runnum/"
    set RunList [lsort [glob ~/stagearea/experiment/$runnum/*.evt]]
    foreach RunNum $RunList {
        #set entry $EVT
        set entry $RunNum
        set bdecayv.corr.reset 1
        set bdecayv.runnum.run $RunNum
        puts -nonewline $entry
        attach -format ring -size 32778 -file $entry
        start
	
	#    vwait for next run
        vwait RunState
        puts "    SORTED"
    }

}

proc readAll3 {listfile} {
    global RunState
    global bdecayv.corr.reset
    global bdecayv.runnum.run

    set ListFile [open $listfile r]
    set RunNumList [read $ListFile]
    foreach runnum $RunNumList {
        set EVT "/events/e17028/experiment/$runnum/"
        set RunList [lsort [glob ~/stagearea/experiment/$runnum/*.evt]]
        foreach RunNum $RunList {
            set entry $RunNum
            set bdecayv.corr.reset 1
            set bdecayv.runnum.run $RunNum
            puts -nonewline $entry
            attach -format ring -size 32778 -file $entry
            start
	
	    #    vwait for next run
            vwait RunState
            puts " $RunNum   SORTED"
        }
    }

}

proc detachAll {} {
    for { set i 0 } { $i < 10 } { incr i } {
      detach
      vwait RunState
    }   
} 

proc readAll_NERO {} {
    set begin_all [clock seconds]
    for { set i 1045 } { $i < 1069 } { incr i } {
        readAll_ft $i
    }
    set end_all [clock seconds]
    set dt_all [expr { $end_all - $begin_all }]
    puts -nonewline [expr {$i - 1045}]
    puts " runs sorted"
    puts -nonewline "Time to sort ALL FILES in seconds: "
    puts $dt_all
}

proc readAll_SuN {{begin_runnum 2025} {end_runnum 2048}} {
    set begin_all [clock seconds]
    for { set i $begin_runnum } { $i < $end_runnum } { incr i } {
        readAll $i
    }
    set end_all [clock seconds]
    set dt_all [expr { $end_all - $begin_all }]
    puts -nonewline [expr {$i - $begin_runnum}]
    puts " runs sorted"
    puts -nonewline "Time to sort ALL FILES in seconds: "
    puts $dt_all
}

proc readAll_SuN_ft {{begin_runnum 2025} {end_runnum 2048}} {
    set begin_all [clock seconds]
    for { set i $begin_runnum } { $i < $end_runnum } { incr i } {
        readAll_ft $i
    }
    set end_all [clock seconds]
    set dt_all [expr { $end_all - $begin_all }]
    puts -nonewline [expr {$i - $begin_runnum}]
    puts " runs sorted"
    puts -nonewline "Time to sort ALL FILES in seconds: "
    puts $dt_all
}
