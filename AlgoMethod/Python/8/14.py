# 2023/06/21 20:21:08
# 2023/06/21 20:28:15 AC.
class Character:
    def __init__(self, name, hp, strength):
        self.name = name
        self.hp = hp
        self.strength = strength
    def attack(self, other):
        if self.hp <= 0:
            return
        other.hp = max(0, other.hp - self.strength)

class Healer(Character):
    def __init__(self, name, hp, strength):
        super().__init__(name, hp, strength)
        self.max_hp = self.hp
    def attack(self, other):
        if self.hp <= self.max_hp / 2:
            self.hp = self.max_hp
        else:
            super().attack(other)

# HP を出力するメソッド
def print_hp(character1, character2):
    print(f"{character1.name}: {character1.hp}, {character2.name}: {character2.hp}")

# Character クラスのインスタンス aruru
aruru = Character("aruru", 60, 30)
# Healer クラスのインスタンス iruru
iruru = Healer("iruru", 70, 25)

print_hp(aruru, iruru) # HP を出力
for i in range(2): # 2 回交互に攻撃する
    aruru.attack(iruru) # aruru が iruru に攻撃する
    print(f"{aruru.name}の攻撃！")
    print_hp(aruru, iruru)
    iruru.attack(aruru) # iruru が aruru に攻撃する
    print(f"{iruru.name}の攻撃！")
    print_hp(aruru, iruru)
