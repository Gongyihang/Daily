def inv(a):
    n = len(a)
    for i in range(n):
#        print(f'a[{i}][{i}]:{a[i][i]}')
        a[i][i] = 1/a[i][i]
#        print(f'a[{i}][{i}]:{a[i][i]}')
#        print(a)
        for j in range(n):
            if j != i :
#                print(f'a[{i}][{j}]:{a[i][j]}')
                a[i][j] = a[i][j]*a[i][i]
#                print(f'a[{i}][{j}]:{a[i][j]}')
        for k in range(n):
            for j in range(n):
                if k!=i and j!=i:
#                    print(f'a[{k}][{j}]:{a[k][j]}')
                    a[k][j] = a[k][j]-a[k][i]*a[i][j]
#                    print(f'a[{k}][{j}]:{a[k][j]}')
        for k in range(n):
            if k!=i :
#                print(f'a[{i}][{j}]:{a[i][j]}')
                a[k][i] = -a[k][i]*a[i][i]
#                print(f'a[{i}][{j}]:{a[i][j]}')
    return a

#import numpy as np

#e  = np.random.randn(3,3)
e = [[1,-1,1],[5,-4,3],[2,1,1]]
#e = np.array([[1,5,2],[-1,-1,1],[1,3,1]])
print(e)
print(inv(e))