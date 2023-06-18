# 2023/06/18 21:52:36
# 2023/06/18 21:55:47 AC.
class Character:
    def __init__(self, name, hp, strength):
        self.name = name
        self.hp = hp
        self.strength = strength

aruru = Character("aruru", 50, 20)
print(f"name: {aruru.name}, hp: {aruru.hp}, strength: {aruru.strength}")
