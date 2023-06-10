str = input()
if 5 <= str.__len__() <= 12 and str[0].isupper():
    print("Yes")
else:
    print("No")