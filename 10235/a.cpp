#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int reverse_int(int n) {
    int result = 0;
    while (n) {
        result = result * 10 + n % 10;
        n /= 10;
    }
    return result;
}

struct TestCase {
    int n;
    int reversed_n;
};

int main() 
{
    vector<TestCase> test_cases;
    int max_n_or_reversed_n = 0;

    TestCase tc;
    while (cin >> tc.n) {
        tc.reversed_n = reverse_int(tc.n);
        if (tc.n > max_n_or_reversed_n)
            max_n_or_reversed_n = tc.n;
        if (tc.reversed_n > max_n_or_reversed_n)
            max_n_or_reversed_n = tc.reversed_n;
        test_cases.push_back(tc);
    }
    
    vector<bool> is_prime (max_n_or_reversed_n + 1);
    fill(is_prime.begin(), is_prime.end(), true);
    is_prime[0] = false;
    for (int i = 2; i < is_prime.size(); i++) {
        if (is_prime[i]) {
            for (int j = 2 * i; j < is_prime.size(); j += i) {
                is_prime[j] = false;
            }
        }
    }

    for (int i = 0; i < test_cases.size(); i++) {
        const TestCase& tc = test_cases[i];
        cout << tc.n;
        if (tc.n % 10 == 0) {
            cout << " is not prime.";
        } else if (tc.reversed_n != tc.n && is_prime[tc.n] && is_prime[tc.reversed_n]) {
            cout << " is emirp.";
        } else if (is_prime[tc.n]) {
            cout << " is prime.";
        } else {
            cout << " is not prime.";
        }
        cout << endl;
    }
}
