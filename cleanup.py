import numpy as np
import sys
filename = sys.argv[1] + '/Integrated.dat'
file1 = open(filename, 'r')
timelen = float(sys.argv[2])
counts = np.loadtxt(file1, usecols=(1,), unpack=True)
quada = counts[0:15]
quadd = counts[15:30]
quadb = counts[30:45]
quadc = counts[45:60]
#quada = counts[0:10]
#quadd = counts[11:21]
#quadb = counts[22:32]
#quadc = counts[33:43]
print "Quad A: ", sum(quada)/(147.12*timelen)
print "Quad B: ", sum(quadb)/(147.12*timelen)
print "Quad C: ", sum(quadc)/(147.12*timelen)
print "Quad D: ", sum(quadd)/(147.12*timelen)
print "Total: ", sum(counts)/(147.12*timelen)
print sum(counts)
print sum(counts)/(timelen)
np.savetxt(sys.argv[1]+'/Reintegrated.dat', np.transpose((counts)), fmt='%.3i')
