# 2024/02/24 18:56:11
# 2024/02/24 19:18:40 AC.
N, M = map(int, input().split())
A = list(map(int, input().split()))
dct = dict()
for a in A:
    dct[a] = dct.get(a, 0) + 1
nums = list(dct.items()) # (座標,プレゼントの個数)の配列
nums.sort()
l, r = 0, 0
cnt = 0 # 取得できるプレゼントの個数
max_cnt = 0
while l < len(nums):
    while r < len(nums) and nums[r][0] < nums[l][0] + M:
        cnt += nums[r][1]
        r += 1
    max_cnt = max(max_cnt, cnt)
    cnt -= nums[l][1]
    l += 1
print(max_cnt)
