# 2023/06/15 21:20:41
# 2023/06/15 21:24:10 AC.
N,Q = map(int, input().split())
a = []
for i in range(N):
    a.append(input().split()[1:])
for i in range(Q):
    s,t = map(int, input().split())
    print(a[s - 1][t - 1])
