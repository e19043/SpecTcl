#DSSDInit.tcl -- DSSD initialization file
# SpecTcl source file: SpecTcl.cpp
# Last modified 2003/01/05 by ACM to start DSSD and SSSD 
# Strip numbering starts at 01 instead of 00

###### Set front decay ADC offsets (DSSD)
###### All ADC offsets are based on a 12-bit scale

# DSSD Front strips 

set bdecayv.front.hioffset.01 0.0
set bdecayv.front.hioffset.02 0.0
set bdecayv.front.hioffset.03 0.0
set bdecayv.front.hioffset.04 0.0
set bdecayv.front.hioffset.05 0.0
set bdecayv.front.hioffset.06 0.0
set bdecayv.front.hioffset.07 0.0
set bdecayv.front.hioffset.08 0.0
set bdecayv.front.hioffset.09 0.0
set bdecayv.front.hioffset.10 0.0
set bdecayv.front.hioffset.11 0.0
set bdecayv.front.hioffset.12 0.0
set bdecayv.front.hioffset.13 0.0
set bdecayv.front.hioffset.14 0.0
set bdecayv.front.hioffset.15 0.0
set bdecayv.front.hioffset.16 0.0
set bdecayv.front.hioffset.17 0.0
set bdecayv.front.hioffset.18 0.0
set bdecayv.front.hioffset.19 0.0
set bdecayv.front.hioffset.20 0.0
set bdecayv.front.hioffset.21 0.0
set bdecayv.front.hioffset.22 0.0
set bdecayv.front.hioffset.23 0.0
set bdecayv.front.hioffset.24 0.0
set bdecayv.front.hioffset.25 0.0
set bdecayv.front.hioffset.26 0.0
set bdecayv.front.hioffset.27 0.0
set bdecayv.front.hioffset.28 0.0
set bdecayv.front.hioffset.29 0.0
set bdecayv.front.hioffset.30 0.0
set bdecayv.front.hioffset.31 0.0
set bdecayv.front.hioffset.32 0.0
set bdecayv.front.hioffset.33 0.0
set bdecayv.front.hioffset.34 0.0
set bdecayv.front.hioffset.35 0.0
set bdecayv.front.hioffset.36 0.0
set bdecayv.front.hioffset.37 0.0
set bdecayv.front.hioffset.38 0.0
set bdecayv.front.hioffset.39 0.0
set bdecayv.front.hioffset.40 0.0 

###### Set back decay ADC offsets
###### All ADC offsets are on a 12-bit scale

# DSSD1 Back strips

set bdecayv.back.hioffset.01 0.
set bdecayv.back.hioffset.02 0.
set bdecayv.back.hioffset.03 1.
set bdecayv.back.hioffset.04 0.
set bdecayv.back.hioffset.05 0.
set bdecayv.back.hioffset.06 0.
set bdecayv.back.hioffset.07 0.
set bdecayv.back.hioffset.08 0.
set bdecayv.back.hioffset.09 0.
set bdecayv.back.hioffset.10 0.
set bdecayv.back.hioffset.11 0.
set bdecayv.back.hioffset.12 0.
set bdecayv.back.hioffset.13 0.
set bdecayv.back.hioffset.14 0
set bdecayv.back.hioffset.15 0.
set bdecayv.back.hioffset.16 0.
set bdecayv.back.hioffset.17 0
set bdecayv.back.hioffset.18 0
set bdecayv.back.hioffset.19 0
set bdecayv.back.hioffset.20 0
set bdecayv.back.hioffset.21 0
set bdecayv.back.hioffset.22 0
set bdecayv.back.hioffset.23 0
set bdecayv.back.hioffset.24 0
set bdecayv.back.hioffset.25 0
set bdecayv.back.hioffset.26 0
set bdecayv.back.hioffset.27 0
set bdecayv.back.hioffset.28 0
set bdecayv.back.hioffset.29 0
set bdecayv.back.hioffset.30 0
set bdecayv.back.hioffset.31 0
set bdecayv.back.hioffset.32 0
set bdecayv.back.hioffset.33 0
set bdecayv.back.hioffset.34 0
set bdecayv.back.hioffset.35 0
set bdecayv.back.hioffset.36 0
set bdecayv.back.hioffset.37 0
set bdecayv.back.hioffset.38 0
set bdecayv.back.hioffset.39 0
set bdecayv.back.hioffset.40 0

