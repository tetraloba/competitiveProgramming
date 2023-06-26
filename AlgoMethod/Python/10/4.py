# 2023/06/26 13:28:11
# 2023/06/26 13:29:58 AC.

import copy # copy モジュールを読み込む

a = [3, 1, 4, 1, 5]       # リスト型変数
a_shallow = a             # a を参照渡しした変数
a_deep = copy.deepcopy(a) # a を値渡しした変数
print('True' if a_shallow is a else 'False')
print('True' if a_deep is a else 'False')
