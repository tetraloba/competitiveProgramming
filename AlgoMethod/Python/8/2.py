# 2023/06/17 00:35:54
# 2023/06/17 00:39:13 AC.
class Tortoise:
    name = ""
    age = 0
    def __init__(self, name, age):
        self.name = name
        self.age = age
    def say(self):
        print(f"{self.name} は {self.age} 歳です。")
aruru = Tortoise("aruru", 5)
iruru = Tortoise("iruru", 16)
ururu = Tortoise("ururu", 3)
eruru = Tortoise("eruru", 100)
aruru.say()
iruru.say()
ururu.say()
eruru.say()
