#include <iostream>
#include <cstdint>
using namespace std;

int main()
{
    uint64_t n, k;
    while (cin >> n >> k) {
        if (!n && !k) break;
        if (n < k) {
            cout << 0 << endl;
            continue;
        }
        if (n - k < k) k = n - k;
        uint64_t ni = n - k + 1;
        uint64_t ki = 2;
        uint64_t result = 1;
        while (ni <= n) {
            result *= ni++;
            while (ki <= k && result % ki == 0) {
                result /= ki++;
            }
        }
        while (ki <= k) {
            result /= ki++;
        }
        cout << result << endl;
    }
}
