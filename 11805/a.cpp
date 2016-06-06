#include <iostream>
using namespace std;

int main()
{
    int num_tcs;
    cin >> num_tcs;

    for (int tc = 1; tc <= num_tcs; tc++) {
        cout << "Case " << tc << ": ";
        int n, k, p;
        cin >> n >> k >> p;
        cout << (k - 1 + p % n) % n + 1 << endl;
    }
}
