#include <stdio.h>

int main()
{
    int n, k;
    while (scanf("%d%d", &n, &k) == 2) {
        long long sum = 0;
        long long cigars = n;
        long long butts = 0;
        while (cigars > 0 || butts >= k) {
            cigars += butts / k;
            butts = butts % k;
            butts += cigars;
            sum += cigars;
            cigars = 0;
        }
        printf("%lld\n", sum);
    }
}
