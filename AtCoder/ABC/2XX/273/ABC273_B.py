# 2023/06/24 10:44:43
# 2023/06/24 11:02:55 AC.
from decimal import Decimal, ROUND_HALF_UP
X, K = map(int, input().split())
X_dec = Decimal(X)
for i in range(K):
    X_dec = X_dec.quantize(Decimal('1E' + str(i + 1)), rounding=ROUND_HALF_UP)
print(int(X_dec))
