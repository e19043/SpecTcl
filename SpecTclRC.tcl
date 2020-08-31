#
#
#  Setup the standard scripted commandsin SpecTcl.
#
#

# if {[info globals SpecTclRCHasRun] eq ""}  
#    {
#     set SpecTclRCHasRun 1;
    

    lappend auto_path $SpecTclHome/TclLibs
    package require splash
    package require img::jpeg 
    
    
    
    tk appname SpecTcl
    
    puts -nonewline "Loading SpecTcl gui..."
    source $SpecTclHome/Script/gui.tcl
    puts "Done."
    
    puts -nonewline "Loading state I/O scripts..."
    source $SpecTclHome/Script/fileall.tcl
    puts "Done."
    
    puts -nonewline "Loading formatted listing scripts..."
    source $SpecTclHome/Script/listall.tcl
    puts "Done."
    
    puts -nonewline "Loading gate copy script procs..."
    source $SpecTclHome/Script/CopyGates.tcl
    puts "Done."
    
    puts -nonewline "Initializing SpecTcl..."
    source SpecTclInit.tcl
    puts "Done."
    
    puts -nonewline "Loading TKCon console..."
    source $SpecTclHome/Script/tkcon.tcl
    puts "Done."
    
    puts -nonewline "Loading SpecTcl GUI interface..."
    source $SpecTclHome/Script/SpecTclGui.tcl 
    puts "Done."
    
#    } 
    
    # Following line recovers buttons omitted in new version
    #pack .clearall .exit   -side top -fill x
    #.help
    #####
    # .help originally was after .exit, but I removed it 
    # because the Help button on the Spectcl Gui was not
    # functional -SAS 06-27-2012
    #####
    
    #######################################
    # Define procedure to attach to an online data source
    #######################################
    proc attonl {} {
        global SpecTclHome
        global RunState
        global bdecayv.corr.reset
        set bdecayv.corr.reset 1
        if $RunState stop
    
       #attach -ring \
    	#/usr/opt/daq/10.0/bin/ringselector --formatted --source=tcp://ddas \
    	#--sample=PHYSICS_EVENT
    
    #   attach -pipe \
    	#/usr/opt/daq/10.1/bin/ringselector --formatted --source=tcp://spdaq46.nscl.msu.edu/ddas \
    	#--sample=PHYSICS_EVENT
       attach -format ring -pipe \
    	/usr/opt/daq/10.2/bin/ringselector  --source=tcp://s2pc2/onering \
    	--sample=PHYSICS_EVENT
    
    #attach -pipe \
    	#/usr/opt/daq/10.0/bin/ringselector --formatted --source=tcp://ddasdaq4.nscl.msu.edu/ddas \
    	#--sample=PHYSICS_EVENT
    
    #    attach -pipe /usr/opt/daq/current/Bin/spectcldaq TCP://ddasdaq4.nscl.msu.edu:2602/ 
        after 100 start
    }
    
    #######################################
    # Define procedure to attach to an event file
    #######################################
    proc attfile {} {
        global SpecTclHome
        global RunState
        global bdecayv.corr.reset
        set bdecayv.corr.reset 1
        set fname [tk_getOpenFile -defaultextension ".evt" -initialdir "tcp://spdaq03/e14041/stagearea/complete" -title "Select listmode file:"]
        if {$fname != {} } {
    	if $RunState stop
    #	attach -file $fname
    	puts -nonewline "File name is ... $fname"
    	attach -file --formatted=ring $fname
    	#--formatted=ring  
    	#attach -format ring -file $fname
    	#attach -format ring -pipe \
    	/usr/opt/daq/10.2/bin/ringselector  --source=file://$fname \
    	--sample=PHYSICS_EVENT
    	after 100 start
        }
    }
    
    #######################################
    # Define procedure to calculate efficiency of SpecTcl
    #######################################
    set AnalysisEfficiency 0
    set LastSequence0 0
    set BuffersAnalyzed0 0
    set RunNumber0 -1
    
    proc newrun {} {
        global LastSequence
        global LastSequence0
        global BuffersAnalyzed
        puts "Start new run......"
        set BuffersAnalyzed 0
        puts "BuffersAnalyzed reset to 0"
        set LastSequence0 $LastSequence
        puts "Initial LastSequence remembered $LastSequence0"
    }                 
    
    proc Efficiency {} {
        ;# Will reschedule self to compute every second.
        global AnalysisEfficiency
        global LastSequence
        global LastSequence0
        global RunNumber BuffersAnalyzed
        global RunNumber0 BuffersAnalyzed0
    
        # Reset at beginning of run
        if { $RunNumber0 != $RunNumber } {
            set LastSequence0 $LastSequence
            set BuffersAnalyzed0 $BuffersAnalyzed
            set RunNumber0 $RunNumber
        }
        if {$LastSequence != $LastSequence0} {
            set eff [expr ($BuffersAnalyzed - $BuffersAnalyzed0) * 100.0 / ($LastSequence - $LastSequence0)]
            set AnalysisEfficiency [format "%5.1f" $eff]
        }
        after 1000 Efficiency
    }
    
    Efficiency
    
    # Create efficiency display frame
    
    frame .eff
    label .eff.head -text "Sampling Efficiency: "
    label .eff.tail -text "% "
    label .eff.val  -textvariable AnalysisEfficiency
    pack .eff.head .eff.val .eff.tail -side left
    
    # Display Data source 
#    frame .source
#    label .source.head -text "Source: "
#    label .source.val -textvariable DataSource
#    pack .source.head .source.val -side left
    
    # Display Run Number
#    frame .runno
#    label .runno.head -text "Run Number: "
#    label .runno.val -textvariable RunNumber
#    pack .runno.head .runno.val -side left
    
    # Create buffer display frame
    frame .buf
    label .buf.head -text "Analyzed Buffers: "
    label .buf.val -textvariable BuffersAnalyzed
    
    pack .buf.head .buf.val -side left
    
    # Create control buttons
#    button .attonl -text "Attach online" -command attonl
#    button .attfile -text "Attach to file" -command attfile
#    button .resetcount -text "Reset buffer count" -command "newrun"
#    button .resetarray -text "Reset correlator" -command "set bdecayv.corr.reset 1"
    
    # Pack control panel
#    pack .attonl .attfile .source .runno .buf .eff .resetcount .resetarray -fill x
    
    sbind -all
    
    puts -nonewline "Loading SpecTk Server..."
    #source /user/e08020/e08020/SpecTk/Server/Server.tcl 
    source Server.tcl
    puts "Done."
    
    
