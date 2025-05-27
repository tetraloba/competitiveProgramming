# 2023/06/15 23:22:39
# 2023/06/16 00:22:30 AC.
N,M = map(int, input().split())
x = [[False for _ in range(N) ] for _ in range(M)]
for i in range(M):
    for j in map(int, input().split()[1:]):
        x[i][j - 1] = True
friends = [[False for _ in range(N)] for _ in range(N)]
for i in range(N):
    for j in x:
        for k,l in enumerate(j):
            if l:
                friends[i][k] |= j[i] & l
ans = True
for i in friends:
    for j in i:
        ans &= j
# print(x)
# print(friends)
if ans:
    print("Yes")
else:
    print("No")
