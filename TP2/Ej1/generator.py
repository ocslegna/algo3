# $ python generator.py n_intances n_works max_cost

import sys
import random

n_instances = int(sys.argv[1])
n_works = int(sys.argv[2])
max_cost = int(sys.argv[3]) if len(sys.argv) > 3 else 100

for n in xrange(0, n_instances):
    # n_works = random.randint(5, 15)
    cost = [ [random.randint(1, max_cost) for i in xrange(0, j+1)] for j in xrange(0, n_works) ]
    sys.stdout.write(str(n_works)+'\n')
    for i in xrange(0, len(cost)):
        for j in xrange(0, i+1):
            sys.stdout.write(str(cost[i][j]) + ' ')
        sys.stdout.write('\n')
sys.stdout.write(str(0)+'\n')