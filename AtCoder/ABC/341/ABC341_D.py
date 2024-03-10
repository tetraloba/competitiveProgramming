# 2024/03/10 18:41:00
# 2024/03/10 19:20:25 WA
# 2024/03/10 19:23:48 WA
# 2024/03/10 20:10:39 AC.
from math import lcm
N, M, K = map(int, input().split())
l = 0
r = 18446744073709551615
while l < r:
    m = (l + r) // 2
    # print(l, m, r) # debug
    num = m // N + m // M - m // lcm(N, M) * 2
    if num < K:
        l = m + 1
    elif K < num:
        r = m - 1
    else:
        r = m
print(int((l + r) // 2))

# X以下の自然数において NとMのいずれか一方でのみ割り切れる数の数は
# X / N + X / M - X / (N * M)
# Xを二分探索してそこから動かせば早いかな。
