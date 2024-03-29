import numpy as np
import random
import networkx as nx
import subprocess
import os

def own_method():
	pname = "./main"
	rinput = open('rinput', 'r')
	routput = open('output_us.txt', 'w')
	routput.truncate(0)
	p = subprocess.Popen(pname, stdin=rinput, stdout=routput)
	p.wait()
	rinput.close()
	routput.close()
	return


if __name__ == '__main__':

	if(not os.path.exists("main")):
		print "Compiling program..."
		p = subprocess.Popen('make')
		p.wait()


	print "Generating random input..."
	randinput = open('rinput', 'w')
	#weights = open('output_lib', 'w')
	#weights.truncate(0)
	randinput.truncate(0)
	
	for n in range(5, 11):
		complete = n*(n-1)/2
		for m in range(n-1, complete+1):
			randinput.write("{0} {1}\n".format(n,m))
			G = nx.dense_gnm_random_graph(n, m)
			while nx.is_connected(G) == False:
				G = nx.dense_gnm_random_graph(n, m)
			for (u, v) in G.edges():
				G.edge[u][v]['weight'] = random.randint(1,100)
				w = G.edge[u][v]['weight']
				randinput.write("{0} {1} {2}\n".format(u+1,v+1,w))
			#Tree = nx.minimum_spanning_tree(G)
			#weights.write("{0}\n".format(str(Tree.size(weight='weight'))))
			
	randinput.write("0 \n")
	randinput.close()
	

	#print "Running excersice 2..."
	#own_method()