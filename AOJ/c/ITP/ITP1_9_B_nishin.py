while True:
    S = input()
    if S == "-": break
    m = int(input())
    start_idx = 0
    for i in range(m):
        start_idx += int(input())
    print(S[start_idx%len(S):] + S[:start_idx%len(S)])