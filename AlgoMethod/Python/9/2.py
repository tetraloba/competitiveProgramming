# 2023/06/23 12:31:07
# 2023/06/23 12:38:04 AC.
import random
random.seed(42)
num = list()
for _ in range(1000):
    num.append(random.randint(1, 6))
print(num[0:10])

cnt = [0] * 7
for i in num:
    cnt[i] += 1
for i in range(1, 7):
    print(f"{i} が出た回数: {cnt[i]}")
