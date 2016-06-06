#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<bool> is_prime (101);
    vector<int> primes;
    fill(is_prime.begin(), is_prime.end(), true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= 100; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = 2 * i; j <= 100; j += i) {
                is_prime[j] = false;
            }
        }
    }
    int d;
    while (cin >> d) {
        if (d == 0) break;
        cout << right << setw(3) << d << "! =";
        for (int i = 0; i < primes.size(); i++) {
            if (primes[i] > d) break;
            if (i == 15) cout << endl << "      ";
            int count = 0;
            int td = d;
            while (td) {
                td /= primes[i];
                count += td;
            }
            cout << right << setw(3) << count;
        }
        cout << endl;
    }
}
