def compute(x):
    x_2k = x * (x - 1)
    x_3k = x_2k * (x - 2)
    x_4k = x_3k * (x - 3)
    return x_4k // 4 + x_3k + x_2k // 2

while(True):
    try:
        d = int(input())
        print(compute(d + 1) - compute(1))
    except EOFError:
        break
