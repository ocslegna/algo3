import os
import subprocess
import sys
from shutil import copy

if __name__ == '__main__':
	sys.path.append('./code')
	sys.path.append('./nfijo')


	if(not os.path.exists("main")):
		print "Compiling program..."
		p = subprocess.Popen(["make"], stdout=subprocess.PIPE, cwd="./code")
		p.wait()
		copy('./code/main', './main')
		copy('./code/Makefile', './Makefile')


	import exp2nfijo as nfijo

	nfijo.main()

	
	p = subprocess.Popen(["make", "clean"], stdout=subprocess.PIPE)
	p = subprocess.Popen(["make", "clean"], stdout=subprocess.PIPE, cwd="./code")

	os.remove('Makefile')
	