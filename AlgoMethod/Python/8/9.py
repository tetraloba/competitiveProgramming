# 2023/06/18 21:43:00
# 2023/06/18 21:47:19 AC.
class Pair:
    def __init__(self, first, second):
        self.first = first
        self.second = second
    def __eq__(self, other):
        return self.first == other.first and self.second == other.second
    def __lt__(self, other):
        return self.first < other.first or (self.first == other.first and self.second < other.second)
a = Pair(2, 3)
b = Pair(1, 4)
c = Pair(1, 3)
print(a < b)
print(b < c)
print(c < b)
