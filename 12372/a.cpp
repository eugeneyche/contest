#include <iostream>
using namespace std;

int main()
{
    int num_tcs;
    cin >> num_tcs;
    for (int tc = 1; tc <= num_tcs; tc++) {
        cout << "Case " << tc << ": ";
        int l, w, h;
        cin >> l >> w >> h;
        if (l > 20 || w > 20 || h > 20) {
            cout << "bad";
        } else {
            cout << "good";
        }
        cout << endl;
    }
}
