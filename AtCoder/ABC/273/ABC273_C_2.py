# 2023/06/24 12:04:16
# 2023/06/24 12:11:18 AC.
N = int(input())
A = list(map(int, input().split()))
dct = dict()
for i in A:
    dct[i] = dct.get(i, 0) + 1
for _, value in sorted(dct.items(), reverse=True):
    print(value)
for _ in range(N - dct.__len__()):
    print(0)
