# 2023/06/23 12:42:52
# 2023/06/23 12:46:36 AC.
import itertools
for i, j, k in itertools.product(range(1, 21), repeat=3):
    if i**2 + j**2 == k**2:
        print(i, j, k)
