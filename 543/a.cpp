#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_VAL (1000000)

int main()
{
    vector<int> primes;
    bool is_prime [MAX_VAL + 1];

    fill(is_prime, is_prime + MAX_VAL + 1, true);

    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= MAX_VAL; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * 2; j <= MAX_VAL; j += i) {
                is_prime[j] = false;
            }
        }
    }

    int d;
    while (cin >> d) {
        if (d == 0) break;
        bool found = false;
        int l, r;
        for (int i = 0; i < primes.size(); i++) {
            if (primes[i] > d / 2) break;
            if (is_prime[d - primes[i]]) {
                found = true;
                l = primes[i];
                r = d - l;
                break;
            }
        }
        if (found) {
            cout << d << " = " << l << " + " << r << endl;
        } else {
            cout << "Goldbach's conjecture is wrong." << endl;
        }
    }
}
