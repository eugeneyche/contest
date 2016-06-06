#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int d;
    while (cin >> d) {
        if (d == 0) break;
        int count = 0;
        int td = d;
        cout << "The parity of ";
        string rep = "";
        while (td) {
            if (td & 1) 
                count++;
            rep += td & 1 ? '1' : '0';
            td >>= 1;
        }
        reverse(rep.begin(), rep.end());
        cout << rep
            << " is " << count 
            << " (mod 2)." << endl;
    }
}
