#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> test_cases;

    int max_d = 0;
    int d;
    while (cin >> d) {
        if (d == 0) break;
        if (max_d < d)
            max_d = d;
        if (max_d < -d)
            max_d = -d;
        test_cases.push_back(d);
    }

    int max_prime = ceil(sqrt(max_d)) + 1;

    vector<bool> is_prime (max_prime);
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

    for (int i = 0; i < test_cases.size(); i++) {
        int tc = test_cases[i];
        cout << tc << " = ";
        if (-1 <= tc && tc <= 1) {
            cout << " " << tc << endl;
            continue;
        }
        bool is_first = true;
        if (tc < 0) {
            tc *= -1;
            cout << -1;
            is_first = false;
        }
        for (int j = 0; j < primes.size() && primes[j] <= tc; j++) {
            while (tc % primes[j] == 0) {
                tc /= primes[j];
                if (is_first)
                    is_first = false;
                else
                    cout << " x ";
                cout << primes[j];
            }
        }
        if (tc > 1) {
            if (!is_first)
                cout << " x ";
            cout << tc;
        }
        cout << endl;
    }
}
