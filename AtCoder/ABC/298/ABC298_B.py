# 2023/11/03 12:14:39
# 2023/11/03 12:39:28 AC.
N = int(input())
A = list()
for _ in range(N):
    A.append(list(map(int, input().split())))
B = list()
for _ in range(N):
    B.append(list(map(int, input().split())))

for _ in range(4):
    flag = True
    for a_l, b_l in zip(A, B):
        for a, b in zip(a_l, b_l):
            if a == 1 and b != 1:
                flag = False
    if flag:
        print("Yes")
        exit()
    C = [[0 for _ in range(N)] for _ in range(N)]
    for i in range(N):
        for j in range(N):
            C[i][j] = A[N - 1 - j][i]
    A = C
print("No")
