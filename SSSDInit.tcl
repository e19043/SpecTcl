###############################################################
#  SSSDInit.tcl -- SSSD initialization file
#  SpecTcl source file: 01016_bdecayspec.cpp
#  Last modified 2004/20/04 to change sssd offset, gain, thresh.
#  
#  All ADC offsets are based on a 12-bit scale
###############################################################

# SSSD01 #######################################################

# Set SSSD01 Offsets 
set bdecayv.sssd01.offset.01 0
set bdecayv.sssd01.offset.02 0
set bdecayv.sssd01.offset.03 0
set bdecayv.sssd01.offset.04 0
set bdecayv.sssd01.offset.05 0
set bdecayv.sssd01.offset.06 0
set bdecayv.sssd01.offset.07 0
set bdecayv.sssd01.offset.08 0
set bdecayv.sssd01.offset.09 0
set bdecayv.sssd01.offset.10 0
set bdecayv.sssd01.offset.11 0
set bdecayv.sssd01.offset.12 0
set bdecayv.sssd01.offset.13 0
set bdecayv.sssd01.offset.14 0
set bdecayv.sssd01.offset.15 0
set bdecayv.sssd01.offset.16 0

# Set SSSD01 gains (JPC 9/27/2006)
# All gains are based on peak positions on a 9-bit scale
set bdecayv.sssd01.slope.01 [expr 3000./(3092. - (${bdecayv.sssd01.offset.01}/8.0))]
set bdecayv.sssd01.slope.02 [expr 3000./(3121. - (${bdecayv.sssd01.offset.02}/8.0))]
set bdecayv.sssd01.slope.03 [expr 3000./(3078. - (${bdecayv.sssd01.offset.03}/8.0))]
set bdecayv.sssd01.slope.04 [expr 3000./(3080. - (${bdecayv.sssd01.offset.04}/8.0))]
set bdecayv.sssd01.slope.05 [expr 3000./(3035. - (${bdecayv.sssd01.offset.05}/8.0))]
set bdecayv.sssd01.slope.06 [expr 3000./(2942. - (${bdecayv.sssd01.offset.06}/8.0))]
set bdecayv.sssd01.slope.07 [expr 3000./(3038. - (${bdecayv.sssd01.offset.07}/8.0))]
set bdecayv.sssd01.slope.08 [expr 3000./(3035. - (${bdecayv.sssd01.offset.08}/8.0))]
set bdecayv.sssd01.slope.09 [expr 3000./(3000. - (${bdecayv.sssd01.offset.09}/8.0))]
set bdecayv.sssd01.slope.10 [expr 3000./(3000. - (${bdecayv.sssd01.offset.10}/8.0))]
set bdecayv.sssd01.slope.11 [expr 3000./(3092. - (${bdecayv.sssd01.offset.11}/8.0))]
set bdecayv.sssd01.slope.12 [expr 3000./(3067. - (${bdecayv.sssd01.offset.12}/8.0))]
set bdecayv.sssd01.slope.13 [expr 3000./(3027. - (${bdecayv.sssd01.offset.13}/8.0))]
set bdecayv.sssd01.slope.14 [expr 3000./(3140. - (${bdecayv.sssd01.offset.14}/8.0))]
set bdecayv.sssd01.slope.15 [expr 3000./(3136. - (${bdecayv.sssd01.offset.15}/8.0))]
set bdecayv.sssd01.slope.16 [expr 3000./(3047. - (${bdecayv.sssd01.offset.16}/8.0))]

# Set SSSD01 thresholds 
set bdecayv.sssd01.thresh.01 29.
set bdecayv.sssd01.thresh.02 31.
set bdecayv.sssd01.thresh.03 30.
set bdecayv.sssd01.thresh.04 34.
set bdecayv.sssd01.thresh.05 31.
set bdecayv.sssd01.thresh.06 35.
set bdecayv.sssd01.thresh.07 31.
set bdecayv.sssd01.thresh.08 29.
set bdecayv.sssd01.thresh.09 30000
set bdecayv.sssd01.thresh.10 30000
set bdecayv.sssd01.thresh.11 29.
set bdecayv.sssd01.thresh.12 28.
set bdecayv.sssd01.thresh.13 36.
set bdecayv.sssd01.thresh.14 33.
set bdecayv.sssd01.thresh.15 63.
set bdecayv.sssd01.thresh.16 126. 

