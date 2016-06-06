#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int d;
    while (cin >> d) {
        int diag = ceil((-1 + sqrt(1 + 8 * d)) / 2);
        int r1 = d - (diag * (diag - 1)) / 2;
        int r2 = diag - r1 + 1;
        cout << "TERM " << d << " IS ";
        if (diag % 2 == 0) {
            cout << r1 << "/" << r2 << endl;
        } else {
            cout << r2 << "/" << r1 << endl;
        }
    }
}
