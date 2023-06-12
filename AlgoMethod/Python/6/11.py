# 2023/06/12 17:52:39
# 2023/06/12 18:01:30 AC.
def func(S):
    T = ""
    dc = {'a':'b', 'b':'c', 'c':'a'}
    for c in S:
        T += dc[c]
    return T
S = input()
T = func(S)
U = func(T)
V = func(U)
print(T)
print(U)
print(V)
# 関数の引数の参照渡しとかの概念が…
# イミュータブルなオブジェクトでも参照渡しではあるが、変更した時点で新しいオブジェクトが作られる実質的な値渡し・・・