# Set SSSD01 upper level discriminators
set bdecayv.sssd01.uld.01 4000.0
set bdecayv.sssd01.uld.02 4000.0
set bdecayv.sssd01.uld.03 4000.0
set bdecayv.sssd01.uld.04 4000.0
set bdecayv.sssd01.uld.05 4000.0
set bdecayv.sssd01.uld.06 4000.0
set bdecayv.sssd01.uld.07 4000.0
set bdecayv.sssd01.uld.08 4000.0
set bdecayv.sssd01.uld.09 4000.0
set bdecayv.sssd01.uld.10 4000.0
set bdecayv.sssd01.uld.11 4000.0
set bdecayv.sssd01.uld.12 4000.0
set bdecayv.sssd01.uld.13 4000.0
set bdecayv.sssd01.uld.14 4000.0
set bdecayv.sssd01.uld.15 4000.0
set bdecayv.sssd01.uld.16 4000.0


# SSSD02 #######################################################

# Set ADC offsets 
set bdecayv.sssd02.offset.01 0
set bdecayv.sssd02.offset.02 0
set bdecayv.sssd02.offset.03 0
set bdecayv.sssd02.offset.04 0
set bdecayv.sssd02.offset.05 0
set bdecayv.sssd02.offset.06 0
set bdecayv.sssd02.offset.07 0
set bdecayv.sssd02.offset.08 0
set bdecayv.sssd02.offset.09 0
set bdecayv.sssd02.offset.10 0
set bdecayv.sssd02.offset.11 0
set bdecayv.sssd02.offset.12 0
set bdecayv.sssd02.offset.13 0
set bdecayv.sssd02.offset.14 0
set bdecayv.sssd02.offset.15 0
set bdecayv.sssd02.offset.16 0

# Set SSSD02 gains 
set bdecayv.sssd02.slope.01 [expr 3000./(2788. - (${bdecayv.sssd02.offset.01}/8.0))]
set bdecayv.sssd02.slope.02 [expr 3000./(2800. - (${bdecayv.sssd02.offset.02}/8.0))]
set bdecayv.sssd02.slope.03 [expr 3000./(2826. - (${bdecayv.sssd02.offset.03}/8.0))]
set bdecayv.sssd02.slope.04 [expr 3000./(2833. - (${bdecayv.sssd02.offset.04}/8.0))]
set bdecayv.sssd02.slope.05 [expr 3000./(2760. - (${bdecayv.sssd02.offset.05}/8.0))]
set bdecayv.sssd02.slope.06 [expr 3000./(2788. - (${bdecayv.sssd02.offset.06}/8.0))]
set bdecayv.sssd02.slope.07 [expr 3000./(2752. - (${bdecayv.sssd02.offset.07}/8.0))]
set bdecayv.sssd02.slope.08 [expr 3000./(2763. - (${bdecayv.sssd02.offset.08}/8.0))]
set bdecayv.sssd02.slope.09 [expr 3000./(2788. - (${bdecayv.sssd02.offset.09}/8.0))]
set bdecayv.sssd02.slope.10 [expr 3000./(2813. - (${bdecayv.sssd02.offset.10}/8.0))]
set bdecayv.sssd02.slope.11 [expr 3000./(2900. - (${bdecayv.sssd02.offset.11}/8.0))]
set bdecayv.sssd02.slope.12 [expr 3000./(2810. - (${bdecayv.sssd02.offset.12}/8.0))]
set bdecayv.sssd02.slope.13 [expr 3000./(2830. - (${bdecayv.sssd02.offset.13}/8.0))]
set bdecayv.sssd02.slope.14 [expr 3000./(2849. - (${bdecayv.sssd02.offset.14}/8.0))]
set bdecayv.sssd02.slope.15 [expr 3000./(2808. - (${bdecayv.sssd02.offset.15}/8.0))]
set bdecayv.sssd02.slope.16 [expr 3000./(2710. - (${bdecayv.sssd02.offset.16}/8.0))]

