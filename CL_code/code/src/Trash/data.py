from os import listdir
from os.path import isfile, join
import sys

args = sys.argv

d = str(args[1])
#d = args[2]
#print d
for f in listdir(d): 
	if (f.endswith(".h")):
		f_ns = f[:-2]
		f_fu = d + "/" + f
		lines = open(f_fu).readlines()
		open(f_fu, 'w').writelines("/**\n * @addtogroup " + f_ns +"\n * @ingroup " + d + "\n * @{\n")
		open(f_fu, 'a').writelines(lines[2:])
		open(f_fu, 'a').writelines("\n/** @} */")


