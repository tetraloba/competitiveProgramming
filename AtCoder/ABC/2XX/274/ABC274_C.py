# 2023/06/24 16:27:43
# 2023/06/24 16:38:03 AC.
N = int(input())
A = map(int, input().split())
V = [0] * (1 + N * 2)
V[0] = 0
for i, a in enumerate(A):
    V[2 * (i + 1) - 1] = V[a - 1] + 1
    V[2 * (i + 1)] = V[a - 1] + 1
for i in V:
    print(i)
