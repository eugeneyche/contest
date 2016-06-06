import sys
words = [
    ('zero', 0),
    ('one', 1),
    ('two', 2),
    ('three', 3),
    ('four', 4),
    ('five', 5),
    ('six', 6),
    ('seven', 7),
    ('eight', 8),
    ('nine', 9),
    ('ten', 10)
]

map_words_by_length = {}
for word in words:
    str_rep, value = word
    word_size = len(str_rep)
    if word_size in map_words_by_length:
        map_words_by_length[word_size].append(word)
    else:
        map_words_by_length[word_size] = [word]

def compute_diff(str1, str2):
    diff = 0
    for c1, c2 in zip(str1, str2):
        if c1 != c2:
            diff += 1
    return diff

for line in sys.stdin.readlines()[1:]:
    line = line.strip('\n')
    matches = map_words_by_length[len(line)]
    for word in matches:
        str_rep, value = word
        diff = compute_diff(line, str_rep)
        if diff <= 1:
            print(value)
            break
