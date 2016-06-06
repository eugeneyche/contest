#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string a, b;
    vector<int> a_rep (26), b_rep (26);
    while (getline(cin, a) && getline(cin, b)) {
        fill(a_rep.begin(), a_rep.end(), 0);
        fill(b_rep.begin(), b_rep.end(), 0);
        for (int i = 0; i < a.size(); i++) {
            a_rep[a[i] - 'a']++;
        }
        for (int i = 0; i < b.size(); i++) {
            b_rep[b[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            int min_rep = a_rep[i];
            if (b_rep[i] < min_rep)
                min_rep = b_rep[i];
            if (min_rep > 0) {
                char c = 'a' + i;
                for (int j = 0; j < min_rep; j++) {
                    cout << c;
                }
            }
        }
        cout << endl;
    }
}
