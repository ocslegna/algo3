import numpy as np
import random
import networkx as nx

#code creating G here
#G=nx.gnm_random_graph(10,25.0)

#for (u, v) in G.edges():
#    G.edge[u][v]['weight'] = random.randint(1,10)
#print "Cantidad de ejes:" + str(len(G.edges()))
#for (u, v) in G.edges():
#    print "(" + str(1+u) + "," + str(1+v) + "):" + str(G.edge[u][v]['weight'])
#print G.edges()
#M = adjacency_matrix(G)
#M = nx.to_numpy_matrix(G)
#print M

#G2 = nx.dense_gnm_random_graph(10, 1)
#for (u, v) in G2.edges():
#    G2.edge[u][v]['weight'] = random.randint(1,10)

#print "Grafo 2:" + str(len(G2.edges())) 
#for (u, v) in G2.edges():
#    print "(" + str(1+u) + "," + str(1+v) + "):" + str(G2.edge[u][v]['weight'])

#G = nx.dense_gnm_random_graph(10, 20)
#print G.edges()
#for (u, v) in G.edges():
#	G.edge[u][v]['weight'] = random.randint(1,100)
#	w = G.edge[u][v]['weight']
##print nx.number_connected_components(G)
#print nx.is_connected(G)
#print G.size(weight='weight')
#Tree = nx.minimum_spanning_tree(G)
#print Tree.edges()
#print Tree.size(weight='weight')



randinput = open('graph', 'w')
weights = open('weights', 'w')
weights.truncate(0)
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
		Tree = nx.minimum_spanning_tree(G)
		weights.write("{0}\n".format(Tree.size(weight='weight')))
		
randinput.write("0 \n")
randinput.close()
