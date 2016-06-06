#include <iostream>
#include <cstdint>
using namespace std;

#define MAX_N (500)

int gcd(int a, int b) {
    if (a < b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    while (b) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int main()
{
    uint64_t mem [MAX_N + 1];
    mem[0] = 0;
    mem[1] = 0;
    for (int i = 2; i <= MAX_N; i++) {
        mem[i] = mem[i - 1];
        for (int j = 1; j < i; j++) {
            mem[i] += gcd(i, j);
        }
    }
    int d;
    while (cin >> d) {
        if (d == 0) break;
        cout << mem[d] << endl;
    }
}
