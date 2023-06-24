# 2023/06/24 11:09:22
# 2023/06/24 11:14:58 AC.
X, K = map(int, input().split())
for i in range(K):
    t = X * 2 // 10**(i + 1)
    X = (t // 2 + t % 2) * 10**(i + 1)
print(X)
