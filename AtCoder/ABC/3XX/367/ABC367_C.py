# 2024/11/29 17:57:13
# 2024/11/29 18:43:32 AC.
def base5plus1(n):
    l = list()
    for _ in range(N):
        l.append(n % 5 + 1)
        n //= 5
    return l[::-1]
def base5toint(l):
    r = 0
    for i in l:
        r = r * 10 + i
    return r
def checkR(l):
    for i in range(len(l)):
        if R[i] < l[i]:
            return False
    return True
def printf(n):
    l = list()
    for _ in range(N):
        l.append(n % 10)
        n //= 10
    for i in l[::-1]:
        print(i, end=' ')
    print()
N, K = map(int, input().split())
R = list(map(int, input().split()))
A = [1] * N
ans = list()
for i in range(5**N):
    A = base5plus1(i)
    if not checkR(A):
        continue
    if sum(A) % K:
        continue
    # print(A)
    ans.append(base5toint(A))
ans = sorted(ans)
for a in ans:
    printf(a)

# 5^8 = 390,625
# 全探索で行けるか… (2024/11/29 18:20:28)
