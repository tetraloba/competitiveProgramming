# 
# 2023/07/12 20:15:31 AC.
H, W = map(int, input().split())
A = [0] * H
for i in range(H):
    A[i] = list(map(int, input().split()))
for i1 in range(H):
    for i2 in range(i1, H):
        for j1 in range(W):
            for j2 in range(j1, W):
                if not A[i1][j1] + A[i2][j2] <= A[i2][j1] + A[i1][j2]:
                    print('No')
                    exit()
print('Yes')
