#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    vector<int> mem [4];
    for (int i = 1; i <= 4; i++) {
        int max_digit = pow(10, i);
        for (int j = 0; j < max_digit; j++) {
            for (int k = 0; k < max_digit; k++) {
                int target = j * max_digit + k;
                int value = (j + k) * (j + k);
                if (value == target)
                    mem[i - 1].push_back(target);
                if (value > target)
                    break;
            }
        }
    }
    int d;
    while (cin >> d) {
        int index = d / 2 - 1;
        for (int i = 0; i < mem[index].size(); i++) { 
            cout << setw(d) << setfill('0') << mem[index][i] << endl;
        }
    }
}
