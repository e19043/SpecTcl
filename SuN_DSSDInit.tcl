#DSSDInit.tcl -- DSSD initialization file
# SpecTcl source file: SpecTcl.cpp
# Last modified 2003/01/05 by ACM to start DSSD and SSSD 
# Strip numbering starts at 01 instead of 00

###### Set front decay ADC offsets (DSSD)
###### All ADC offsets are based on a 12-bit scale

# DSSD Front strips 

set gammav.front.hioffset.00 0.0
set gammav.front.hioffset.01 0.0
set gammav.front.hioffset.02 0.0
set gammav.front.hioffset.03 0.0
set gammav.front.hioffset.04 0.0
set gammav.front.hioffset.05 0.0
set gammav.front.hioffset.06 0.0
set gammav.front.hioffset.07 0.0
set gammav.front.hioffset.08 0.0
set gammav.front.hioffset.09 0.0
set gammav.front.hioffset.10 0.0
set gammav.front.hioffset.11 0.0
set gammav.front.hioffset.12 0.0
set gammav.front.hioffset.13 0.0
set gammav.front.hioffset.14 0.0
set gammav.front.hioffset.15 0.0
set gammav.front.hioffset.16 0.0
set gammav.front.hioffset.17 0.0
set gammav.front.hioffset.18 0.0
set gammav.front.hioffset.19 0.0
set gammav.front.hioffset.20 0.0
set gammav.front.hioffset.21 0.0
set gammav.front.hioffset.22 0.0
set gammav.front.hioffset.23 0.0
set gammav.front.hioffset.24 0.0
set gammav.front.hioffset.25 0.0
set gammav.front.hioffset.26 0.0
set gammav.front.hioffset.27 0.0
set gammav.front.hioffset.28 0.0
set gammav.front.hioffset.29 0.0
set gammav.front.hioffset.30 0.0
set gammav.front.hioffset.31 0.0
set gammav.front.hioffset.32 0.0
set gammav.front.hioffset.33 0.0
set gammav.front.hioffset.34 0.0
set gammav.front.hioffset.35 0.0
set gammav.front.hioffset.36 0.0
set gammav.front.hioffset.37 0.0
set gammav.front.hioffset.38 0.0
set gammav.front.hioffset.39 0.0 

###### Set back decay ADC offsets
###### All ADC offsets are on a 12-bit scale

# DSSD1 Back strips

set gammav.back.hioffset.00 0.
set gammav.back.hioffset.01 0.
set gammav.back.hioffset.02 1.
set gammav.back.hioffset.03 0.
set gammav.back.hioffset.04 0.
set gammav.back.hioffset.05 0.
set gammav.back.hioffset.06 0.
set gammav.back.hioffset.07 0.
set gammav.back.hioffset.08 0.
set gammav.back.hioffset.09 0.
set gammav.back.hioffset.10 0.
set gammav.back.hioffset.11 0.
set gammav.back.hioffset.12 0.
set gammav.back.hioffset.13 0
set gammav.back.hioffset.14 0.
set gammav.back.hioffset.15 0.
set gammav.back.hioffset.16 0
set gammav.back.hioffset.17 0
set gammav.back.hioffset.18 0
set gammav.back.hioffset.19 0
set gammav.back.hioffset.20 0
set gammav.back.hioffset.21 0
set gammav.back.hioffset.22 0
set gammav.back.hioffset.23 0
set gammav.back.hioffset.24 0
set gammav.back.hioffset.25 0
set gammav.back.hioffset.26 0
set gammav.back.hioffset.27 0
set gammav.back.hioffset.28 0
set gammav.back.hioffset.29 0
set gammav.back.hioffset.30 0
set gammav.back.hioffset.31 0
set gammav.back.hioffset.32 0
set gammav.back.hioffset.33 0
set gammav.back.hioffset.34 0
set gammav.back.hioffset.35 0
set gammav.back.hioffset.36 0
set gammav.back.hioffset.37 0
set gammav.back.hioffset.38 0
set gammav.back.hioffset.39 0

