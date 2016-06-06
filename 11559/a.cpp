#include <iostream>
using namespace std;

int main()
{
    int n, b, h, w;
    while (cin >> n >> b >> h >> w) {
        int min_cost = -1;
        for (int i = 0; i < h; i++) {
            int cost;
            cin >> cost;
            bool viable = false;
            for (int j = 0; j < w; j++) {
                int beds;
                cin >> beds;
                if (beds >= n) {
                    viable = true;
                }
            }
            if (viable && (min_cost == -1 || min_cost > cost)) {
                min_cost = cost;
            }
        }
        if (min_cost < 0 || n * min_cost > b) {
            cout << "stay home" << endl;
        } else {
            cout << n * min_cost << endl;
        }
    }
}
