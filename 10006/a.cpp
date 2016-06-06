#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
using namespace std;

bool check_fermat(int a, int n) {
    uint64_t leftover_pow = n;
    uint64_t cur_pow = a;
    uint64_t result = 1;
    while (leftover_pow) {
        if (leftover_pow & 1)
            result = (result * cur_pow) % n;
        leftover_pow >>= 1;
        cur_pow = (cur_pow * cur_pow) % n;
    }
    return result == a;
}

int main()
{
    vector<int> test_cases;
    int max_test_case = 0;

    int d;
    while (cin >> d) {
        if (d == 0) break;
        if (max_test_case < d)
            max_test_case = d;
        test_cases.push_back(d);
    }

    vector<bool> is_prime (max_test_case + 1);
    fill(is_prime.begin(), is_prime.end(), true);
    is_prime[0] = is_prime[1] = false;
    // Special case
    is_prime[1] = true;
    for (int i = 2; i < is_prime.size(); i++) {
        if (is_prime[i]) {
            for (int j = 2 * i; j < is_prime.size(); j += i) {
                is_prime[j] = false;
            }
        }
    }

    for (int i = 0; i < test_cases.size(); i++) {
        int test_case = test_cases[i];
        if (is_prime[test_case]) {
            cout << test_case << " is normal." << endl;
        } else {
            bool is_car = true;
            for (int j = 2; j < test_case; j++) {
                if (!check_fermat(j, test_case)) {
                    is_car = false;
                    break;
                }
            }
            if (is_car) {
                cout << "The number " << test_case << " is a Carmichael number." << endl;
            } else {
                cout << test_case << " is normal." << endl;
            }
        }
    }
}
