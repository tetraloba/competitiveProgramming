# 2023/06/28 10:34:32
# 2023/06/28 10:42:21 AC.
N = int(input())
A = list(map(int, input().split()))
A.sort()
cc = 0
cnt = 0
for a in A:
    if a == cc:
        cnt += 1
    else:
        cc = a
        cnt = cnt // 2 * 2 + 1
print(cnt // 2)
