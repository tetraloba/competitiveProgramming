# None
# 2023/06/10 23:37:27 AC.
def f(x):
    return x ** 2  + 2 * x + 3
t = int(input())
print(f(f(f(t) + t) + f(f(t))))