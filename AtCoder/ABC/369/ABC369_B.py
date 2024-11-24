# 2024/11/24 14:21:15
# 2024/11/24 14:41:44 AC.
K = [tuple(input().split()) for _ in range(int(input()))]
cnt_l = 0
cnt_r = 0
tire = 0
for a, s in K:
    a = int(a)
    if s == 'L':
        if cnt_l:
            tire += (l - a if a < l else a - l)
        l = a
        cnt_l += 1
    else:
        if cnt_r:
            tire += (r - a if a < r else a - r)
        r = a
        cnt_r += 1
print(tire)
