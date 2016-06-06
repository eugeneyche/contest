#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int ts;
int n;
int arr [10000];

int main()
{
    cin >> ts;
    cin.ignore(BUFSIZ, '\n');
    for (int t = 1; t <= ts; t++) {
        string line;
        getline(cin, line);
        stringstream line_stream (line);
        int d, mx;
        if (!(line_stream >> mx)) {
            mx = 0;
        } else {
            while (line_stream >> d) {
                if (d > mx) mx = d;
            }
        }
        std::cout << "Case " << t << ": " << mx << std::endl;
    }
}
