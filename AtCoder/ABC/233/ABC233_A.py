# 2023/06/22 23:54:28
# 2023/06/22 23:57:35 AC.
X, Y = map(int, input().split())
if Y < X:
    print(0)
    exit()
ans = (Y - X) // 10
if (Y - X) % 10 != 0:
    ans += 1
print(ans)
