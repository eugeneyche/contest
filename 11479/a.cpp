#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
using namespace std;

int main()
{
    int num_tcs;
    vector<int64_t> sides (3);

    cin >> num_tcs;
    for (int tc = 1; tc <= num_tcs; tc++) {
        cin >> sides[0] >> sides[1] >> sides[2];;
        sort(sides.begin(), sides.end());
        cout << "Case " << tc << ": ";
        if (sides[0] + sides[1] <= sides[2] ||
                sides[0] <= 0 ||
                sides[1] <= 0 ||
                sides[2] <= 0) {
            cout << "Invalid";
        } else if (sides[0] == sides[1] && sides[1] == sides[2]) {
            cout << "Equilateral";
        } else if (sides[0] == sides[1] || sides[1] == sides[2]) {
            cout << "Isosceles";
        } else {
            cout << "Scalene";
        }
        cout << endl;
    }
}