###### Set front decay gains
###### All gains are based on peak positions on a 9-bit scale

# DSSD -- set lowest energy peak of 228Th to channel XXX

set bdecayv.front.hislope.01 [expr 123.0/(1054.000 - (${bdecayv.front.hioffset.01}))]
set bdecayv.front.hislope.02 [expr 123.0/(1394.000 - (${bdecayv.front.hioffset.02}))]
set bdecayv.front.hislope.03 [expr 123.0/(1386.00 - (${bdecayv.front.hioffset.03}))]
set bdecayv.front.hislope.04 [expr 123.0/(1462.000 - (${bdecayv.front.hioffset.04}))]
set bdecayv.front.hislope.05 [expr 123.0/(1186.00 - (${bdecayv.front.hioffset.05}))]
set bdecayv.front.hislope.06 [expr 123.0/(1162.000 - (${bdecayv.front.hioffset.06}))]
set bdecayv.front.hislope.07 [expr 123.0/(1094.000 - (${bdecayv.front.hioffset.07}))]
set bdecayv.front.hislope.08 [expr 123.0/(1002.000 - (${bdecayv.front.hioffset.08}))]
set bdecayv.front.hislope.09 [expr 123.0/(1238.000 - (${bdecayv.front.hioffset.09}))]
set bdecayv.front.hislope.10 [expr 123.0/(1038.000 - (${bdecayv.front.hioffset.10}))]
set bdecayv.front.hislope.11 [expr 123.0/(1330.00 - (${bdecayv.front.hioffset.11}))]
set bdecayv.front.hislope.12 [expr 123.0/(1126.000 - (${bdecayv.front.hioffset.12}))]
set bdecayv.front.hislope.13 [expr 123.0/(1334.000 - (${bdecayv.front.hioffset.13}))]
set bdecayv.front.hislope.14 [expr 123.0/(1206.000 - (${bdecayv.front.hioffset.14}))]
set bdecayv.front.hislope.15 [expr 123.0/(1334.000 - (${bdecayv.front.hioffset.15}))]
set bdecayv.front.hislope.16 [expr 123.0/(1158.000 - (${bdecayv.front.hioffset.16}))]
set bdecayv.front.hislope.17 [expr 3000.0/(2991.951 - (${bdecayv.front.hioffset.17}/8.0))]
set bdecayv.front.hislope.18 [expr 3000.0/(3045.760 - (${bdecayv.front.hioffset.18}/8.0))]
set bdecayv.front.hislope.19 [expr 3000.0/(2943.828 - (${bdecayv.front.hioffset.19}/8.0))]
set bdecayv.front.hislope.20 [expr 3000.0/(3268.400 - (${bdecayv.front.hioffset.20}/8.0))]
set bdecayv.front.hislope.21 [expr 3000.0/(3097.195 - (${bdecayv.front.hioffset.21}/8.0))]
set bdecayv.front.hislope.22 [expr 3000.0/(3050.000 - (${bdecayv.front.hioffset.22}/8.0))]
set bdecayv.front.hislope.23 [expr 3000.0/(3105.131 - (${bdecayv.front.hioffset.23}/8.0))]
set bdecayv.front.hislope.24 [expr 3000.0/(3095.880 - (${bdecayv.front.hioffset.24}/8.0))]
set bdecayv.front.hislope.25 [expr 3000.0/(3096.215 - (${bdecayv.front.hioffset.25}/8.0))]
set bdecayv.front.hislope.26 [expr 3000.0/(3008.422 - (${bdecayv.front.hioffset.26}/8.0))]
set bdecayv.front.hislope.27 [expr 3000.0/(3174.391 - (${bdecayv.front.hioffset.27}/8.0))]
set bdecayv.front.hislope.28 [expr 3000.0/(2961.366 - (${bdecayv.front.hioffset.28}/8.0))]
set bdecayv.front.hislope.29 [expr 3000.0/(3198.094 - (${bdecayv.front.hioffset.29}/8.0))]
set bdecayv.front.hislope.30 [expr 3000.0/(3318.292 - (${bdecayv.front.hioffset.30}/8.0))]
set bdecayv.front.hislope.31 [expr 3000.0/(3105.000 - (${bdecayv.front.hioffset.31}/8.0))]
set bdecayv.front.hislope.32 [expr 3000.0/(2947.600 - (${bdecayv.front.hioffset.32}/8.0))]
set bdecayv.front.hislope.33 [expr 3000.0/(3005.572 - (${bdecayv.front.hioffset.33}/8.0))]
set bdecayv.front.hislope.34 [expr 3000.0/(3201.376 - (${bdecayv.front.hioffset.34}/8.0))]
set bdecayv.front.hislope.35 [expr 3000.0/(3085.500 - (${bdecayv.front.hioffset.35}/8.0))]
set bdecayv.front.hislope.36 [expr 3000.0/(3202.128 - (${bdecayv.front.hioffset.36}/8.0))]
set bdecayv.front.hislope.37 [expr 3000.0/(3171.763 - (${bdecayv.front.hioffset.37}/8.0))]
set bdecayv.front.hislope.38 [expr 3000.0/(3129.325 - (${bdecayv.front.hioffset.38}/8.0))]
set bdecayv.front.hislope.39 [expr 3000.0/(2977.248 - (${bdecayv.front.hioffset.39}/8.0))]
set bdecayv.front.hislope.40 [expr 3000.0/(3244.251 - (${bdecayv.front.hioffset.40}/8.0))]1


