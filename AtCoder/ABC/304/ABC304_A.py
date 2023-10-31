# 2023/10/31 21:05:54
# 2023/10/31 21:13:02 AC.
N = int(input())
l = list()
for i in range(N):
    l.append(tuple(input().split()))
min_age_i = 0
for i in range(N):
    if int(l[i][1]) < int(l[min_age_i][1]):
        min_age_i = i
for i in range(min_age_i, N):
    print(l[i][0])
for i in range(0, min_age_i):
    print(l[i][0])
exit()
