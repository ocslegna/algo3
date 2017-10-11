import numpy as np
import random
import networkx as nx
import subprocess
import os

def own_method():
	pname = "./main"
	rinput = open('rinput', 'r')
	routput = open('output_basico', 'w')
	routput.truncate(0)
	p = subprocess.Popen(pname, stdin=rinput, stdout=routput)
	p.wait()
	
	routput = open('output_basico')
	s = routput.read()
	routput.close()
	return s

# Generate graph with n nodes and m edges
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

def generate_input_complete(n):
	randinput = open('rinput', 'w')
	randinput.truncate(0)
	
	G = nx.complete_graph(n)
	m = n*(n-1)/2
	if(len(G.edges()) != m):
		print "ERROR"
	
	randinput.write("{0} {1}\n".format(n,m))
	
	for (u, v) in G.edges():
		G.edge[u][v]['weight'] = random.randint(1,100)
		w = G.edge[u][v]['weight']
		randinput.write("{0} {1} {2}\n".format(u+1,v+1,w))
			
	randinput.write("0 \n")
	randinput.close()	

# Generate graph with n nodes and density = p
def generate_input_density(n, p):
	randinput = open('rinput', 'w')
	randinput.truncate(0)
	
	G = nx.gnp_random_graph(n, p)
	m = len(G.edges())
	randinput.write("{0} {1}\n".format(n,m))
	k = 0
	while nx.is_connected(G) == False and k < 50:
		G = nx.dense_gnm_random_graph(n, m)
		k = k+1
		if k >= 50:
			p = p + 0.025
			G = nx.gnp_random_graph(n, p)
			k = 0


	for (u, v) in G.edges():
		G.edge[u][v]['weight'] = random.randint(1,100)
		w = G.edge[u][v]['weight']
		randinput.write("{0} {1} {2}\n".format(u+1,v+1,w))
			
	randinput.write("0 \n")
	randinput.close()

def file_is_empty(path):
    return os.stat(path).st_size==0


#if __name__ == '__main__':
def main(default = 501, **kwargs):
	if(not os.path.exists("main")):
		print "Compiling program..."
		p = subprocess.Popen('make')
		p.wait()

	delimiter = ';'

	if('optional' in kwargs):
		#print 'optional parameter found, it is ', kwargs['optional']
		max_n = kwargs['optional']
	else:
		max_n = default


	print "Running experiment..."
	file = open('exp2complete.csv', 'w')
	file.write(delimiter.join(['modo','vertices','aristas','duracion','densidad']) + '\n')
	
	for n in range(10, max_n):
		generate_input_complete(n)
		percent = n/(float(max_n)-1)*100
		print "	" + str(int(percent)) + "% Running with " + str(n) + " nodes complete graph"


		m = n*(n-1)/2
		p = 2*m/(n*(n-1))
		for i in range(0,11):
			times = own_method()
			ts = times.split('\n')
			t1 = ts[0]
			t2 = ts[1]
			file.write(delimiter.join(["arreglo", str(n), str(m), str(t1), str(p)]) + '\n')
			file.write(delimiter.join(["cola", str(n), str(m), str(t2), str(p)]) + '\n')
	

	os.remove('output_basico')
	os.remove('rinput')

