# 2023/06/19 23:50:55
# 2023/06/19 23:54:55 WA.
N, K = map(int, input().split())
A = list(map(int, input().split()))
print(*A[K:], end=' ')
for _ in range(K):
    print(0, end=' ')
print()
