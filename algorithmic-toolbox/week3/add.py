import sys



## Read in data
a = [int(c) for c in list(sys.stdin.readline().rstrip('\n'))]
b = [int(c) for c in list(sys.stdin.readline().rstrip('\n'))]
a.sort()
b.sort()
c = [c*d for c,d in zip(a, b)]
print '%f' % sum(c)
