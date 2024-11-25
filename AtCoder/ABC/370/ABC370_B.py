# 2024/11/25 09:58:27
# 2024/11/25 10:22:30 AC.
N = int(input())
A = list()
for r in range(N):
    A.append(list(map(int, input().split())))
ans = 0
for i in range(N):
    if ans < i:
        tmp = ans
        ans = i
        i = tmp
    ans = A[ans][i] - 1
print(ans + 1)