set bdecayv.front.hislope.17 0
set bdecayv.front.hislope.18 0
set bdecayv.front.hislope.19 0
set bdecayv.front.hislope.20 0
set bdecayv.front.hislope.21 0
set bdecayv.front.hislope.22 0
set bdecayv.front.hislope.23 0
set bdecayv.front.hislope.24 0
set bdecayv.front.hislope.25 0
set bdecayv.front.hislope.26 0
set bdecayv.front.hislope.27 0
set bdecayv.front.hislope.28 0
set bdecayv.front.hislope.29 0
set bdecayv.front.hislope.30 0
set bdecayv.front.hislope.31 0
set bdecayv.front.hislope.32 0
set bdecayv.front.hislope.33 0
set bdecayv.front.hislope.34 0
set bdecayv.front.hislope.35 0
set bdecayv.front.hislope.36 0
set bdecayv.front.hislope.37 0
set bdecayv.front.hislope.38 0
set bdecayv.front.hislope.39 0
set bdecayv.front.hislope.40 0

###### Set back decay gains
###### All gains are based on peak positions on a 9-bit scale

# DSSD Back strip gains

set bdecayv.back.hislope.01 [expr 123.0/(1146.000 - (${bdecayv.back.hioffset.01}))]
set bdecayv.back.hislope.02 [expr 123.0/(1090.000 - (${bdecayv.back.hioffset.02}))]
set bdecayv.back.hislope.03 [expr 123.0/(942.000 - (${bdecayv.back.hioffset.03}))]
set bdecayv.back.hislope.04 [expr 123.0/(1438.000 - (${bdecayv.back.hioffset.04}))]
set bdecayv.back.hislope.05 [expr 123.0/(934.000 - (${bdecayv.back.hioffset.05}))]
set bdecayv.back.hislope.06 [expr 123.0/(1126.000 - (${bdecayv.back.hioffset.06}))]
set bdecayv.back.hislope.07 [expr 123.0/(1150.000 - (${bdecayv.back.hioffset.07}))]
set bdecayv.back.hislope.08 [expr 123.0/(1042.000 - (${bdecayv.back.hioffset.08}))]
set bdecayv.back.hislope.09 [expr 123.0/(1186.000 - (${bdecayv.back.hioffset.09}))]
set bdecayv.back.hislope.10 [expr 123.0/(1146.000 - (${bdecayv.back.hioffset.10}))]
set bdecayv.back.hislope.11 [expr 123.0/(982.0000 - (${bdecayv.back.hioffset.11}))]
set bdecayv.back.hislope.12 [expr 123.0/(1094.000 - (${bdecayv.back.hioffset.12}))]
set bdecayv.back.hislope.13 [expr 123.0/(1094.000 - (${bdecayv.back.hioffset.13}))]
set bdecayv.back.hislope.14 [expr 123.0/(1094.000 - (${bdecayv.back.hioffset.14}))]
set bdecayv.back.hislope.15 [expr 123.0/(1062.000 - (${bdecayv.back.hioffset.15}))]
set bdecayv.back.hislope.16 [expr 123.0/(1150.000 - (${bdecayv.back.hioffset.16}))]
#set bdecayv.back.hislope.17 [expr 3000.0/(3124.116 - (${bdecayv.back.hioffset.17}))]
#set bdecayv.back.hislope.18 [expr 3000.0/(3117.797 - (${bdecayv.back.hioffset.18}))]
#set bdecayv.back.hislope.19 [expr 3000.0/(3022.120 - (${bdecayv.back.hioffset.19}))]
#set bdecayv.back.hislope.20 [expr 3000.0/(3156.031 - (${bdecayv.back.hioffset.20}))]
#set bdecayv.back.hislope.21 [expr 3000.0/(3016.507 - (${bdecayv.back.hioffset.21}))]
#set bdecayv.back.hislope.22 [expr 3000.0/(2947.321 - (${bdecayv.back.hioffset.22}))]
#set bdecayv.back.hislope.23 [expr 3000.0/(3170.001 - (${bdecayv.back.hioffset.23}))]
#set bdecayv.back.hislope.24 [expr 3000.0/(3165.144 - (${bdecayv.back.hioffset.24}))]
#set bdecayv.back.hislope.25 [expr 3000.0/(2958.138 - (${bdecayv.back.hioffset.25}))]
#set bdecayv.back.hislope.26 [expr 3000.0/(3149.524 - (${bdecayv.back.hioffset.26}))]
#set bdecayv.back.hislope.27 [expr 3000.0/(3027.683 - (${bdecayv.back.hioffset.27}))]
#set bdecayv.back.hislope.28 [expr 3000.0/(2968.807 - (${bdecayv.back.hioffset.28}))]
#set bdecayv.back.hislope.29 [expr 3000.0/(3003.152 - (${bdecayv.back.hioffset.29}))]
#set bdecayv.back.hislope.30 [expr 3000.0/(2970.701 - (${bdecayv.back.hioffset.30}))]
#set bdecayv.back.hislope.31 [expr 3000.0/(2917.011 - (${bdecayv.back.hioffset.31}))]
#set bdecayv.back.hislope.32 [expr 3000.0/(3142.135 - (${bdecayv.back.hioffset.32}))]
#set bdecayv.back.hislope.33 [expr 3000.0/(3255.126 - (${bdecayv.back.hioffset.33}))]
#set bdecayv.back.hislope.34 [expr 3000.0/(2969.277 - (${bdecayv.back.hioffset.34}))]
#set bdecayv.back.hislope.35 [expr 3000.0/(3148.399 - (${bdecayv.back.hioffset.35}))]
#set bdecayv.back.hislope.36 [expr 3000.0/(3055.676 - (${bdecayv.back.hioffset.36}))]
#set bdecayv.back.hislope.37 [expr 3000.0/(3305.083 - (${bdecayv.back.hioffset.37}))]
#set bdecayv.back.hislope.38 [expr 3000.0/(2824.569 - (${bdecayv.back.hioffset.38}))]
#set bdecayv.back.hislope.39 [expr 3000.0/(2898.932 - (${bdecayv.back.hioffset.39}))]
#set bdecayv.back.hislope.40 [expr 3000.0/(3068.579 - (${bdecayv.back.hioffset.40}))]

