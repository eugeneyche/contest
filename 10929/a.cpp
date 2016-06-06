#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string line;
    while (cin >> line) {
        if (line == "0") break;
        vector<int> digits;
        int first_nonzero = 0;
        for (int i = 0; i < line.size() - 1; i++) {
            if (line[i] != '0') break;
            first_nonzero++;
        }
        for (int i = line.size() - 1; i >= first_nonzero; i--) {
            digits.push_back(line[i] - '0');
        }
        int sub_carry = 0;
        for (int i = 1; i < digits.size(); i++) {
            digits[i] += 10 - sub_carry - digits[i - 1];
            sub_carry = (digits[i] < 10) ? 1 : 0;
            digits[i] %= 10;
        }
        if (sub_carry == 0 && digits.back() == 0) {
            cout << line << " is a multiple of 11." << endl;
        } else {
            cout << line << " is not a multiple of 11." << endl;
        }
    }
}
