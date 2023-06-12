# 2023/06/12 18:09:40
# 2023/06/12 18:16:13 AC.
S = input()
key = 3
key %= 26
T = ""
for c1 in S:
    c2 = chr(ord(c1) - key)
    if ord(c2) < ord('a') or ord('z') < ord(c2):
        c2 = chr(ord(c2) + 26)
    T += c2
print(T)
