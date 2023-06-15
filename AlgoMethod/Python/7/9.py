# 2023/06/15 20:51:38
# 2023/06/15 20:56:43 AC.
ls = [0] * (5 + 1)
S = input()
for c in S:
    ls[ord(c) - ord('0')] += 1 # pythonはint(c)で数値に直せるんだったな。
for i in range(1, 6):
    print(ls[i], end=' ') # pirnt(*ls)一発で書ける…？
print()