set bdecayv.back.hislope.17 0
set bdecayv.back.hislope.18 0
set bdecayv.back.hislope.19 0
set bdecayv.back.hislope.20 0
set bdecayv.back.hislope.21 0
set bdecayv.back.hislope.22 0
set bdecayv.back.hislope.23 0
set bdecayv.back.hislope.24 0
set bdecayv.back.hislope.25 0
set bdecayv.back.hislope.26 0
set bdecayv.back.hislope.27 0
set bdecayv.back.hislope.28 0
set bdecayv.back.hislope.29 0
set bdecayv.back.hislope.30 0
set bdecayv.back.hislope.31 0
set bdecayv.back.hislope.32 0
set bdecayv.back.hislope.33 0
set bdecayv.back.hislope.34 0
set bdecayv.back.hislope.35 0
set bdecayv.back.hislope.36 0
set bdecayv.back.hislope.37 0
set bdecayv.back.hislope.38 0
set bdecayv.back.hislope.39 0
set bdecayv.back.hislope.40 0

###### Set front decay thresholds 
###### All thresholds are on a 12-bit scale

# DSSD Front strips
set bdecayv.fthresh.hithresh.01 500
set bdecayv.fthresh.hithresh.02 500
set bdecayv.fthresh.hithresh.03 500
set bdecayv.fthresh.hithresh.04 500
set bdecayv.fthresh.hithresh.05 500
set bdecayv.fthresh.hithresh.06 500
set bdecayv.fthresh.hithresh.07 500
set bdecayv.fthresh.hithresh.08 500
set bdecayv.fthresh.hithresh.09 500
set bdecayv.fthresh.hithresh.10 500
set bdecayv.fthresh.hithresh.11 500
set bdecayv.fthresh.hithresh.11 500
set bdecayv.fthresh.hithresh.12 500
set bdecayv.fthresh.hithresh.13 500
set bdecayv.fthresh.hithresh.14 500
set bdecayv.fthresh.hithresh.15 500
set bdecayv.fthresh.hithresh.16 500
set bdecayv.fthresh.hithresh.17 500
set bdecayv.fthresh.hithresh.18 500
set bdecayv.fthresh.hithresh.19 500
set bdecayv.fthresh.hithresh.20 500
set bdecayv.fthresh.hithresh.21 500
set bdecayv.fthresh.hithresh.22 500
set bdecayv.fthresh.hithresh.23 500
set bdecayv.fthresh.hithresh.24 500
set bdecayv.fthresh.hithresh.25 500
set bdecayv.fthresh.hithresh.26 500
set bdecayv.fthresh.hithresh.27 500
set bdecayv.fthresh.hithresh.28 500
set bdecayv.fthresh.hithresh.29 500
set bdecayv.fthresh.hithresh.30 500
set bdecayv.fthresh.hithresh.31 500
set bdecayv.fthresh.hithresh.32 500
set bdecayv.fthresh.hithresh.33 500
set bdecayv.fthresh.hithresh.34 500
set bdecayv.fthresh.hithresh.35 500
set bdecayv.fthresh.hithresh.36 500
set bdecayv.fthresh.hithresh.37 500
set bdecayv.fthresh.hithresh.38 500
set bdecayv.fthresh.hithresh.39 500
set bdecayv.fthresh.hithresh.40 500

