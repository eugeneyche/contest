#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    while (cin >> n) {
        if (n == 0) break;
        int vp [100];
        int hp [100];
        fill(vp, vp + n, 0);
        fill(hp, hp + n, 0);
        int d;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> d;
                vp[i] += d;
                hp[j] += d;
            }
        }
        int vi = -1;
        int hi = -1;
        bool corrupt = false; 
        for (int i = 0; i < n; i++) {
            if (vp[i] % 2 != 0) {
                if (vi == -1) {
                    vi = i;
                } else {
                    corrupt = true;
                    break;
                }
            }
            if (hp[i] % 2 != 0) {
                if (hi == -1) {
                    hi = i;
                } else {
                    corrupt = true;
                    break;
                }
            }
        }
        if (corrupt) {
            cout << "Corrupt" << endl;
        } else if (vi != -1 && hi != -1) {
            cout << "Change bit (" << vi + 1 << "," << hi + 1 << ")" << endl;
        } else {
            cout << "OK" << endl;
        }
    }
}
