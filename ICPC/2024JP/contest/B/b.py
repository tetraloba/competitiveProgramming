N = 0
while (1):
    N = int(input())
    if N == 0:
        break
    num_a = list(map(int, input().split()))
    num_b = list(map(int, input().split()))

    count = 0
    sum_a = 0
    sum_b = 0
    j=0
    for i in range(0,N):
        sum_a = sum_a + num_a[i]
        sum_b = sum_b + num_b[i]
        if sum_a > sum_b:
            if j==2:
                count+=1
            j=1
        if sum_a < sum_b:
            if j==1:
                count+=1
            j=2
    print(count)
    