###### Set back decay thresholds
###### All thresholds are on a 12-bit scale

set bdecayv.bthresh.hithresh.01 640
set bdecayv.bthresh.hithresh.02 640
set bdecayv.bthresh.hithresh.03 640
set bdecayv.bthresh.hithresh.04 640
set bdecayv.bthresh.hithresh.05 640
set bdecayv.bthresh.hithresh.06 640
set bdecayv.bthresh.hithresh.07 640
set bdecayv.bthresh.hithresh.08 640
set bdecayv.bthresh.hithresh.09 640
set bdecayv.bthresh.hithresh.10 640
set bdecayv.bthresh.hithresh.11 640
set bdecayv.bthresh.hithresh.12 640
set bdecayv.bthresh.hithresh.13 640
set bdecayv.bthresh.hithresh.14 640
set bdecayv.bthresh.hithresh.15 640
set bdecayv.bthresh.hithresh.16 640
set bdecayv.bthresh.hithresh.17 640
set bdecayv.bthresh.hithresh.18 640
set bdecayv.bthresh.hithresh.19 640
set bdecayv.bthresh.hithresh.20 640
set bdecayv.bthresh.hithresh.21 640
set bdecayv.bthresh.hithresh.22 640
set bdecayv.bthresh.hithresh.23 640
set bdecayv.bthresh.hithresh.24 640
set bdecayv.bthresh.hithresh.25 640
set bdecayv.bthresh.hithresh.26 640
set bdecayv.bthresh.hithresh.27 640
set bdecayv.bthresh.hithresh.28 640
set bdecayv.bthresh.hithresh.29 640
set bdecayv.bthresh.hithresh.30 640
set bdecayv.bthresh.hithresh.31 640
set bdecayv.bthresh.hithresh.32 640
set bdecayv.bthresh.hithresh.33 640
set bdecayv.bthresh.hithresh.34 640
set bdecayv.bthresh.hithresh.35 640
set bdecayv.bthresh.hithresh.36 640
set bdecayv.bthresh.hithresh.37 640
set bdecayv.bthresh.hithresh.38 640
set bdecayv.bthresh.hithresh.39 640
set bdecayv.bthresh.hithresh.40 640

