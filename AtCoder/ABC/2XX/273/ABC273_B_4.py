# 2023/06/24 11:45:16
# 2023/06/24 11:46:16 AC.
X, K = map(int, input().split())
for i in range(K):
    t = X + 5 * 10**i
    X = t - t % 10**(i + 1)
print(X)
