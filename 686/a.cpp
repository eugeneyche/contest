#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    uint64_t d;
    vector<bool> is_prime ((1 << 15) + 1);
    vector<uint64_t> primes;
    fill(is_prime.begin(), is_prime.end(), true);
    is_prime[0] = is_prime[1] = false;
    for (uint64_t i = 2; i < is_prime.size(); i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (uint64_t j = 2 * i; j < is_prime.size(); j += i) {
                is_prime[j] = false;
            }
        }
    }
    while (cin >> d) {
        if (d == 0) break;
        int prime_pairs = 0;    
        for (int i = 0; i < primes.size(); i++) {
            if (primes[i] > d / 2) break;
            if (is_prime[d - primes[i]])
                prime_pairs++;
        }
        cout << prime_pairs << endl;
    }
}
