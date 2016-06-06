#include <stdio.h>
#include <algorithm>

#define ABS(x) ((x) >= 0 ? (x) : -(x))

int t;
int r;
int med;
int sum;
int as [500];

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &r);
        for (int i = 0; i < r; i++) {
            scanf("%d", as + i);
        }
        std::sort(as, as + r);
        med = as[r / 2];
        sum = 0;
        for (int i = 0; i < r; i++) {
            sum += ABS(med - as[i]);
        }
        printf("%d\n", sum);
    }
}