###### Set front decay gains
###### All gains are based on peak positions on a 9-bit scale

# DSSD -- set lowest energy peak of 228Th to channel XXX

set gammav.front.hislope.00 1
set gammav.front.hislope.01 1
set gammav.front.hislope.02 1
set gammav.front.hislope.03 1
set gammav.front.hislope.04 1
set gammav.front.hislope.05 1
set gammav.front.hislope.06 1
set gammav.front.hislope.07 1
set gammav.front.hislope.08 1
set gammav.front.hislope.09 1
set gammav.front.hislope.10 1
set gammav.front.hislope.11 1
set gammav.front.hislope.12 1
set gammav.front.hislope.13 1
set gammav.front.hislope.14 1
set gammav.front.hislope.15 1
#set gammav.front.hislope.17 [expr 3000.0/(2991.951 - (${gammav.front.hioffset.17}/8.0))]
#set gammav.front.hislope.18 [expr 3000.0/(3045.760 - (${gammav.front.hioffset.18}/8.0))]
#set gammav.front.hislope.19 [expr 3000.0/(2943.828 - (${gammav.front.hioffset.19}/8.0))]
#set gammav.front.hislope.20 [expr 3000.0/(3268.400 - (${gammav.front.hioffset.20}/8.0))]
#set gammav.front.hislope.21 [expr 3000.0/(3097.195 - (${gammav.front.hioffset.21}/8.0))]
#set gammav.front.hislope.22 [expr 3000.0/(3050.000 - (${gammav.front.hioffset.22}/8.0))]
#set gammav.front.hislope.23 [expr 3000.0/(3105.131 - (${gammav.front.hioffset.23}/8.0))]
#set gammav.front.hislope.24 [expr 3000.0/(3095.880 - (${gammav.front.hioffset.24}/8.0))]
#set gammav.front.hislope.25 [expr 3000.0/(3096.215 - (${gammav.front.hioffset.25}/8.0))]
#set gammav.front.hislope.26 [expr 3000.0/(3008.422 - (${gammav.front.hioffset.26}/8.0))]
#set gammav.front.hislope.27 [expr 3000.0/(3174.391 - (${gammav.front.hioffset.27}/8.0))]
#set gammav.front.hislope.28 [expr 3000.0/(2961.366 - (${gammav.front.hioffset.28}/8.0))]
#set gammav.front.hislope.29 [expr 3000.0/(3198.094 - (${gammav.front.hioffset.29}/8.0))]
#set gammav.front.hislope.30 [expr 3000.0/(3318.292 - (${gammav.front.hioffset.30}/8.0))]
#set gammav.front.hislope.31 [expr 3000.0/(3105.000 - (${gammav.front.hioffset.31}/8.0))]
#set gammav.front.hislope.32 [expr 3000.0/(2947.600 - (${gammav.front.hioffset.32}/8.0))]
#set gammav.front.hislope.33 [expr 3000.0/(3005.572 - (${gammav.front.hioffset.33}/8.0))]
#set gammav.front.hislope.34 [expr 3000.0/(3201.376 - (${gammav.front.hioffset.34}/8.0))]
#set gammav.front.hislope.35 [expr 3000.0/(3085.500 - (${gammav.front.hioffset.35}/8.0))]
#set gammav.front.hislope.36 [expr 3000.0/(3202.128 - (${gammav.front.hioffset.36}/8.0))]
#set gammav.front.hislope.37 [expr 3000.0/(3171.763 - (${gammav.front.hioffset.37}/8.0))]
#set gammav.front.hislope.38 [expr 3000.0/(3129.325 - (${gammav.front.hioffset.38}/8.0))]
#set gammav.front.hislope.39 [expr 3000.0/(2977.248 - (${gammav.front.hioffset.39}/8.0))]
#set gammav.front.hislope.40 [expr 3000.0/(3244.251 - (${gammav.front.hioffset.40}/8.0))]


