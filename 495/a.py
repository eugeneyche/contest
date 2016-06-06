fib = [1, 1]
for i in range(2, 5001):
    fib.append(fib[-1] + fib[-2])

while True:
    try:
        d = int(input())
        print("The Fibonacci number for {} is {}".format(d, fib[d - 1] if d > 0 else 0))
    except EOFError:
        break
