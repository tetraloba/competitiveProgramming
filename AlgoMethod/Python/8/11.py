# 2023/06/18 21:50:41
# 2023/06/18 21:51:59 AC.
class Tortoise:
    def __init__(self, name, age):
        self.name = name
        self.age = age
    def introduce(self):
        print(f"{self.name} は {self.age} 歳です。")
    def aging(self):
        self.age += 1

class TortoiseWizard(Tortoise): # Tortoise クラスを継承するクラス
    def set_age(self, age):
        self.age = age

iruru = TortoiseWizard("iruru", 16)
iruru.introduce()
iruru.set_age(3)
iruru.introduce()