# Set SSSD02 thresholds  
set bdecayv.sssd02.thresh.01 90.
set bdecayv.sssd02.thresh.02 75.
set bdecayv.sssd02.thresh.03 56.
set bdecayv.sssd02.thresh.04 47.
set bdecayv.sssd02.thresh.05 33.
set bdecayv.sssd02.thresh.06 50.
set bdecayv.sssd02.thresh.07 40.
set bdecayv.sssd02.thresh.08 51.
set bdecayv.sssd02.thresh.09 36.
set bdecayv.sssd02.thresh.10 35.
set bdecayv.sssd02.thresh.11 40.
set bdecayv.sssd02.thresh.12 35.
set bdecayv.sssd02.thresh.13 50.
set bdecayv.sssd02.thresh.14 60.
set bdecayv.sssd02.thresh.15 71.
set bdecayv.sssd02.thresh.16 116.

# Set SSSD02 upper level discriminators  
set bdecayv.sssd02.uld.01 4000.0
set bdecayv.sssd02.uld.02 4000.0
set bdecayv.sssd02.uld.03 4000.0
set bdecayv.sssd02.uld.04 4000.0
set bdecayv.sssd02.uld.05 4000.0
set bdecayv.sssd02.uld.06 4000.0
set bdecayv.sssd02.uld.07 4000.0
set bdecayv.sssd02.uld.08 4000.0
set bdecayv.sssd02.uld.09 4000.0
set bdecayv.sssd02.uld.10 4000.0
set bdecayv.sssd02.uld.11 4000.0
set bdecayv.sssd02.uld.12 4000.0
set bdecayv.sssd02.uld.13 4000.0
set bdecayv.sssd02.uld.14 4000.0
set bdecayv.sssd02.uld.15 4000.0
set bdecayv.sssd02.uld.16 4000.0


# SSSD03 #######################################################

# Set SSSD03 ADC offsets 
set bdecayv.sssd03.offset.01 0
set bdecayv.sssd03.offset.02 0
set bdecayv.sssd03.offset.03 0
set bdecayv.sssd03.offset.04 0
set bdecayv.sssd03.offset.05 0
set bdecayv.sssd03.offset.06 0
set bdecayv.sssd03.offset.07 0
set bdecayv.sssd03.offset.08 0
set bdecayv.sssd03.offset.09 0
set bdecayv.sssd03.offset.10 0
set bdecayv.sssd03.offset.11 0
set bdecayv.sssd03.offset.12 0
set bdecayv.sssd03.offset.13 0
set bdecayv.sssd03.offset.14 0
set bdecayv.sssd03.offset.15 0
set bdecayv.sssd03.offset.16 0

# Set SSSD03 gains  
set bdecayv.sssd03.slope.01 [expr 3000./(2976. - (${bdecayv.sssd03.offset.01}/8.0))]
set bdecayv.sssd03.slope.02 [expr 3000./(3035. - (${bdecayv.sssd03.offset.02}/8.0))]
set bdecayv.sssd03.slope.03 [expr 3000./(2981. - (${bdecayv.sssd03.offset.03}/8.0))]
set bdecayv.sssd03.slope.04 [expr 3000./(3009. - (${bdecayv.sssd03.offset.04}/8.0))]
set bdecayv.sssd03.slope.05 [expr 3000./(2969. - (${bdecayv.sssd03.offset.05}/8.0))]
set bdecayv.sssd03.slope.06 [expr 3000./(3028. - (${bdecayv.sssd03.offset.06}/8.0))]
set bdecayv.sssd03.slope.07 [expr 3000./(3124. - (${bdecayv.sssd03.offset.07}/8.0))]
set bdecayv.sssd03.slope.08 [expr 3000./(3020. - (${bdecayv.sssd03.offset.08}/8.0))]
set bdecayv.sssd03.slope.09 [expr 3000./(3023. - (${bdecayv.sssd03.offset.09}/8.0))]
set bdecayv.sssd03.slope.10 [expr 3000./(2987. - (${bdecayv.sssd03.offset.10}/8.0))]
set bdecayv.sssd03.slope.11 [expr 3000./(3042. - (${bdecayv.sssd03.offset.11}/8.0))]
set bdecayv.sssd03.slope.12 [expr 3000./(3118. - (${bdecayv.sssd03.offset.12}/8.0))]
set bdecayv.sssd03.slope.13 [expr 3000./(3078. - (${bdecayv.sssd03.offset.13}/8.0))]
set bdecayv.sssd03.slope.14 [expr 3000./(3023. - (${bdecayv.sssd03.offset.14}/8.0))]
set bdecayv.sssd03.slope.15 [expr 3000./(3049. - (${bdecayv.sssd03.offset.15}/8.0))]
set bdecayv.sssd03.slope.16 [expr 3000./(3296. - (${bdecayv.sssd03.offset.16}/8.0))]

