#python2
import sys

## Running variables.
n        = sys.stdin.readline()
weights  = []
values   = []
for i in range(int(n[0])):
    item = sys.stdin.readline().rstrip('\n')
    item = item.split(' ')
    values.append(int(item[0]))
    weights.append(int(item[1]))

print values
print weights