set gammav.front.hislope.16 0
set gammav.front.hislope.17 0
set gammav.front.hislope.18 0
set gammav.front.hislope.19 0
set gammav.front.hislope.20 0
set gammav.front.hislope.21 0
set gammav.front.hislope.22 0
set gammav.front.hislope.23 0
set gammav.front.hislope.24 0
set gammav.front.hislope.25 0
set gammav.front.hislope.26 0
set gammav.front.hislope.27 0
set gammav.front.hislope.28 0
set gammav.front.hislope.29 0
set gammav.front.hislope.30 0
set gammav.front.hislope.31 0
set gammav.front.hislope.32 0
set gammav.front.hislope.33 0
set gammav.front.hislope.34 0
set gammav.front.hislope.35 0
set gammav.front.hislope.36 0
set gammav.front.hislope.37 0
set gammav.front.hislope.38 0
set gammav.front.hislope.39 0

###### Set back decay gains
###### All gains are based on peak positions on a 9-bit scale

# DSSD Back strip gains

set gammav.back.hislope.00 1
set gammav.back.hislope.01 1
set gammav.back.hislope.02 1
set gammav.back.hislope.03 1
set gammav.back.hislope.04 1
set gammav.back.hislope.05 1
set gammav.back.hislope.06 1
set gammav.back.hislope.07 1
set gammav.back.hislope.08 1
set gammav.back.hislope.09 1
set gammav.back.hislope.10 1
set gammav.back.hislope.11 1
set gammav.back.hislope.12 1
set gammav.back.hislope.13 1
set gammav.back.hislope.14 1
set gammav.back.hislope.15 1
#set gammav.back.hislope.17 [expr 3000.0/(3124.116 - (${gammav.back.hioffset.17}))]
#set gammav.back.hislope.18 [expr 3000.0/(3117.797 - (${gammav.back.hioffset.18}))]
#set gammav.back.hislope.19 [expr 3000.0/(3022.120 - (${gammav.back.hioffset.19}))]
#set gammav.back.hislope.20 [expr 3000.0/(3156.031 - (${gammav.back.hioffset.20}))]
#set gammav.back.hislope.21 [expr 3000.0/(3016.507 - (${gammav.back.hioffset.21}))]
#set gammav.back.hislope.22 [expr 3000.0/(2947.321 - (${gammav.back.hioffset.22}))]
#set gammav.back.hislope.23 [expr 3000.0/(3170.001 - (${gammav.back.hioffset.23}))]
#set gammav.back.hislope.24 [expr 3000.0/(3165.144 - (${gammav.back.hioffset.24}))]
#set gammav.back.hislope.25 [expr 3000.0/(2958.138 - (${gammav.back.hioffset.25}))]
#set gammav.back.hislope.26 [expr 3000.0/(3149.524 - (${gammav.back.hioffset.26}))]
#set gammav.back.hislope.27 [expr 3000.0/(3027.683 - (${gammav.back.hioffset.27}))]
#set gammav.back.hislope.28 [expr 3000.0/(2968.807 - (${gammav.back.hioffset.28}))]
#set gammav.back.hislope.29 [expr 3000.0/(3003.152 - (${gammav.back.hioffset.29}))]
#set gammav.back.hislope.30 [expr 3000.0/(2970.701 - (${gammav.back.hioffset.30}))]
#set gammav.back.hislope.31 [expr 3000.0/(2917.011 - (${gammav.back.hioffset.31}))]
#set gammav.back.hislope.32 [expr 3000.0/(3142.135 - (${gammav.back.hioffset.32}))]
#set gammav.back.hislope.33 [expr 3000.0/(3255.126 - (${gammav.back.hioffset.33}))]
#set gammav.back.hislope.34 [expr 3000.0/(2969.277 - (${gammav.back.hioffset.34}))]
#set gammav.back.hislope.35 [expr 3000.0/(3148.399 - (${gammav.back.hioffset.35}))]
#set gammav.back.hislope.36 [expr 3000.0/(3055.676 - (${gammav.back.hioffset.36}))]
#set gammav.back.hislope.37 [expr 3000.0/(3305.083 - (${gammav.back.hioffset.37}))]
#set gammav.back.hislope.38 [expr 3000.0/(2824.569 - (${gammav.back.hioffset.38}))]
#set gammav.back.hislope.39 [expr 3000.0/(2898.932 - (${gammav.back.hioffset.39}))]
#set gammav.back.hislope.40 [expr 3000.0/(3068.579 - (${gammav.back.hioffset.40}))]

