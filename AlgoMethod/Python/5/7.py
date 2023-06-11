# 2023/06/11 09:08:55
# 2023/06/11 09:10:44 AC.
X = 27
cnt = 0
while X != 1:
    if X % 2 == 1:
        X = X * 3 + 1
    else:
        X //= 2
    cnt += 1
print(cnt)
