# 2023/11/04 21:03:22
# 2023/11/04 21:05:44 WA 0か
# 2023/11/04 21:07:22 AC
B = int(input())
A = 1
while True:
    A2 = A**A
    if A2 == B:
        print(A)
        exit()
    if B <= A2:
        break
    A += 1
print(-1)
