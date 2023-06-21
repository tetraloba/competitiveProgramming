# 2023/06/21 20:29:39
# 2023/06/21 20:31:26 AC.
class MyFraction:
    def __init__(self, num, den):
        self.num = num
        self.den = den
    def __str__(self):
        return f'{self.num}/{self.den}'
    
a = MyFraction(3, 4)
print(a) # "3/4" が出力されるようにする
