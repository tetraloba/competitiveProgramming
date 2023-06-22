# 2023/06/22 20:43:11
# 2023/06/22 20:54:27 AC.
import math
class MyFraction:
    def __init__(self, num, den):
        self.num = num
        self.den = den
        self.normalize()
    def normalize(self):
        if self.den < 0:
            self.num *= -1
            self.den *= -1
        g = math.gcd(self.num, self.den)
        self.num //= g
        self.den //= g
    def __str__(self):
        return f"{self.num}/{self.den}"
    
a = MyFraction(3, 4)
print(a) # 出力: 3/4

b = MyFraction(6, 8)
print(b) # 出力: 3/4

c = MyFraction(9, -6)
print(c) # 出力: -3/2

d = MyFraction(-10, -5)
print(d) # 出力: 2/1
