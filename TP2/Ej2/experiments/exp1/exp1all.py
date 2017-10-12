import os
import subprocess
import sys
from shutil import copy

if __name__ == '__main__':
	sys.path.append('./code')
	sys.path.append('./complete')
	sys.path.append('./random')
	sys.path.append('./sparse')


	if(not os.path.exists("main")):
		print "Compiling program..."
		p = subprocess.Popen(["make"], stdout=subprocess.PIPE, cwd="./code")
		p.wait()
		copy('./code/main', './main')
		copy('./code/Makefile', './Makefile')


	import exp1complete as comp
	import exp1random as rand
	import exp1sparse as spar

	# se puede pasarle a la funcion main un paramatro opcional que denota la cantidad maxima de vertices
	# por default es 500
	comp.main()
	rand.main()
	spar.main()

	# Por ej:
	#comp.main(51)
	#rand.main(51)
	#spar.main(51)

		

	p = subprocess.Popen(["make", "clean"], stdout=subprocess.PIPE)
	p = subprocess.Popen(["make", "clean"], stdout=subprocess.PIPE, cwd="./code")

	os.remove('Makefile')
	