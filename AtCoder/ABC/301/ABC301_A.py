# 2023/10/11 19:28:12
# 2023/10/11 19:34:38 AC.
N = int(input())
S = input()
cnt = [0, 0]
for c in S:
    winner = 1 if c == 'A' else 0
    cnt[winner] += 1
    if cnt[winner] >= N / 2 :
        print('T' if winner == 0 else 'A')
        break
