#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

struct Case {
    int lo;
    int hi;
};

int compute_num_factors(int n, const vector<int>& primes) {
    int factors = 1;
    for (int i = 0; i < primes.size(); i++) {
        if (primes[i] > n) break;
        int count = 0;
        while (n % primes[i] == 0) {
            n /= primes[i];
            count++;
        }
        factors *= count + 1;
    }
    if (n > 1) {
        factors *= 2;
    }
    return factors;
}

int main()
{
    int num_tc;
    int max_hi = 0;
    vector<Case> cases;
    
    cin >> num_tc;
    while (num_tc--) {
        Case c;
        cin >> c.lo >> c.hi;
        if (c.hi > max_hi)
            max_hi = c.hi;
        cases.push_back(c);
    }

    max_hi = 50;
    int max_in = ceil(sqrt(max_hi));

    vector<bool> is_prime (max_in + 1000);
    vector<int> primes;

    fill(is_prime.begin(), is_prime.end(), true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i < is_prime.size(); i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = 2 * i; j < is_prime.size(); j += i) {
                is_prime[j] = false;
            }
        }
    }

    for (int i = 0; i < cases.size(); i++) {
        int max_number = cases[i].lo;
        int max_num_factors = compute_num_factors(max_number, primes);
        for (int j = cases[i].lo + 1; j <= cases[i].hi; j++) {
            int num_factors = compute_num_factors(j, primes);
            if (num_factors > max_num_factors) {
                max_number = j;
                max_num_factors = num_factors;
            }
        }
        cout << "Between " << cases[i].lo
            << " and " << cases[i].hi
            << ", " << max_number
            << " has a maximum of " << max_num_factors
            << " divisors." << endl;
    }
}
