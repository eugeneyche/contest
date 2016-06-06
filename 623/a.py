import sys

cases = list(map(int, sys.stdin.readlines()))
max_case = max(cases)

fact = [1]
for i in range(1, max_case + 1):
    fact.append(fact[-1] * i)

for case in cases:
    print("{}!".format(case))
    print(fact[case])
