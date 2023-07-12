# 2023/07/12 20:17:05
# 2023/07/12 20:29:23 AC.
ans = []
for s in input():
    ans.append('9' if s == '6' else '6' if s == '9' else s)
ans.reverse()
print(''.join(ans))
