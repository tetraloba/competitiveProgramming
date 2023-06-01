W, H, x, y, r = map(int, input().split())
if 0 + r <= x and x <= W - r and 0 + r <= y and y <= H - r:
    print("Yes")
else:
    print("No")