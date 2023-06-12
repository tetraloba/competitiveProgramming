# 2023/06/12 17:49:10
# 2023/06/12 17:52:04 AC.
dc = {'a':'b', 'b':'c', 'c':'a'}
S = input()
T = ""
for c in S:
    T += dc[c]
print(T)
