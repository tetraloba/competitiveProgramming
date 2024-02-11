# 
# 2024/02/11 23:25:38 WA
N = int(input())
A = list(map(int, input().split()))
S = [A[0]]
for a in A[1:]:
    S.append(S[-1] + a)
print(S[-1] - min(S))
