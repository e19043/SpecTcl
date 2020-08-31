import numpy as np
import sys
from scipy.optimize import curve_fit
f1 = open(sys.argv[1], 'r')
x,y = np.genfromtxt(f1,skip_header=7, skip_footer=1,dtype=str,unpack=True)
x1 = []
y1 = []
for index,item in enumerate(x):
	x1.append(float(item[1:-1]))
	y1.append(float(y[index]))
np.savetxt(sys.argv[1]+'.txt', np.transpose((x1,y1)), fmt='%.1i')
