# 2023/06/17 20:52:03
# 2023/06/17 20:58:00 AC.
S = input()
flag = False
for i in range(S.__len__()):
    if flag:
        if S[i] == 'h':
            flag = False
            continue
        else:
            print('NO')
            exit()
    if S[i] == 'c':
        flag = True
    elif S[i] != 'o' and S[i] != 'k' and S[i] != 'u':
        print('NO')
        exit()
print('YES')
