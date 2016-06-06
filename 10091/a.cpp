#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int b1, b2;
        int dec, hex;
        cin >> dec;
        hex = 0;
        int tdec = dec;
        while (tdec) {
            hex = hex * 16 + tdec % 10;
            tdec /= 10;
        }
        b1 = 0;
        while (dec) {
            dec -= dec & -dec;
            b1++;
        }
        b2 = 0;
        while (hex) {
            hex -= hex & -hex;
            b2++;
        }
        cout << b1 << " " << b2 << endl;
    }
}
