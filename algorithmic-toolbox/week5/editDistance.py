#python2

import sys


def editDist(a, b):
    '''
    List of len(a)Xlen(b)
    len(a) = n rows
    len(b) = n cols
    '''

    ## Fill in with the indices for first col and row.
    a = ' ' + a
    b = ' ' + b
    distances = [[0 for i in range(len(b))] for j in range(len(a))]
    for i in range(len(b)):
        distances[0][i] = i
    for i in range(len(a)):
        distances[i][0] = i

    ##
    for i in range(len(a))[1:]:
        for j in range(len(b))[1:]:
            if a[i] == b[j]:
                distances[i][j] = min(distances[i - 1][j - 1],
                                      distances[i - 1][j] + 1,
                                      distances[i][j - 1] + 1)
            else:
                distances[i][j] = min(distances[i - 1][j - 1] + 1,
                                      distances[i - 1][j] + 1,
                                      distances[i][j - 1] + 1)
    return distances[len(a) - 1][len(b) - 1]

a = sys.stdin.readline()
b = sys.stdin.readline()
print editDist(a, b)