set gammav.back.hislope.16 0
set gammav.back.hislope.17 0
set gammav.back.hislope.18 0
set gammav.back.hislope.19 0
set gammav.back.hislope.20 0
set gammav.back.hislope.21 0
set gammav.back.hislope.22 0
set gammav.back.hislope.23 0
set gammav.back.hislope.24 0
set gammav.back.hislope.25 0
set gammav.back.hislope.26 0
set gammav.back.hislope.27 0
set gammav.back.hislope.28 0
set gammav.back.hislope.29 0
set gammav.back.hislope.30 0
set gammav.back.hislope.31 0
set gammav.back.hislope.32 0
set gammav.back.hislope.33 0
set gammav.back.hislope.34 0
set gammav.back.hislope.35 0
set gammav.back.hislope.36 0
set gammav.back.hislope.37 0
set gammav.back.hislope.38 0
set gammav.back.hislope.39 0

###### Set front decay thresholds 
###### All thresholds are on a 12-bit scale

# DSSD Front strips
set gammav.fthresh.hithresh.00 0
set gammav.fthresh.hithresh.01 0
set gammav.fthresh.hithresh.02 0
set gammav.fthresh.hithresh.03 0
set gammav.fthresh.hithresh.04 0
set gammav.fthresh.hithresh.05 0
set gammav.fthresh.hithresh.06 0
set gammav.fthresh.hithresh.07 0
set gammav.fthresh.hithresh.08 0
set gammav.fthresh.hithresh.09 0
set gammav.fthresh.hithresh.10 0
set gammav.fthresh.hithresh.11 0
set gammav.fthresh.hithresh.12 0
set gammav.fthresh.hithresh.13 0
set gammav.fthresh.hithresh.14 0
set gammav.fthresh.hithresh.15 0
set gammav.fthresh.hithresh.16 0
set gammav.fthresh.hithresh.17 0
set gammav.fthresh.hithresh.18 0
set gammav.fthresh.hithresh.19 0
set gammav.fthresh.hithresh.20 0
set gammav.fthresh.hithresh.21 0
set gammav.fthresh.hithresh.22 0
set gammav.fthresh.hithresh.24 0
set gammav.fthresh.hithresh.25 1
set gammav.fthresh.hithresh.26 1
set gammav.fthresh.hithresh.27 1
set gammav.fthresh.hithresh.28 1
set gammav.fthresh.hithresh.29 1
set gammav.fthresh.hithresh.30 1
set gammav.fthresh.hithresh.31 1
set gammav.fthresh.hithresh.32 1
set gammav.fthresh.hithresh.33 1
set gammav.fthresh.hithresh.34 1
set gammav.fthresh.hithresh.35 1
set gammav.fthresh.hithresh.36 1
set gammav.fthresh.hithresh.37 1
set gammav.fthresh.hithresh.38 1
set gammav.fthresh.hithresh.39 1


###### Set back decay thresholds
###### All thresholds are on a 12-bit scale

