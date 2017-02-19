###########################################
###########################################
## Divide an conquer algorithms
###########################################
###########################################
import math
import numpy as np


## ----------------------------------------
## Maximum sum problem
## ----------------------------------------
def maxCrossing(a, high, low, mid):
    maxLeft = maxRight = high/2
    sum    = 0
    aux    = mid
    lowSum = highSum = -float('inf')
    while aux >= low:
        sum  = sum + a[aux]
        if sum >= lowSum:
            lowSum  = sum
            maxLeft = aux
        else:
            break
        aux = aux - 1
    sum = 0
    aux = mid + 1
    while aux <= high:
        sum = sum + a[aux]
        if highSum <= sum:
            highSum  = sum
            maxRight = aux
        else:
            break
        aux = aux + 1
    return maxLeft, maxRight, lowSum + highSum

def maxArray(a, high, low):
    if high < low:
        return -1
    if high == low:
        return (low, high, a[low])
    mid = (low + high)/2
    lowLeft, highLeft, sumLeft    = maxArray(a, mid, low)
    lowRight, highRight, sumRight = maxArray(a, high, mid + 1)
    lowCent, highCent, sumCent    = maxCrossing(a, high, low, mid)
    if(sumLeft >= max(sumRight, sumCent)):
        return lowLeft, highLeft, sumLeft
    if(sumRight >= max(sumLeft, sumCent)):
        return lowRight, highRight, sumRight
    return lowCent, highCent, sumCent

a = np.random.randint(-100, 100, size = 100)
maxArray(a, len(a) - 1, 0)
