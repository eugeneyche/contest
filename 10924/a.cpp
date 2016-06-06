#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_PRIME (20 * 52)

int main()
{
    string word;
    vector<bool> is_prime (MAX_PRIME + 1);
    fill(is_prime.begin(), is_prime.end(), true);
    is_prime[0] = is_prime[1] = false;
    /* Special case for this problem */
    is_prime[1] = true;
    for (int i = 2; i < is_prime.size(); i++) {
        if (is_prime[i]) {
            for (int j = 2 * i; j < is_prime.size(); j += i) {
                is_prime[j] = false;
            }
        }
    }
    while (cin >> word) {
        int sum = 0;
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if ('a' <= c && c <= 'z') {
                sum += c - 'a' + 1;
            }
            if ('A' <= c && c <= 'Z') {
                sum += c - 'A' + 27; 
            }
        }
        if (is_prime[sum]) {
            cout << "It is a prime word." << endl;
        } else {
            cout << "It is not a prime word." << endl;
        }
    }
}
