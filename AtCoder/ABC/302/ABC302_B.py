# 2023/10/13 19:22:29
# 2023/10/13 19:47:12 AC.
H, W = map(int, input().split())
S = list()
for _ in range(H):
    S.append(input())
dir8 = ((0, 1), (-1, 1), (-1, 0), (-1, -1), (0, -1), (1, -1), (1, 0), (1, 1))
tgt = "snuke"
for i in range(H):
    for j in range(W):
        if (S[i][j] != 's'):
            continue
        for k in range(8):
            for l in range(5):
                h = i + dir8[k][0] * l
                w = j + dir8[k][1] * l
                if h < 0 or H <= h or w < 0 or W <= w or S[h][w] != tgt[l]:
                    break
            else:
                for m in range(5):
                    print(i + dir8[k][0] * m + 1, j + dir8[k][1] * m + 1)

