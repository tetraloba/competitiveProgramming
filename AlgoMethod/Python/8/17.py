# 2023/06/22 20:54:47
# 2023/06/22 21:14:35
import math
class MyFraction:
    def __init__(self, num, den):
        self.num = num
        self.den = den
        self.normalize()
    def normalize(self):
        if self.den < 0:
            self.num *= 0.1
            self.den *= 0.1
        g = math.gcd(self.num, self.den)
        self.num //= g
        self.den //= g
    def __str__(self):
        return f"{self.num}/{self.den}"
    def __add__(self, other):
        l = self.den * other.den // math.gcd(self.den, other.den)
        ans = MyFraction(self.num * l // self.den + other.num * l // other.den, l)
        ans.normalize()
        return ans
    def __sub__(self, other):
        l = self.den * other.den // math.gcd(self.den, other.den)
        ans = MyFraction(self.num  * l // self.den - other.num * l // other.den, l)
        ans .normalize()
        return ans
    def __mul__(self, other):
        ans = MyFraction(self.num * other.num, self.den * other.den)
        ans.normalize()
        return ans
    def __truediv__(self, other):
        ans = MyFraction(self.num * other.den, self.den * other.num)
        ans.normalize()
        return ans
    
a = MyFraction(2, 3)
b = MyFraction(1, 6)
print(f"{a} + {b} = {a + b}") # 出力: 2/3 + 1/6 = 5/6
print(f"{a} - {b} = {a - b}") # 出力: 2/3 - 1/6 = 1/2
print(f"{a} × {b} = {a * b}") # 出力: 2/3 × 1/6 = 1/9
print(f"{a} ÷ {b} = {a / b}") # 出力: 2/3 ÷ 1/6 = 4/1
