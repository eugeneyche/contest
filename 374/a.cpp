#include <stdio.h>
#include <stdint.h>

int32_t b, p, m;
int32_t mem [46340 + 1];

int main()
{
    while (scanf("%d%d%d", &b, &p, &m) == 3) {
        int32_t pow = 0;
        int32_t num = 1;
        for (int i = 0; i < m; i++) {
            mem[i] = -1;
        }
        int it = 0;
        while (p--) {
            int prev = num;
            num = (num * (b % m)) % m;
            if (p >= m && mem[num] >= 0) {
                int cycle_len = mem[prev] - mem[num] + 1;
                p %= cycle_len;
            }
            mem[num] = it++;
        }
        printf("%d\n", num);
    }
}
