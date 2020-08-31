
with open("raw_spectra.tcl","w") as f:
    for i in range(0,416):
        num_string = ""
        if i < 10:
            num_string =  "00" + str(i)
        elif i < 100:
            num_string =  "0" + str(i)
        else:
            num_string =  str(i)
    
        f.write("catch {spectrum -delete raw"+num_string+"}\n")
        f.write("spectrum raw"+num_string+" 1 bdecay.raw.chanid"+num_string+".adc {{0.000000 65536.000000 65536}} long\n")
    
