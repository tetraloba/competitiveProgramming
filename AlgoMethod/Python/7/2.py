# 2023/06/13 13:07:55
# 2023/06/13 13:10:11 AC.

# 標準入力から値を受け取る
# month: int 型
month = int(input())

# month の値で場合分けし、答えを出力する
if month == 2:
    print(28)
elif month == 4 or month == 6 or month == 9 or month == 11:
    print(30)
else:
    print(31)
