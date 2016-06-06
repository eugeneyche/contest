#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d;
    while (cin >> a >> b >> c >> d) {
        if (!a && !b && !c && !d) break;
        int total = 360 * 3;
        int offset = (a - b) * 9;
        if (offset < 0) offset += 360;
        total += offset;
        offset = (c - b) * 9;
        if (offset < 0) offset += 360;
        total += offset;
        offset = (c - d) * 9;
        if (offset < 0) offset += 360;
        total += offset;
        cout << total << endl;
    }
}
