# 2023/06/23 12:02:36
# 2023/06/23 12:15:07 AC.
N, A, B = map(int, input().split())
S = [0] * N

for i in range(N):
    S[i] = int(input())

diff = max(S) - min(S)
if diff == 0:
    print(-1)
    exit()
P = B / diff
for i in range(N):
    S[i] *= P
Q = A - sum(S) / N
print(P, Q)
