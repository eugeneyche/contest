#include <iostream>
#include <unordered_map>
#include <cstdint>
using namespace std;

uint64_t ackerman(uint64_t n, bool first = true) {
    static unordered_map<uint64_t, uint64_t> mem;
    if (!first) {
        if (n == 1) return 0;
        unordered_map<uint64_t, uint64_t>::iterator it = mem.find(n);
        if (it != mem.end())
            return it->second;
    }
    uint64_t result;
    if (n % 2 == 0) {
        result = ackerman(n / 2, false) + 1;
    } else {
        result = ackerman(3 * n + 1, false) + 1;
    }
    mem[n] = result;
    return result;
}

int main()
{
    uint64_t lo, hi;
    while (cin >> lo >> hi) {
        if (lo == 0 && hi == 0) break;
        if (lo > hi) {
            uint64_t tmp = lo;
            lo = hi;
            hi = tmp;
        }
        cout << "Between " << lo << " and " << hi << ", ";
        uint64_t max_n = lo;
        uint64_t max_len = ackerman(lo);
        for (uint64_t i = lo + 1; i <= hi; i++) {
            uint64_t len = ackerman(i); 
            if (len > max_len) {
                max_n = i;
                max_len = len;
            }
        }
        cout << max_n << " generates the longest sequence of "
            << max_len << " values." << endl;
    }
}
