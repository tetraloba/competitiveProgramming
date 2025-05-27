# 2023/06/24 18:58:43
# 2023/06/24 19:03:38 AC.
S = int(input())
AA = S // 100
BB = S % 100
if 1 <= BB <= 12 and 1 <= AA <= 12:
    print('AMBIGUOUS')
elif 1 <= BB <= 12:
    print('YYMM')
elif 1 <= AA <= 12:
    print('MMYY')
else:
    print('NA')
