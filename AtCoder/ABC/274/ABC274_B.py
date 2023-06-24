# 2023/06/24 16:23:25
# 2023/06/24 16:27:25 AC.
H, W = map(int, input().split())
X = [0] * W
for _ in range(H):
    S = input()
    for i, c in enumerate(S):
        if c == '#':
            X[i] += 1
print(*X)
