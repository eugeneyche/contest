#include <iostream>
#include <cmath>
using namespace std;

#define MAX_N (20)

int main()
{
    int num_tcs;
    int n;

    cin >> num_tcs;
    while (num_tcs--) {
        cin >> n;
        int min_stop;
        int max_stop;
        cin >> min_stop;
        max_stop = min_stop;
        for (int i = 1; i < n; i++) {
            int stop;
            cin >> stop;
            if (stop < min_stop)
                min_stop = stop;
            if (stop > max_stop)
                max_stop = stop;
        }
        cout << 2 * (max_stop - min_stop) << endl;
    }
}
