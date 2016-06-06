import sys

compressed_mapping = {
    ('BFPV', 1),
    ('CGJKQSXZ', 2),
    ('DT', 3),
    ('L', 4),
    ('MN', 5),
    ('R', 6),
}

mapping = {}
for arr, v in compressed_mapping:
    for c in arr:
        mapping[c] = str(v)

for line in sys.stdin.readlines():
    line = line.strip('\n')
    rep = []
    prev_mapped = None
    for c in line:
        if c in mapping:
            mapped = mapping[c]
            if prev_mapped != mapped:
                rep.append(mapped)
            prev_mapped = mapped 
        else:
            prev_mapped = None
    print(''.join(rep))