###### Set front decay upper level threshold
###### All thresholds are in 12-bit scale

# DSSD1 (most upstream)

set bdecayv.fthresh.duld.01 16000.0
set bdecayv.fthresh.duld.02 16000.0
set bdecayv.fthresh.duld.03 16000.0
set bdecayv.fthresh.duld.04 16000.0
set bdecayv.fthresh.duld.05 16000.0
set bdecayv.fthresh.duld.06 16000.0
set bdecayv.fthresh.duld.07 16000.0
set bdecayv.fthresh.duld.08 16000.0
set bdecayv.fthresh.duld.09 16000.0
set bdecayv.fthresh.duld.10 16000.0
set bdecayv.fthresh.duld.11 16000.0
set bdecayv.fthresh.duld.12 16000.0
set bdecayv.fthresh.duld.13 16000.0
set bdecayv.fthresh.duld.14 16000.0
set bdecayv.fthresh.duld.15 16000.0
set bdecayv.fthresh.duld.16 16000.0
set bdecayv.fthresh.duld.17 16000.0
set bdecayv.fthresh.duld.18 16000.0
set bdecayv.fthresh.duld.19 16000.0
set bdecayv.fthresh.duld.20 16000.0
set bdecayv.fthresh.duld.21 16000.0
set bdecayv.fthresh.duld.22 16000.0
set bdecayv.fthresh.duld.23 16000.0
set bdecayv.fthresh.duld.24 16000.0
set bdecayv.fthresh.duld.25 16000.0
set bdecayv.fthresh.duld.26 16000.0
set bdecayv.fthresh.duld.27 16000.0
set bdecayv.fthresh.duld.28 16000.0
set bdecayv.fthresh.duld.29 16000.0
set bdecayv.fthresh.duld.30 16000.0
set bdecayv.fthresh.duld.31 16000.0
set bdecayv.fthresh.duld.32 16000.0
set bdecayv.fthresh.duld.33 16000.0
set bdecayv.fthresh.duld.34 16000.0
set bdecayv.fthresh.duld.35 16000.0
set bdecayv.fthresh.duld.36 16000.0
set bdecayv.fthresh.duld.37 16000.0
set bdecayv.fthresh.duld.38 16000.0
set bdecayv.fthresh.duld.39 16000.0
set bdecayv.fthresh.duld.40 16000.0

###### Set back decay upper level thresholds
###### All thresholds on 12-bit scale

