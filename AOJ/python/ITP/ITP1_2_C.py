a, b, c = map(int, input().split())
if c < b:
    b, c = c, b
if b < a:
    a, b = b, a
    if c < b:
        b, c = c, b
print(f"{a} {b} {c}")