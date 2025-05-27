# 2023/06/24 11:42:16
# 2023/06/24 11:44:27 AC.
X, K = map(int, input().split())
for i in range(K):
    X = (X + 5 * 10**i) // 10**(i + 1) * 10**(i + 1)
print(X)
