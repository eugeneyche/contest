#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int d;
    vector<int> digits;
    while (cin >> d) {
        if (d < 0) break;
        if (d == 0) {
            cout << 0 << endl;
            continue;
        }
        digits.clear();        
        while (d) {
            digits.push_back(d % 3);
            d /= 3;
        }
        for (int i = digits.size(); i > 0; i--) {
            cout << digits[i - 1];
        }
        cout << endl;
    }
}
