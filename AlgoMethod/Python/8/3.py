# 
# 2023/06/17 00:41:31 AC.
class Tortoise:
    name = ""
    age = 0
    def __init__(self, name, age):
        self.name = name
        self.age = age
    def introduce(self):
        print(f"{self.name} は {self.age} 歳です。")
    def aging(self):
        self.age += 1

aruru = Tortoise("aruru", 5)
aruru.introduce()
aruru.aging()
aruru.introduce()
