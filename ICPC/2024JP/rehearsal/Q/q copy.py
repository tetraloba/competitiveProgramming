N=1
while(N!=0):
    N = int(input())
    if N==0:
        break

    # こうするとnumが整数値(int)の配列(list)になる。
    num = list(    map(int, input().split())      )

    num_t =[]
    for i in range(0,N):
        num_t.append(abs(num[i]-2023))
    mn = min(num_t)
    for i in range(0,N):
        if mn == num_t[i]:
            print(i+1)