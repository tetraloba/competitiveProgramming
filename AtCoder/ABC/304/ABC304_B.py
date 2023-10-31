# 2023/10/31 21:13:34
# 2023/10/31 21:22:52 AC.
from numpy import log10
N = int(input())
if N <= 1000 - 1:
    print(N)
    exit()
print(N // 10**(int(log10(N))-2) * 10**(int(log10(N))-2))
