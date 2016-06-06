import sys

rows = [
    'qwertyuiop[]',
    'asdfghjkl;\'',
    'zxcvbnm,.'
]

mapping = {}
for row in rows:
    for i in range(2, len(row)):
        mapping[row[i]] = row[i - 2]

for line in sys.stdin.readlines():
    line = line.lower().strip('\n')
    print(''.join(map(lambda c: mapping[c] if c in mapping else c, line)))
