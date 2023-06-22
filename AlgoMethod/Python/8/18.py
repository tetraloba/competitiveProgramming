# 2023/06/22 21:14:55
# 2023/06/22 21:22:28 AC.
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
    def __lt__(self, other):
        return (self - other).num < 0
    def __le__(self, other):
        return (self - other).num <= 0
    def __eq__(self, other):
        return (self - other).num == 0
    def __ne__(self, other):
        return not self == other
    def __gt__(self, other):
        return not self <= other
    def __ge__(self, other):
        return not self < other

a = MyFraction(-3, 5)
b = MyFraction(2, 3)
c = MyFraction(3, 5)
d = MyFraction(6, 10)

print(f"c == d -> {c == d}") # 出力: c == d -> True
print(f"c != d -> {c != d}") # 出力: c != d -> False
print(f"a < b -> {a < b}") # 出力: a < b -> True
print(f"b <= c -> {b <= c}") # 出力: b <= c -> False
print(f"a > d -> {a > d}") # 出力: a > d -> False
print(f"c >= d -> {c >= d}") # 出力: c >= d -> True: 
