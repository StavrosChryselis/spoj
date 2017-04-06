from math import sqrt

def solve(n):
    l = -1 + sqrt(1 + 8 * n)
    l /= 2

    return l

for _ in range(int(input())):
    n = int(input())
    t = solve(n)
    if t == int(t):
        print(int(t))
    else:
        print("NAI")
