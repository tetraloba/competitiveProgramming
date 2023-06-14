# 2023/06/14 09:51:16
# 2023/06/14 09:53:35 AC.
# x ページ目に表示されるのは何位から何位までかを返す関数
def paginate(x):
    return n * x - (n - 1), n * x

# 標準入力から値を受け取る
# n: int 型
# x: int 型
n = int(input())
x = int(input())

# 答えを求め、出力する
first, last = paginate(x)
print(f"{first} ~ {last}")