set gammav.bthresh.hithresh.00 0
set gammav.bthresh.hithresh.01 0
set gammav.bthresh.hithresh.02 0
set gammav.bthresh.hithresh.03 0
set gammav.bthresh.hithresh.04 0
set gammav.bthresh.hithresh.05 0
set gammav.bthresh.hithresh.06 0
set gammav.bthresh.hithresh.07 0
set gammav.bthresh.hithresh.08 0
set gammav.bthresh.hithresh.09 0
set gammav.bthresh.hithresh.10 0
set gammav.bthresh.hithresh.11 0
set gammav.bthresh.hithresh.12 0
set gammav.bthresh.hithresh.13 0
set gammav.bthresh.hithresh.14 0
set gammav.bthresh.hithresh.15 0
set gammav.bthresh.hithresh.16 0
set gammav.bthresh.hithresh.17 0
set gammav.bthresh.hithresh.18 1
set gammav.bthresh.hithresh.19 1
set gammav.bthresh.hithresh.20 1
set gammav.bthresh.hithresh.21 1
set gammav.bthresh.hithresh.22 1
set gammav.bthresh.hithresh.23 1
set gammav.bthresh.hithresh.24 1
set gammav.bthresh.hithresh.25 1
set gammav.bthresh.hithresh.26 1
set gammav.bthresh.hithresh.27 1
set gammav.bthresh.hithresh.28 1
set gammav.bthresh.hithresh.29 1
set gammav.bthresh.hithresh.30 1
set gammav.bthresh.hithresh.31 1
set gammav.bthresh.hithresh.32 1
set gammav.bthresh.hithresh.33 1
set gammav.bthresh.hithresh.34 1
set gammav.bthresh.hithresh.35 1
set gammav.bthresh.hithresh.36 1
set gammav.bthresh.hithresh.37 1
set gammav.bthresh.hithresh.38 1
set gammav.bthresh.hithresh.39 1

###### Set front decay upper level threshold
###### All thresholds are in 12-bit scale

# DSSD1 (most upstream)

set gammav.fthresh.duld.00 30000.0
set gammav.fthresh.duld.01 30000.0
set gammav.fthresh.duld.02 30000.0
set gammav.fthresh.duld.03 30000.0
set gammav.fthresh.duld.04 30000.0
set gammav.fthresh.duld.05 30000.0
set gammav.fthresh.duld.06 30000.0
set gammav.fthresh.duld.07 30000.0
set gammav.fthresh.duld.08 30000.0
set gammav.fthresh.duld.09 30000.0
set gammav.fthresh.duld.10 30000.0
set gammav.fthresh.duld.11 30000.0
set gammav.fthresh.duld.12 30000.0
set gammav.fthresh.duld.13 30000.0
set gammav.fthresh.duld.14 30000.0
set gammav.fthresh.duld.15 30000.0
set gammav.fthresh.duld.16 30000.0
set gammav.fthresh.duld.17 30000.0
set gammav.fthresh.duld.18 30000.0
set gammav.fthresh.duld.19 30000.0
set gammav.fthresh.duld.20 30000.0
set gammav.fthresh.duld.21 30000.0
set gammav.fthresh.duld.22 30000.0
set gammav.fthresh.duld.23 30000.0
set gammav.fthresh.duld.24 30000.0
set gammav.fthresh.duld.25 30000.0
set gammav.fthresh.duld.26 30000.0
set gammav.fthresh.duld.27 30000.0
set gammav.fthresh.duld.28 30000.0
set gammav.fthresh.duld.29 30000.0
set gammav.fthresh.duld.30 30000.0
set gammav.fthresh.duld.31 30000.0
set gammav.fthresh.duld.32 30000.0
set gammav.fthresh.duld.33 30000.0
set gammav.fthresh.duld.34 30000.0
set gammav.fthresh.duld.35 30000.0
set gammav.fthresh.duld.36 30000.0
set gammav.fthresh.duld.37 30000.0
set gammav.fthresh.duld.38 30000.0
set gammav.fthresh.duld.39 3000.0

###### Set back decay upper level thresholds
###### All thresholds on 12-bit scale

