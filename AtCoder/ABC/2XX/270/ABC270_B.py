# 2023/06/12 18:45:36
# 2023/06/12 18:58:17 WA.
# 2023/06/12 19:03:07 WA.
# 2023/06/12 19:08:36 AC.
X,Y,Z = map(int, input().split())
if 0 < X < Y or Y < X < 0 or X < 0 < Y or Y < 0 < X:
    print(abs(X))
elif Z < Y < 0 or 0 < Y < Z:
    print(-1)
else:
    print(abs(Z) + abs(X - Z))
