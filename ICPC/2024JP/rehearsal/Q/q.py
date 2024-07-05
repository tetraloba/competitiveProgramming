N=1
while(N!=0):
    N = int(input())
    if N==0:
        break
    num = input()
    num_s = num.split(" ")
    num_t =[]
    for i in range(0,N):
        num_t.append((int(num_s[i])-2023)**2)
    mn = min(num_t)
    for i in range(0,N):
        if mn == num_t[i]:
            print(i+1)