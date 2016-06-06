#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Case {
    int n, c;
};

int impl_bin_search(int target, const vector<int>& vec, int left, int right) {
    if (right - left == 1) {
        if (target < vec[left])
            return left;
        else
            return right;
    }
    int mid = left + (right - left) / 2;
    if (target < vec[mid]) {
        return impl_bin_search(target, vec, left, mid);
    } else {
        return impl_bin_search(target, vec, mid, right);
    }
}

int bin_search(int target, const vector<int>& vec) {
    return impl_bin_search(target, vec, 0, vec.size());
}

int main() 
{
    vector<Case> cs;

    int max_n = 0;
    Case c;
    while (cin >> c.n >> c.c) {
        if (c.n > max_n)
            max_n = c.n;
        cs.push_back(c);    
    }
    vector<bool> is_prime (max_n + 1);
    vector<int> primes;
    fill(is_prime.begin(), is_prime.end(), true);
    is_prime[0] = is_prime[1] = false;
    // Special case with 1
    is_prime[1] = true;
    primes.push_back(1);
    for (int i = 2; i < is_prime.size(); i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = 2 * i; j < is_prime.size(); j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 0; i < cs.size(); i++) {
        int prime_size = bin_search(cs[i].n, primes);
        int prime_begin;
        int prime_end;
        int mid = prime_size / 2;
        if (prime_size % 2 == 0) {
            prime_begin = mid - cs[i].c;
            prime_end = mid + cs[i].c;
        } else {
            prime_begin = mid - cs[i].c + 1;
            prime_end = mid + cs[i].c;
        }
        if (prime_begin < 0)
            prime_begin = 0;
        if (prime_end > prime_size)
            prime_end = prime_size;
        cout << cs[i].n << " " << cs[i].c << ": ";
        for (int j = prime_begin; j < prime_end; j++) {
            if (j != prime_begin) cout << " ";
            cout << primes[j];
        }
        cout << endl;
        cout << endl;
    }
}
