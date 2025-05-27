# 2023/06/20 00:10:04
# 2023/06/20 00:21:36 TLE
N, Q = map(int, input().split())
ls = list()
for _ in range(N):
    st = set()
    ls.append(st)
for _ in range(Q):
    T, A, B = map(int, input().split())
    if T == 1:
        ls[A - 1].add(B - 1)
    elif T == 2:
        if B - 1 in ls[A - 1]:
            ls[A - 1].remove(B - 1)
    else:
        if B - 1 in ls[A - 1] and A - 1 in ls[B - 1]:
            print('Yes')
        else:
            print('No')

