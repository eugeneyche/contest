#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int64_t a, b, c;
    while (cin >> a >> b >> c) {
        if (!a && !b && !c) break;
        vector<int64_t> sides;
        sides.push_back(a);
        sides.push_back(b);
        sides.push_back(c);
        sort(sides.begin(), sides.end());
        if (sides[0] * sides[0] + sides[1] * sides[1] == sides[2] * sides[2])
            cout << "right" << endl;
        else
            cout << "wrong" << endl;
    }
}
