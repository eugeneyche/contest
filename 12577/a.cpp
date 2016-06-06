#include <iostream>
#include <string>
using namespace std;

int main()
{
    string line;
    int tc = 1;
    while (cin >> line) {
        if (line == "*") break;
        cout << "Case " << tc << ": ";
        if (line == "Hajj")
            cout << "Hajj-e-Akbar";
        else
            cout << "Hajj-e-Asghar";
        cout << endl;
        tc++;
    }
}
