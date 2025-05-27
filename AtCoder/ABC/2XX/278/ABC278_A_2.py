# 2023/06/19 23:55:10
# 2023/06/19 23:56:50 AC.
N, K = map(int, input().split())
A = list(map(int, input().split()))
for _ in range(K):
    A.pop(0)
    A.append(0)
print(*A)
