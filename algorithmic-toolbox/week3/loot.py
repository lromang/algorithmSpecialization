#python2

import sys

## knapsack
def knapsack(v, w, c):
    """
    v = value of items.
    w = weight of itmes.
    c = capacity of knapsack.
    """
    tot          = 0
    fracs        = [float(n)/float(d) for n, d in zip(v, w)]
    sortedIndexs = sorted(range(len(fracs)), key = lambda k: fracs[k], reverse = True)
    i = 0
    while(c > 0 and i < len(v)):
        frac_in  = min(1, float(c)/float(w[sortedIndexs[i]]))
        c        = c   - frac_in*w[sortedIndexs[i]]
        tot      = tot + frac_in*v[sortedIndexs[i]]
        i        = i + 1
    return float(tot)


## Running variables.
n        = sys.stdin.readline()
weights  = []
values   = []
c        = int(n.split(' ')[1])
for i in range(int(n.split(' ')[0])):
    item = sys.stdin.readline().rstrip('\n')
    item = item.split(' ')
    values.append(int(item[0]))
    weights.append(int(item[1]))
print '%f' % knapsack(values, weights, c)
