# 2023/10/11 19:35:27
# 2023/10/11 19:51:06 AC.
N = int(input())
A = list(map(int, input().split()))
for i in range(N - 1):
    print(A[i], end=' ')
    d = A[i] - A[i + 1]
    if d < -1 or 1 < d:
        b = 1 if 0 < d else -1
        while b != d:
            print(A[i] - b, end=' ')
            b += 1 if 0 < d else -1
print(A[N - 1])
exit()
