#include <iostream>
#include <cstdint>
using namespace std;

int main()
{
    int64_t d;
    while (cin >> d) {
        if (d == 1) {
            cout << 1 << endl;
            continue;
        }
        int64_t row = d / 2 + 1;
        int64_t first_num = 2 * (row * row - 2) - 1;
        int64_t total = first_num * 3 + 6;
        cout << total << endl;
    }
}
