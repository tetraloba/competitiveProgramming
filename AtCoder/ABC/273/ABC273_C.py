# 2023/06/24 11:49:05
# 2023/06/24 12:01:16 AC.
N = int(input())
A = list(map(int, input().split()))
A.sort(reverse=True)
current = A[0]
cnt = 1
cnt_output = 0
for i in A[1:]:
    if i == current:
        cnt += 1
    else:
        print(cnt)
        cnt_output += 1
        cnt = 1
        current = i
print(cnt)
for _ in range(N - cnt_output - 1):
    print(0)