# Set SSSD03 thresholds 
set bdecayv.sssd03.thresh.01 25.
set bdecayv.sssd03.thresh.02 34.
set bdecayv.sssd03.thresh.03 32.
set bdecayv.sssd03.thresh.04 34.
set bdecayv.sssd03.thresh.05 39.
set bdecayv.sssd03.thresh.06 33.
set bdecayv.sssd03.thresh.07 34.
set bdecayv.sssd03.thresh.08 42.
set bdecayv.sssd03.thresh.09 52.
set bdecayv.sssd03.thresh.10 39.
set bdecayv.sssd03.thresh.11 37.
set bdecayv.sssd03.thresh.12 82.
set bdecayv.sssd03.thresh.13 71.
set bdecayv.sssd03.thresh.14 08.
set bdecayv.sssd03.thresh.15 60.
set bdecayv.sssd03.thresh.16 151.

# Set SSSD03 upper level discriminators 
set bdecayv.sssd03.uld.01 4000.0
set bdecayv.sssd03.uld.02 4000.0
set bdecayv.sssd03.uld.03 4000.0
set bdecayv.sssd03.uld.04 4000.0
set bdecayv.sssd03.uld.05 4000.0
set bdecayv.sssd03.uld.06 4000.0
set bdecayv.sssd03.uld.07 4000.0
set bdecayv.sssd03.uld.08 4000.0
set bdecayv.sssd03.uld.09 4000.0
set bdecayv.sssd03.uld.10 4000.0
set bdecayv.sssd03.uld.11 4000.0
set bdecayv.sssd03.uld.12 4000.0
set bdecayv.sssd03.uld.13 4000.0
set bdecayv.sssd03.uld.14 4000.0
set bdecayv.sssd03.uld.15 4000.0
set bdecayv.sssd03.uld.16 4000.0


# SSSD04 #######################################################

# Set SSSD04 ADC offsets 
set bdecayv.sssd04.offset.01 0
set bdecayv.sssd04.offset.02 0
set bdecayv.sssd04.offset.03 0
set bdecayv.sssd04.offset.04 0
set bdecayv.sssd04.offset.05 0
set bdecayv.sssd04.offset.06 0
set bdecayv.sssd04.offset.07 0
set bdecayv.sssd04.offset.08 0
set bdecayv.sssd04.offset.09 0
set bdecayv.sssd04.offset.10 0
set bdecayv.sssd04.offset.11 0
set bdecayv.sssd04.offset.12 0
set bdecayv.sssd04.offset.13 0
set bdecayv.sssd04.offset.14 0
set bdecayv.sssd04.offset.15 0
set bdecayv.sssd04.offset.16 0

