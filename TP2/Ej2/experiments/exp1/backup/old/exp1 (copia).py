import numpy as np
import random
import networkx as nx
import subprocess
import os
import difflib

def own_method():
	pname = "./main"
	rinput = open('rinput', 'r')
	routput = open('output_basic', 'w')
	routput.truncate(0)
	p = subprocess.Popen(pname, stdin=rinput, stdout=routput)
	p.wait()
	
	routput = open('output_basic')
	s = routput.read()
	routput.close()
	return s

def generate_input(n, m):
	randinput = open('rinput', 'w')
	randinput.truncate(0)
	
	randinput.write("{0} {1}\n".format(n,m))
	G = nx.dense_gnm_random_graph(n, m)
	while nx.is_connected(G) == False:
		G = nx.dense_gnm_random_graph(n, m)
	for (u, v) in G.edges():
		G.edge[u][v]['weight'] = random.randint(1,100)
		w = G.edge[u][v]['weight']
		randinput.write("{0} {1} {2}\n".format(u+1,v+1,w))
			
	randinput.write("0 \n")
	randinput.close()

def file_is_empty(path):
    return os.stat(path).st_size==0


if __name__ == '__main__':

	if(not os.path.exists("main")):
		print "Compiling program..."
		p = subprocess.Popen('make')
		p.wait()

	delimiter = ';'

	print "Running experiment..."
	file = open('exp1.csv', 'w')
	file.write(delimiter.join(['modo','vertices','aristas','duracion','resultado']) + '\n')
	for n in range(50, 51):
		complete = n*(n-1)/2
		for m in xrange(n-1, complete+1, 5):
			for i in range(0,1):
				generate_input(n, 2*m)
				t1 = own_method()
				#t2 = own_method_colaprioridad() TO DO
				file.write(delimiter.join(["basico", str(n), str(m), str(t1)]) + '\n')
	

	os.remove('output_basico')
	os.remove('rinput')

