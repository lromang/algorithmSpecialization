#python2

import sys
import math

## Majority
def majority(n, l, h):
    """
    Return:
    - Item
    - Count
    """
    if len(n) == 0:
        return 0
    if l == h:
        return n[l], 1
    if h - l == 1 and n[l] == n[h]:
        return n[l], 2
    if h - l == 1 and n[l] != n[h]:
        return -1, 0
    # Recursive call
    m = int(math.floor((l + h)/2))
    item_h, count_h = majority(n, m, h)
    item_l, count_l = majority(n, l, m)
    if item_h == item_l:
        return item_h, count_h + count_l
    if count_h >= count_l:
        return item_h, count_h
    if count_l >= count_l:
        return item_l, count_l
    return -1, 0

def callMajority(n):
    return int(majority(n, 0, len(n) - 1)[1] > len(n)/2)

## Read in Variables
n        = sys.stdin.readline()
weights  = []
values   = []
c        = int(n.split(' ')[0])
items    = sys.stdin.readline()
items    = [int(i) for i in items.split()]
print callMajority(items)
