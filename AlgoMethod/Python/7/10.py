# 2023/06/15 21:09:26
# 2023/06/15 21:10:44 AC.

# カメの名前と年齢の名簿
tortoises = [
    {"name": "aruru", "age": 5},
    {"name": "iruru", "age": 16},
    {"name": "ururu", "age": 3},
    {"name": "eruru", "age": 100}
]

# それぞれのカメについて出力
for tortoise in tortoises:
    print(f"{tortoise['name']} は {tortoise['age']} 歳です")
