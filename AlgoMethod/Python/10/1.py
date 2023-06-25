# 2023/06/25 22:36:25
# 2023/06/25 22:38:41 AC.
# ハッシュ値を求める文字列
sentence1 = "Lorem ipsum dolor sit amet consectetur adipiscing elit sed do eiusmod tempor incididunt ut labore et dolore magna aliqua Ut enim ad minim veniam quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur Excepteur sint occaecat cupidatat non proident sunt in culpa qui officia deserunt mollit anim id est laborum"
sentence2 = "Lorem ipsum dolor sit amet consectetur adipiscing elit sed do eiusmod tempor incididunt ut labore et dolore magna aliqua Ut enim ad minim veniam quis nostrud exersitation ullamco laboris nisi ut aliquip ex ea commodo consequat Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur Excepteur sint occaecat cupidatat non proident sunt in culpa qui officia deserunt mollit anim id est laborum"

# ここに文字列のハッシュ値を求める関数を実装してください
def hash_func(S):
    sum = 0
    for c in S:
        sum += ord(c)
    return sum

# それぞれの文章のハッシュ値
hash1 = hash_func(sentence1)
hash2 = hash_func(sentence2)

# ハッシュ値を出力
print(hash1)
print(hash2)