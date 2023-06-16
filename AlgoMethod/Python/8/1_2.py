# 2023/06/17 00:27:53
# 2023/06/17 00:35:34 AC.
class Tortoise:
    name = ""
    age = 0
    def __init__(self, name, age):
        self.name = name
        self.age = age
    def say(self):
        print(eruru.name,'は',eruru.age,'歳です。')

eruru = Tortoise("eruru", 100)
eruru.say()
