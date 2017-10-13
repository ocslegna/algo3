import numpy as np
import random
import networkx as nx
import subprocess
import os
import difflib

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
	
	G = nx.dense_gnm_random_graph(n, m)
	while nx.is_connected(G) == False:
		m = m+1
		G = nx.dense_gnm_random_graph(n, m)

	randinput.write("{0} {1}\n".format(n,m))
	for (u, v) in G.edges():
		G.edge[u][v]['weight'] = random.randint(1,100)
		w = G.edge[u][v]['weight']
		randinput.write("{0} {1} {2}\n".format(u+1,v+1,w))
			
	randinput.write("0 \n")
	randinput.close()

	return m


# Generate graph with n nodes and density = p
def generate_input_density(n, p):
	randinput = open('rinput', 'w')
	randinput.truncate(0)
	
	G = nx.gnp_random_graph(n, p)
	k = 0
	while nx.is_connected(G) == False and k < 50:
		G = nx.gnp_random_graph(n, p)
		k = k+1
		if k >= 50:
			p = p + 0.025
			G = nx.gnp_random_graph(n, p)
			k = 0

	m = len(G.edges())			
	randinput.write("{0} {1}\n".format(n,m))
	
	for (u, v) in G.edges():
		G.edge[u][v]['weight'] = random.randint(1,100)
		w = G.edge[u][v]['weight']
		randinput.write("{0} {1} {2}\n".format(u+1,v+1,w))
			
	randinput.write("0 \n")
	randinput.close()

	return [m,p]

def file_is_empty(path):
    return os.stat(path).st_size==0


#if __name__ == '__main__':
def main(default = 500, **kwargs):
	if(not os.path.exists("main")):
		print "Compiling program..."
		p = subprocess.Popen('make')
		p.wait()

	delimiter = ';'

	if('optional' in kwargs):
		#print 'optional parameter found, it is ', kwargs['optional']
		n = kwargs['optional']
	else:
		n = default

	print "Running experiment..."
	file = open('exp2nfijo.csv', 'w')
	file.write(delimiter.join(['modo','vertices','aristas','duracion','densidad']) + '\n')
	
	complete = n*(n-1)/2
	min_den = 6000
	for m in range(min_den, complete+1, 1000):
		m = generate_input(n,m)
		d = 2*m/float(n*(n-1))
		percent = m/(float(complete))*100
		print "	" + str(int(percent)) + "% Running with " + str(n) + " nodes and density " + str(d)
		for i in range(0,11):
			times = own_method()
			if str(times) == "":
				print "ERROR"
			ts = times.split('\n')
			t1 = ts[0]
			t2 = ts[1]
			file.write(delimiter.join(["arreglo", str(n), str(m), str(t1), str(d)]) + '\n')
			file.write(delimiter.join(["cola", str(n), str(m)
				, str(t2), str(d)]) + '\n')		

	os.remove('output_basico')
	os.remove('rinput')

