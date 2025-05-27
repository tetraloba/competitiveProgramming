# 2024/11/27 15:29:29
# 2024/11/27 16:05:45 AC.
from re import findall

# 操作後にABCが増加するかどうか (pre postを逆にすると減少するかどうか)
def inc(S, idx, pre, post):
    if pre == post:
        return False
    if post == 'A' and idx + 2 < N and S[idx + 1] == 'B' and S[idx + 2] == 'C':
        return True
    if post == 'B' and 0 <= idx - 1 and idx + 1 < N and S[idx - 1] == 'A' and S[idx + 1] == 'C':
        return True
    if post == 'C' and 0 <= idx - 2 and S[idx - 2] == 'A' and S[idx - 1] == 'B':
        return True
    return False

if __name__ == '__main__':
    N, Q = map(int, input().split())
    S = input()
    numABC = len(findall('ABC', S))
    # print("numABC: ", numABC) # debug
    # print("S: ", S) # debug
    S = [c for c in S] # 文字の書き換えを可能にするため 文字の配列 (!文字列) に変換
    # print("S: ", S) # debug

    for i in range(Q):
        x, c = input().split()
        x = int(x) - 1
        if inc(S, x, S[x], c):
            numABC += 1
        if inc(S, x, c, S[x]):
            numABC -= 1
        S[x] = c
        print(numABC)

# 予めABCを数えておけば、各クエリをO(1)で処理できるな。実装面倒くさそうだけれど。 (2024/11/27 15:32:21)