# Set SSSD04 gains 
set bdecayv.sssd04.slope.01 [expr 3000./(3055. - (${bdecayv.sssd04.offset.01}/8.0))]
set bdecayv.sssd04.slope.02 [expr 3000./(3330. - (${bdecayv.sssd04.offset.02}/8.0))]
set bdecayv.sssd04.slope.03 [expr 3000./(3321. - (${bdecayv.sssd04.offset.03}/8.0))]
set bdecayv.sssd04.slope.04 [expr 3000./(3276. - (${bdecayv.sssd04.offset.04}/8.0))]
set bdecayv.sssd04.slope.05 [expr 3000./(3278. - (${bdecayv.sssd04.offset.05}/8.0))]
set bdecayv.sssd04.slope.06 [expr 3000./(3231. - (${bdecayv.sssd04.offset.06}/8.0))]
set bdecayv.sssd04.slope.07 [expr 3000./(3328. - (${bdecayv.sssd04.offset.07}/8.0))]
set bdecayv.sssd04.slope.08 [expr 3000./(3269. - (${bdecayv.sssd04.offset.08}/8.0))]
set bdecayv.sssd04.slope.09 [expr 3000./(3272. - (${bdecayv.sssd04.offset.09}/8.0))]
set bdecayv.sssd04.slope.10 [expr 3000./(3318. - (${bdecayv.sssd04.offset.10}/8.0))]
set bdecayv.sssd04.slope.11 [expr 3000./(3240. - (${bdecayv.sssd04.offset.11}/8.0))]
set bdecayv.sssd04.slope.12 [expr 3000./(3327. - (${bdecayv.sssd04.offset.12}/8.0))]
set bdecayv.sssd04.slope.13 [expr 3000./(3309. - (${bdecayv.sssd04.offset.13}/8.0))]
set bdecayv.sssd04.slope.14 [expr 3000./(3388. - (${bdecayv.sssd04.offset.14}/8.0))]
set bdecayv.sssd04.slope.15 [expr 3000./(3340. - (${bdecayv.sssd04.offset.15}/8.0))]
set bdecayv.sssd04.slope.16 [expr 3000./(3077. - (${bdecayv.sssd04.offset.16}/8.0))]

# Set SSSD04 thresholds 
set bdecayv.sssd04.thresh.01 30000.
set bdecayv.sssd04.thresh.02 37.
set bdecayv.sssd04.thresh.03 31.
set bdecayv.sssd04.thresh.04 33.
set bdecayv.sssd04.thresh.05 35.
set bdecayv.sssd04.thresh.06 32.
set bdecayv.sssd04.thresh.07 32.
set bdecayv.sssd04.thresh.08 32.
set bdecayv.sssd04.thresh.09 37.
set bdecayv.sssd04.thresh.10 35.
set bdecayv.sssd04.thresh.11 35.
set bdecayv.sssd04.thresh.12 35.
set bdecayv.sssd04.thresh.13 37.
set bdecayv.sssd04.thresh.14 37.
set bdecayv.sssd04.thresh.15 35.
set bdecayv.sssd04.thresh.16 30000.

# Set SSSD04 upper level discriminators 
set bdecayv.sssd04.uld.01 4000.0
set bdecayv.sssd04.uld.02 4000.0
set bdecayv.sssd04.uld.03 4000.0
set bdecayv.sssd04.uld.04 4000.0
set bdecayv.sssd04.uld.05 4000.0
set bdecayv.sssd04.uld.06 4000.0
set bdecayv.sssd04.uld.07 4000.0
set bdecayv.sssd04.uld.08 4000.0
set bdecayv.sssd04.uld.09 4000.0
set bdecayv.sssd04.uld.10 4000.0
set bdecayv.sssd04.uld.11 4000.0
set bdecayv.sssd04.uld.12 4000.0
set bdecayv.sssd04.uld.13 4000.0
set bdecayv.sssd04.uld.14 4000.0
set bdecayv.sssd04.uld.15 4000.0
set bdecayv.sssd04.uld.16 4000.0

# SSSD05 #######################################################

# Set SSSD05 ADC hioffsets 
set bdecayv.sssd05.offset.01 0
set bdecayv.sssd05.offset.02 0
set bdecayv.sssd05.offset.03 0
set bdecayv.sssd05.offset.04 0
set bdecayv.sssd05.offset.05 0
set bdecayv.sssd05.offset.06 0
set bdecayv.sssd05.offset.07 0
set bdecayv.sssd05.offset.08 0
set bdecayv.sssd05.offset.09 0
set bdecayv.sssd05.offset.10 0
set bdecayv.sssd05.offset.11 0
set bdecayv.sssd05.offset.12 0
set bdecayv.sssd05.offset.13 0
set bdecayv.sssd05.offset.14 0
set bdecayv.sssd05.offset.15 0
set bdecayv.sssd05.offset.16 0

