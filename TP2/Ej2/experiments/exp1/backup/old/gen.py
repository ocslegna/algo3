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


# Generate graph with n nodes and density = p
def generate_input_density(n, p):
	randinput = open('ASD', 'w')
	randinput.truncate(0)
	
	G = nx.gnp_random_graph(n, p)
	m = len(G.edges())
	randinput.write("{0} {1}\n".format(n,m))
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

	generate_input_density(100, 0.5)
