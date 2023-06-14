# 2023/06/14 09:54:39
# 2023/06/14 09:58:05 WA.
# 2023/06/14 10:03:57 AC.

# カメは全員アルファベット 5 文字の名前です
names = [ "alulu", "umumu", "namae", "totot", "irisu", "aaaaa", "mamma", "dadaa", "wowow", "kanan", "usasa", "kamem", "erina", "choco", "betty", "xoooo" ]

# アルルに似た名前を数える変数
answer_aruru = 0

# アララに似た名前を数える変数
answer_arara = 0

# アルルに似た名前とアララに似た名前を数える
for name in names:
    if name[1] == name[3]:
        if name[2] == name[4]:
            if name[0] == name[2]:
                answer_arara += 1
            answer_aruru += 1

# 答えを出力する         
print(answer_aruru)
print(answer_arara)
