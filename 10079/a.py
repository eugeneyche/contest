while True:
    n = int(input())
    if n < 0:
        break
    print(1 + n * (n + 1) // 2)
