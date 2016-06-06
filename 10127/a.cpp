#include <iostream>
using namespace std;

int main()
{
    int d;
    while (cin >> d) {
        int m = 0;
        int p = 0;
        int acc = 1;

        do {
            m = (m + acc) % d;
            acc = (acc * 10) % d;
            p++;
        } while (m % d != 0);

        cout << p << endl;
    }
}
