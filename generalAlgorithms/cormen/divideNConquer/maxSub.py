###########################################
###########################################
## Divide an conquer algorithms
###########################################
###########################################
import math
import numpy as np


## ----------------------------------------
## Maximum sum problem (divide and conquer)
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

## ----------------------------------------
## Maximum sum problem (linear)
## ----------------------------------------
def maxSumLin(a, n):
    maxRight = maxLeft = 0
    maxSub = []
    maxSum = 0
    debt   = 0
    for i in range(n):
        if (maxSum - debt) < 0 and 0 < a[i]:
            maxSub  = [a[i]]
            maxSum  = a[i]
            maxLeft = maxRight = i
        elif  debt + a[i] > 0:
            maxSub.append(a[i])
            maxSum   = maxSum + a[i] + debt
            maxRight = maxRight + 1
        elif maxSum != 0:
            debt = debt + a[i]
    return maxLeft, maxRight, maxSum
## ----------------------------------------
## Testing
## ----------------------------------------
a = np.random.randint(-100, 100, size = 10)

maxArray(a, len(a) - 1, 0)

maxSumLin(a, len(a))
