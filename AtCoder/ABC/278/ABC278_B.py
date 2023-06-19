# 2023/06/19 23:57:19
# 2023/06/20 00:06:56 WA
# 2023/06/20 00:08:51 WA
# 2023/06/20 00:09:33 AC.
H, M = map(int, input().split())
while True:
    A = H // 10
    B = H % 10
    C = M // 10
    D = M % 10
    FAKE_H = A * 10 + C
    FAKE_M = B * 10 + D
    if 0 <= FAKE_H <= 23 and 0 <= FAKE_M <= 59:
        print(H, M)
        exit()
    NEW_TIME = H * 60 + M + 1
    H = NEW_TIME // 60 % 24
    M = NEW_TIME % 60
