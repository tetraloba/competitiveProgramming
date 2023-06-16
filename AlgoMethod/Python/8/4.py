# 2023/06/17 00:42:42
# 2023/06/17 00:45:03 AC.
class Tortoise:
    def __init__(self, name, age):
        self.name = name
        self.age = age
    def greet(self, name):
        print(f"Hello, {name}! I'm {self.name}.")

aruru = Tortoise("aruru", 5)
aruru.greet("iruru")