set bdecayv.bthresh.duld.01 19000.0
set bdecayv.bthresh.duld.02 19000.0
set bdecayv.bthresh.duld.03 19000.0
set bdecayv.bthresh.duld.04 19000.0
set bdecayv.bthresh.duld.05 19000.0
set bdecayv.bthresh.duld.06 19000.0
set bdecayv.bthresh.duld.07 19000.0
set bdecayv.bthresh.duld.08 19000.0
set bdecayv.bthresh.duld.09 19000.0
set bdecayv.bthresh.duld.10 19000.0
set bdecayv.bthresh.duld.11 19000.0
set bdecayv.bthresh.duld.12 19000.0
set bdecayv.bthresh.duld.13 19000.0
set bdecayv.bthresh.duld.14 19000.0
set bdecayv.bthresh.duld.15 19000.0
set bdecayv.bthresh.duld.16 19000.0
set bdecayv.bthresh.duld.17 19000.0
set bdecayv.bthresh.duld.18 19000.0
set bdecayv.bthresh.duld.19 19000.0
set bdecayv.bthresh.duld.20 19000.0
set bdecayv.bthresh.duld.21 19000.0
set bdecayv.bthresh.duld.22 19000.0
set bdecayv.bthresh.duld.23 19000.0
set bdecayv.bthresh.duld.24 19000.0
set bdecayv.bthresh.duld.25 19000.0
set bdecayv.bthresh.duld.26 19000.0
set bdecayv.bthresh.duld.27 19000.0
set bdecayv.bthresh.duld.28 19000.0
set bdecayv.bthresh.duld.29 19000.0
set bdecayv.bthresh.duld.30 19000.0
set bdecayv.bthresh.duld.31 19000.0
set bdecayv.bthresh.duld.32 19000.0
set bdecayv.bthresh.duld.33 19000.0
set bdecayv.bthresh.duld.34 19000.0
set bdecayv.bthresh.duld.35 19000.0
set bdecayv.bthresh.duld.36 19000.0
set bdecayv.bthresh.duld.37 19000.0
set bdecayv.bthresh.duld.38 19000.0
set bdecayv.bthresh.duld.39 19000.0
set bdecayv.bthresh.duld.40 19000.0

###### Set front decay thresholds 
###### All thresholds are on a 12-bit scale

set bdecayv.fthresh.lothresh.01 5
set bdecayv.fthresh.lothresh.02 5
set bdecayv.fthresh.lothresh.03 5
set bdecayv.fthresh.lothresh.04 5
set bdecayv.fthresh.lothresh.05 5
set bdecayv.fthresh.lothresh.06 5
set bdecayv.fthresh.lothresh.07 5
set bdecayv.fthresh.lothresh.08 5
set bdecayv.fthresh.lothresh.09 5
set bdecayv.fthresh.lothresh.10 5
set bdecayv.fthresh.lothresh.11 5
set bdecayv.fthresh.lothresh.12 5
set bdecayv.fthresh.lothresh.13 5
set bdecayv.fthresh.lothresh.14 5
set bdecayv.fthresh.lothresh.15 5
set bdecayv.fthresh.lothresh.16 5
set bdecayv.fthresh.lothresh.17 5
set bdecayv.fthresh.lothresh.18 5
set bdecayv.fthresh.lothresh.19 0
set bdecayv.fthresh.lothresh.20 0
set bdecayv.fthresh.lothresh.21 0
set bdecayv.fthresh.lothresh.22 0
set bdecayv.fthresh.lothresh.23 0
set bdecayv.fthresh.lothresh.24 0
set bdecayv.fthresh.lothresh.25 0
set bdecayv.fthresh.lothresh.26 0
set bdecayv.fthresh.lothresh.27 0
set bdecayv.fthresh.lothresh.28 0
set bdecayv.fthresh.lothresh.29 0
set bdecayv.fthresh.lothresh.30 0
set bdecayv.fthresh.lothresh.31 0
set bdecayv.fthresh.lothresh.32 0
set bdecayv.fthresh.lothresh.33 0
set bdecayv.fthresh.lothresh.34 0
set bdecayv.fthresh.lothresh.35 0
set bdecayv.fthresh.lothresh.36 0
set bdecayv.fthresh.lothresh.37 0
set bdecayv.fthresh.lothresh.38 0
set bdecayv.fthresh.lothresh.39 0
set bdecayv.fthresh.lothresh.40 0

