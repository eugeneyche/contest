#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool is_alpha(char c) {
    return ('A' <= c && c < 'Z') || ('a' <= c && c <= 'z');
}

int main()
{
    string line;
    vector<int> freq (256);;
    while (getline(cin, line)) {
        fill(freq.begin(), freq.end(), 0);
        int max_freq = 0;
        for (int i = 0; i < line.size(); i++) {
            char c = line[i];
            if (is_alpha(c)) {
                freq[c]++;
                if (freq[c] > max_freq)
                    max_freq = freq[c];
            }
        }
        for (char c = 'A'; c <= 'Z'; c++) {
            if (freq[c] == max_freq) {
                cout << c;
            }
        }
        for (char c = 'a'; c <= 'z'; c++) {
            if (freq[c] == max_freq) {
                cout << c;
            }
        }
        if (max_freq > 0) cout << " ";
        cout << max_freq << endl;
    }
}
