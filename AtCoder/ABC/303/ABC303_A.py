# 2023/10/30 10:50:01
# 2023/10/30 10:54:17 AC.
N = int(input())
S = input()
T = input()
for s, t in zip(S, T):
    if (s == t) or (s == '1' and t == 'l') or (s == 'l' and t == '1') or (s == '0' and t == 'o') or (s == 'o' and t == '0'):
        continue
    else:
        print('No')
        exit()
print('Yes')
