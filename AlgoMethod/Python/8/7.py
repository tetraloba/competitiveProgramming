# 2023/06/17 00:54:58
# 2023/06/17 00:57:12 AC.
class Tortoise:
    def __init__(self, name, age):
        self.name = name
        self.age = age
    def __str__(self):
        return f"name: {self.name}, age: {self.age}"
    
aruru = Tortoise("aruru", 5)
print(aruru)
