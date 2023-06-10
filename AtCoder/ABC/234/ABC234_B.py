# 2023/06/10 23:37:44
# 2023/06/10 23:44:11 AC.
N = int(input())
l=[]
for i in range(N):
    l.append(tuple(map(int, input().split())))
max = 0
for x1, y1 in l:
    for x2, y2 in l:
        dist = ((x2 - x1)**2 + (y2 - y1)**2)**0.5
        if max < dist:
            max = dist
print(max)