# 2023/10/11 19:51:43
# 2023/10/11 20:38:37 AC.
S = input()
T = input()
S_cnt = dict()
T_cnt = dict()
for s in S:
    S_cnt[s] = S_cnt.get(s, 0) + 1
for t in T:
    T_cnt[t] = T_cnt.get(t, 0) + 1
# print(S_cnt, T_cnt)
for key, value in S_cnt.items():
    # print(key, value)
    if key == '@':
        T_cnt[key] = T_cnt.get(key, 0) + value
    else:
        T_cnt[key] = T_cnt.get(key, 0) - value
# print(T_cnt)
remain_cnt = 0
for value in T_cnt.values():
    remain_cnt += abs(value)
for key, value in T_cnt.items():
    if value != 0 and key != '@' and key not in 'atcoder':
        print('No')
        exit()
print('Yes' if remain_cnt / 2 <= T_cnt.get('@', 0) else 'No')