set gammav.bthresh.duld.00 30000.0
set gammav.bthresh.duld.01 30000.0
set gammav.bthresh.duld.02 30000.0
set gammav.bthresh.duld.03 30000.0
set gammav.bthresh.duld.04 30000.0
set gammav.bthresh.duld.05 30000.0
set gammav.bthresh.duld.06 30000.0
set gammav.bthresh.duld.07 30000.0
set gammav.bthresh.duld.08 30000.0
set gammav.bthresh.duld.09 30000.0
set gammav.bthresh.duld.10 30000.0
set gammav.bthresh.duld.11 30000.0
set gammav.bthresh.duld.12 30000.0
set gammav.bthresh.duld.13 30000.0
set gammav.bthresh.duld.14 3000.0
set gammav.bthresh.duld.15 30000.0
set gammav.bthresh.duld.16 30000.0
set gammav.bthresh.duld.17 30000.0
set gammav.bthresh.duld.18 30000.0
set gammav.bthresh.duld.19 30000.0
set gammav.bthresh.duld.20 30000.0
set gammav.bthresh.duld.21 30000.0
set gammav.bthresh.duld.22 30000.0
set gammav.bthresh.duld.23 30000.0
set gammav.bthresh.duld.24 30000.0
set gammav.bthresh.duld.25 30000.0
set gammav.bthresh.duld.26 30000.0
set gammav.bthresh.duld.27 30000.0
set gammav.bthresh.duld.28 30000.0
set gammav.bthresh.duld.29 30000.0
set gammav.bthresh.duld.30 30000.0
set gammav.bthresh.duld.31 30000.0
set gammav.bthresh.duld.32 30000.0
set gammav.bthresh.duld.33 30000.0
set gammav.bthresh.duld.34 30000.0
set gammav.bthresh.duld.35 30000.0
set gammav.bthresh.duld.36 30000.0
set gammav.bthresh.duld.37 30000.0
set gammav.bthresh.duld.38 30000.0
set gammav.bthresh.duld.39 30000.0

###### Set front decay thresholds 
###### All thresholds are on a 12-bit scale

set gammav.fthresh.lothresh.00 1
set gammav.fthresh.lothresh.01 1
set gammav.fthresh.lothresh.02 1
set gammav.fthresh.lothresh.03 1
set gammav.fthresh.lothresh.04 1
set gammav.fthresh.lothresh.05 1
set gammav.fthresh.lothresh.06 1
set gammav.fthresh.lothresh.07 1
set gammav.fthresh.lothresh.08 1
set gammav.fthresh.lothresh.09 1
set gammav.fthresh.lothresh.10 1
set gammav.fthresh.lothresh.11 1
set gammav.fthresh.lothresh.12 1
set gammav.fthresh.lothresh.13 1
set gammav.fthresh.lothresh.14 1
set gammav.fthresh.lothresh.15 1
set gammav.fthresh.lothresh.16 1
set gammav.fthresh.lothresh.17 1
set gammav.fthresh.lothresh.18 0
set gammav.fthresh.lothresh.19 0
set gammav.fthresh.lothresh.20 0
set gammav.fthresh.lothresh.21 0
set gammav.fthresh.lothresh.22 0
set gammav.fthresh.lothresh.23 0
set gammav.fthresh.lothresh.24 0
set gammav.fthresh.lothresh.25 0
set gammav.fthresh.lothresh.26 0
set gammav.fthresh.lothresh.27 0
set gammav.fthresh.lothresh.28 0
set gammav.fthresh.lothresh.29 0
set gammav.fthresh.lothresh.30 0
set gammav.fthresh.lothresh.31 0
set gammav.fthresh.lothresh.32 0
set gammav.fthresh.lothresh.33 0
set gammav.fthresh.lothresh.34 0
set gammav.fthresh.lothresh.35 0
set gammav.fthresh.lothresh.36 0
set gammav.fthresh.lothresh.37 0
set gammav.fthresh.lothresh.38 0
set gammav.fthresh.lothresh.39 0

