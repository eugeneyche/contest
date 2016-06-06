#include <iostream>
using namespace std;

int T;
int N;
int hi, lo, mario, prev_mario;

int main() 
{
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N;
        hi = 0;
        lo = 0;
        if (N > 0) {
            cin >> prev_mario; N--;
            while (N--) {
                cin >> mario;
                if (mario < prev_mario)
                    lo++;
                if (mario > prev_mario)
                    hi++;
                prev_mario = mario;
            }
        }
        cout << "Case " << t << ": " << hi << " " << lo << endl;
    }
}
