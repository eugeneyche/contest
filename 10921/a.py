import sys

dials = [
    ("ABC", '2'),
    ("DEF", '3'),
    ("GHI", '4'),
    ("JKL", '5'),
    ("MNO", '6'),
    ("PQRS", '7'),
    ("TUV", '8'),
    ("WXYZ", '9'),
]

mapping = {}
for s, n in dials:
    for c in s:
        mapping[c] = n

for line in sys.stdin.readlines():
    line = line.strip('\n')
    print(''.join(map(lambda c: mapping[c] if c in mapping else c, line)))
