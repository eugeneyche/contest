#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a, b;
    while (cin >> a >> b) {
        if (!a && !b) break;
        int below = ceil(sqrt(a));
        int above = floor(sqrt(b));
        cout << above - below + 1 << endl;
    }
}