# Set SSSD05 gains 
set bdecayv.sssd05.slope.01 [expr 3000./(3014. - (${bdecayv.sssd05.offset.01}/8.0))]
set bdecayv.sssd05.slope.02 [expr 3000./(3040. - (${bdecayv.sssd05.offset.02}/8.0))]
set bdecayv.sssd05.slope.03 [expr 3000./(3067. - (${bdecayv.sssd05.offset.03}/8.0))]
set bdecayv.sssd05.slope.04 [expr 3000./(3068. - (${bdecayv.sssd05.offset.04}/8.0))]
set bdecayv.sssd05.slope.05 [expr 3000./(3056. - (${bdecayv.sssd05.offset.05}/8.0))]
set bdecayv.sssd05.slope.06 [expr 3000./(3046. - (${bdecayv.sssd05.offset.06}/8.0))]
set bdecayv.sssd05.slope.07 [expr 3000./(2972. - (${bdecayv.sssd05.offset.07}/8.0))]
set bdecayv.sssd05.slope.08 [expr 3000./(2932. - (${bdecayv.sssd05.offset.08}/8.0))]
set bdecayv.sssd05.slope.09 [expr 3000./(3023. - (${bdecayv.sssd05.offset.09}/8.0))]
set bdecayv.sssd05.slope.10 [expr 3000./(3003. - (${bdecayv.sssd05.offset.10}/8.0))]
set bdecayv.sssd05.slope.11 [expr 3000./(3071. - (${bdecayv.sssd05.offset.11}/8.0))]
set bdecayv.sssd05.slope.12 [expr 3000./(3094. - (${bdecayv.sssd05.offset.12}/8.0))]
set bdecayv.sssd05.slope.13 [expr 3000./(3092. - (${bdecayv.sssd05.offset.13}/8.0))]
set bdecayv.sssd05.slope.14 [expr 3000./(3078. - (${bdecayv.sssd05.offset.14}/8.0))]
set bdecayv.sssd05.slope.15 [expr 3000./(3042. - (${bdecayv.sssd05.offset.15}/8.0))]
set bdecayv.sssd05.slope.16 [expr 3000./(3000. - (${bdecayv.sssd05.offset.16}/8.0))]

# Set SSSD05 thresholds 
set bdecayv.sssd05.thresh.01 37.
set bdecayv.sssd05.thresh.02 36.
set bdecayv.sssd05.thresh.03 33.
set bdecayv.sssd05.thresh.04 38.
set bdecayv.sssd05.thresh.05 35.
set bdecayv.sssd05.thresh.06 37.
set bdecayv.sssd05.thresh.07 34.
set bdecayv.sssd05.thresh.08 33.
set bdecayv.sssd05.thresh.09 38.
set bdecayv.sssd05.thresh.10 40.
set bdecayv.sssd05.thresh.11 44.
set bdecayv.sssd05.thresh.12 45.
set bdecayv.sssd05.thresh.13 49.
set bdecayv.sssd05.thresh.14 112.
set bdecayv.sssd05.thresh.15 87.
set bdecayv.sssd05.thresh.16 0.0

# Set SSSD05 upper level discriminators 
set bdecayv.sssd05.uld.01 4000.0
set bdecayv.sssd05.uld.02 4000.0
set bdecayv.sssd05.uld.03 4000.0
set bdecayv.sssd05.uld.04 4000.0
set bdecayv.sssd05.uld.05 4000.0
set bdecayv.sssd05.uld.06 4000.0
set bdecayv.sssd05.uld.07 4000.0
set bdecayv.sssd05.uld.08 4000.0
set bdecayv.sssd05.uld.09 4000.0
set bdecayv.sssd05.uld.10 4000.0
set bdecayv.sssd05.uld.11 4000.0
set bdecayv.sssd05.uld.12 4000.0
set bdecayv.sssd05.uld.13 4000.0
set bdecayv.sssd05.uld.14 4000.0
set bdecayv.sssd05.uld.15 4000.0
set bdecayv.sssd05.uld.16 4000.0


# SSSD06 #######################################################

# Set SSSD06 ADC hioffsets 
set bdecayv.sssd06.offset.01 0
set bdecayv.sssd06.offset.02 0
set bdecayv.sssd06.offset.03 0
set bdecayv.sssd06.offset.04 0
set bdecayv.sssd06.offset.05 0
set bdecayv.sssd06.offset.06 0
set bdecayv.sssd06.offset.07 0
set bdecayv.sssd06.offset.08 0
set bdecayv.sssd06.offset.09 0
set bdecayv.sssd06.offset.10 0
set bdecayv.sssd06.offset.11 0
set bdecayv.sssd06.offset.12 0
set bdecayv.sssd06.offset.13 0
set bdecayv.sssd06.offset.14 0
set bdecayv.sssd06.offset.15 0
set bdecayv.sssd06.offset.16 0

