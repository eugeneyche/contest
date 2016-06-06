#include <stdio.h>
#include <stdint.h>

uint64_t n;

int main()
{
    while (scanf("%lld", &n) == 1) {
        if (n == 0)
            break;
        while (n >= 10) {
            int sum = 0;
            while (n > 0) {
                sum += n % 10;
                n /= 10;
            }
            n = sum;
        }
        printf("%lld\n", n);
    }
}
