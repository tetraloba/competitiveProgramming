# 2023/06/12 18:23:09
# 2023/06/12 18:26:03 AC.
person_info = [
    {"name": "aruru", "height": 1.7, "weight": 70.0},
    {"name": "iruru", "height": 1.6, "weight": 65.0},
    {"name": "ururu", "height": 1.8, "weight": 70.0},
    {"name": "eruru", "height": 1.5, "weight": 40.0}
]
for pi in person_info:
    pi["BMI"] = round(pi["weight"] / pi["height"]**2, 1)
print(person_info)
