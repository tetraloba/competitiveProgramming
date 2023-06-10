A,B,C = list(map(int, input().split()))
if A <= B and B < C:
    print("Yes")
else:
    print("No")
# 改行区切りだからinput().split()では上手くいかない。