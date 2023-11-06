# 2023/11/06 21:34:46
# 2023/11/06 21:45:53 4WA
# 2023/11/06 22:11:57 AC.
[print(s[0] + 1, end=' ') for s in sorted({i : 10**100 * a // (a + b) for i, (a, b) in enumerate([map(int, input().split()) for _ in range(int(input()))])}.items(), key=lambda e : (-e[1], e[0]))]    
print()