###### Set back decay thresholds
###### All thresholds are on a 12-bit scale

set bdecayv.bthresh.lothresh.01 5
set bdecayv.bthresh.lothresh.02 5
set bdecayv.bthresh.lothresh.03 5
set bdecayv.bthresh.lothresh.04 5
set bdecayv.bthresh.lothresh.05 5
set bdecayv.bthresh.lothresh.06 5
set bdecayv.bthresh.lothresh.07 5
set bdecayv.bthresh.lothresh.08 5
set bdecayv.bthresh.lothresh.09 5
set bdecayv.bthresh.lothresh.10 5
set bdecayv.bthresh.lothresh.11 5
set bdecayv.bthresh.lothresh.12 5
set bdecayv.bthresh.lothresh.13 5
set bdecayv.bthresh.lothresh.14 5
set bdecayv.bthresh.lothresh.15 5
set bdecayv.bthresh.lothresh.16 5
set bdecayv.bthresh.lothresh.17 5
set bdecayv.bthresh.lothresh.18 5
set bdecayv.bthresh.lothresh.19 0
set bdecayv.bthresh.lothresh.20 0
set bdecayv.bthresh.lothresh.21 0
set bdecayv.bthresh.lothresh.22 0
set bdecayv.bthresh.lothresh.23 0
set bdecayv.bthresh.lothresh.24 0
set bdecayv.bthresh.lothresh.25 0
set bdecayv.bthresh.lothresh.26 0
set bdecayv.bthresh.lothresh.27 0
set bdecayv.bthresh.lothresh.28 0
set bdecayv.bthresh.lothresh.29 0
set bdecayv.bthresh.lothresh.30 0
set bdecayv.bthresh.lothresh.31 0
set bdecayv.bthresh.lothresh.32 0
set bdecayv.bthresh.lothresh.33 0
set bdecayv.bthresh.lothresh.34 0
set bdecayv.bthresh.lothresh.35 0
set bdecayv.bthresh.lothresh.36 0
set bdecayv.bthresh.lothresh.37 0
set bdecayv.bthresh.lothresh.38 0
set bdecayv.bthresh.lothresh.39 0
set bdecayv.bthresh.lothresh.40 0

# set lo dulds

set bdecayv.fthresh.loduld.01 25000.0
set bdecayv.fthresh.loduld.02 25000.0
set bdecayv.fthresh.loduld.03 25000.0
set bdecayv.fthresh.loduld.04 25000.0
set bdecayv.fthresh.loduld.05 25000.0
set bdecayv.fthresh.loduld.06 25000.0
set bdecayv.fthresh.loduld.07 25000.0
set bdecayv.fthresh.loduld.08 25000.0
set bdecayv.fthresh.loduld.09 25000.0
set bdecayv.fthresh.loduld.10 25000.0
set bdecayv.fthresh.loduld.11 25000.0
set bdecayv.fthresh.loduld.12 25000.0
set bdecayv.fthresh.loduld.13 25000.0
set bdecayv.fthresh.loduld.14 25000.0
set bdecayv.fthresh.loduld.15 25000.0
set bdecayv.fthresh.loduld.16 25000.0

#set back lo dulds

set bdecayv.bthresh.loduld.01 25000.0
set bdecayv.bthresh.loduld.02 25000.0
set bdecayv.bthresh.loduld.03 25000.0
set bdecayv.bthresh.loduld.04 25000.0
set bdecayv.bthresh.loduld.05 25000.0
set bdecayv.bthresh.loduld.06 25000.0
set bdecayv.bthresh.loduld.07 25000.0
set bdecayv.bthresh.loduld.08 25000.0
set bdecayv.bthresh.loduld.09 25000.0
set bdecayv.bthresh.loduld.10 25000.0
set bdecayv.bthresh.loduld.11 25000.0
set bdecayv.bthresh.loduld.12 25000.0
set bdecayv.bthresh.loduld.13 25000.0
set bdecayv.bthresh.loduld.14 25000.0
set bdecayv.bthresh.loduld.15 25000.0
set bdecayv.bthresh.loduld.16 25000.0


# End variable initialization

