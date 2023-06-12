# 2023/06/12 17:02:11
# 2023/06/12 17:03:36 AC.
numbers_dict = {
    "one": 1, "two": 2, "three": 3, "four": 4, "five": 5,
    "six": 6, "seven": 7, "eight": 8, "nine": 9, "ten": 10
}
S = input()
if S in numbers_dict:
    print(numbers_dict[S])
else:
    print(-1)
