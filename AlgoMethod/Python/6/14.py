# 2023/06/12 18:17:55
# 2023/06/12 18:20:39 AC.
poll_info = [90, 60, 240, 30, 180]
sum = 0
for num in poll_info:
    sum += num
for i, num in enumerate(poll_info):
    poll_info[i] = num * 100 // sum
print(poll_info)