# Set SSSD06 gains 
set bdecayv.sssd06.slope.01 [expr 3000./(3060.  - (${bdecayv.sssd06.offset.01}/8.0))]
set bdecayv.sssd06.slope.02 [expr 3000./(3070. - (${bdecayv.sssd06.offset.02}/8.0))]
set bdecayv.sssd06.slope.03 [expr 3000./(2990.- (${bdecayv.sssd06.offset.03}/8.0))]
set bdecayv.sssd06.slope.04 [expr 3000./(3009. - (${bdecayv.sssd06.offset.04}/8.0))]
set bdecayv.sssd06.slope.05 [expr 3000./(3045. - (${bdecayv.sssd06.offset.05}/8.0))]
set bdecayv.sssd06.slope.06 [expr 3000./(3077. - (${bdecayv.sssd06.offset.06}/8.0))]
set bdecayv.sssd06.slope.07 [expr 3000./(3055. - (${bdecayv.sssd06.offset.07}/8.0))]
set bdecayv.sssd06.slope.08 [expr 3000./(3038. - (${bdecayv.sssd06.offset.08}/8.0))]
set bdecayv.sssd06.slope.09 [expr 3000./(3040. - (${bdecayv.sssd06.offset.09}/8.0))]
set bdecayv.sssd06.slope.10 [expr 3000./(3065. - (${bdecayv.sssd06.offset.10}/8.0))]
set bdecayv.sssd06.slope.11 [expr 3000./(2985. - (${bdecayv.sssd06.offset.11}/8.0))]
set bdecayv.sssd06.slope.12 [expr 3000./(3034. - (${bdecayv.sssd06.offset.12}/8.0))]
set bdecayv.sssd06.slope.13 [expr 3000./(2945. - (${bdecayv.sssd06.offset.13}/8.0))]
set bdecayv.sssd06.slope.14 [expr 3000./(3106. - (${bdecayv.sssd06.offset.14}/8.0))]
set bdecayv.sssd06.slope.15 [expr 3000./(3016. - (${bdecayv.sssd06.offset.15}/8.0))]
set bdecayv.sssd06.slope.16 [expr 3000./(3105. - (${bdecayv.sssd06.offset.16}/8.0))]

# Set SSSD06 thresholds 
set bdecayv.sssd06.thresh.01 58.
set bdecayv.sssd06.thresh.02 49.
set bdecayv.sssd06.thresh.03 48.
set bdecayv.sssd06.thresh.04 46.
set bdecayv.sssd06.thresh.05 52.
set bdecayv.sssd06.thresh.06 50.
set bdecayv.sssd06.thresh.07 45.
set bdecayv.sssd06.thresh.08 51.
set bdecayv.sssd06.thresh.09 51.
set bdecayv.sssd06.thresh.10 48.
set bdecayv.sssd06.thresh.11 50.
set bdecayv.sssd06.thresh.12 50.
set bdecayv.sssd06.thresh.13 55.
set bdecayv.sssd06.thresh.14 54.
set bdecayv.sssd06.thresh.15 59.
set bdecayv.sssd06.thresh.16 78.

# Set SSSD06 upper level discriminators 
set bdecayv.sssd06.uld.01 4000.0
set bdecayv.sssd06.uld.02 4000.0
set bdecayv.sssd06.uld.03 4000.0
set bdecayv.sssd06.uld.04 4000.0
set bdecayv.sssd06.uld.05 4000.0
set bdecayv.sssd06.uld.06 4000.0
set bdecayv.sssd06.uld.07 4000.0
set bdecayv.sssd06.uld.08 4000.0
set bdecayv.sssd06.uld.09 4000.0
set bdecayv.sssd06.uld.10 4000.0
set bdecayv.sssd06.uld.11 4000.0
set bdecayv.sssd06.uld.12 4000.0
set bdecayv.sssd06.uld.13 4000.0
set bdecayv.sssd06.uld.14 4000.0
set bdecayv.sssd06.uld.15 4000.0
set bdecayv.sssd06.uld.16 4000.0

# end of variable initialization

