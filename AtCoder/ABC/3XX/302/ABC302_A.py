# 2023/10/13 19:19:42
# 2023/10/13 19:22:09 AC.
A, B = map(int, input().split())
print(A // B + (1 if 0 < A % B else 0))
