#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int compute_name_to_value(const string& name) {
    int total = 0;
    for (int i = 0; i < name.size(); i++) {
        if ('a' <= name[i] && name[i] <= 'z') {
            total += name[i] - 'a' + 1;
        } else if ('A' <= name[i] && name[i] <= 'Z') {
            total += name[i] - 'A' + 1;
        }
    }
    while (total >= 10) {
        int sum = 0;
        while (total) {
            sum += total % 10;
            total /= 10;
        }
        total = sum;
    }
    return total;
}

int main()
{
    string name1, name2;
    while (getline(cin, name1) && getline(cin, name2)) {
        int value1 = compute_name_to_value(name1);
        int value2 = compute_name_to_value(name2);
        if (value2 > value1) {
            int tmp = value1;
            value1 = value2;
            value2 = tmp;
        }
        if (value1 == 0 && value2 == 0) {
            cout << endl;
            continue;
        }
        double love = double(value2) / value1 * 100;
        cout << fixed << setprecision(2) << love << " %" << endl;
    }
}