###### Set back decay thresholds
###### All thresholds are on a 12-bit scale

set gammav.bthresh.lothresh.00 1
set gammav.bthresh.lothresh.01 1
set gammav.bthresh.lothresh.02 1
set gammav.bthresh.lothresh.03 1
set gammav.bthresh.lothresh.04 1
set gammav.bthresh.lothresh.05 1
set gammav.bthresh.lothresh.06 1
set gammav.bthresh.lothresh.07 1
set gammav.bthresh.lothresh.08 1
set gammav.bthresh.lothresh.09 1
set gammav.bthresh.lothresh.10 1
set gammav.bthresh.lothresh.11 1
set gammav.bthresh.lothresh.12 1
set gammav.bthresh.lothresh.13 1
set gammav.bthresh.lothresh.14 1
set gammav.bthresh.lothresh.15 1
set gammav.bthresh.lothresh.16 1
set gammav.bthresh.lothresh.17 1
set gammav.bthresh.lothresh.18 0
set gammav.bthresh.lothresh.19 0
set gammav.bthresh.lothresh.20 0
set gammav.bthresh.lothresh.21 0
set gammav.bthresh.lothresh.22 0
set gammav.bthresh.lothresh.23 0
set gammav.bthresh.lothresh.24 0
set gammav.bthresh.lothresh.25 0
set gammav.bthresh.lothresh.26 0
set gammav.bthresh.lothresh.27 0
set gammav.bthresh.lothresh.28 0
set gammav.bthresh.lothresh.29 0
set gammav.bthresh.lothresh.30 0
set gammav.bthresh.lothresh.31 0
set gammav.bthresh.lothresh.32 0
set gammav.bthresh.lothresh.33 0
set gammav.bthresh.lothresh.34 0
set gammav.bthresh.lothresh.35 0
set gammav.bthresh.lothresh.36 0
set gammav.bthresh.lothresh.37 0
set gammav.bthresh.lothresh.38 0
set gammav.bthresh.lothresh.39 0

# set lo dulds

set gammav.fthresh.loduld.00 35000.0
set gammav.fthresh.loduld.01 35000.0
set gammav.fthresh.loduld.02 35000.0
set gammav.fthresh.loduld.03 35000.0
set gammav.fthresh.loduld.04 35000.0
set gammav.fthresh.loduld.05 35000.0
set gammav.fthresh.loduld.06 35000.0
set gammav.fthresh.loduld.07 35000.0
set gammav.fthresh.loduld.08 35000.0
set gammav.fthresh.loduld.09 35000.0
set gammav.fthresh.loduld.10 35000.0
set gammav.fthresh.loduld.11 35000.0
set gammav.fthresh.loduld.12 35000.0
set gammav.fthresh.loduld.13 35000.0
set gammav.fthresh.loduld.14 35000.0
set gammav.fthresh.loduld.15 35000.0

#set back lo dulds

set gammav.bthresh.loduld.00 35000.0
set gammav.bthresh.loduld.01 35000.0
set gammav.bthresh.loduld.02 35000.0
set gammav.bthresh.loduld.03 35000.0
set gammav.bthresh.loduld.04 35000.0
set gammav.bthresh.loduld.05 35000.0
set gammav.bthresh.loduld.06 35000.0
set gammav.bthresh.loduld.07 35000.0
set gammav.bthresh.loduld.08 35000.0
set gammav.bthresh.loduld.09 35000.0
set gammav.bthresh.loduld.10 35000.0
set gammav.bthresh.loduld.11 35000.0
set gammav.bthresh.loduld.12 35000.0
set gammav.bthresh.loduld.13 35000.0
set gammav.bthresh.loduld.14 35000.0
set gammav.bthresh.loduld.15 35000.0


# End variable initialization

