#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    vector<int> order;
    unordered_map<int, int> reps;

    int d;
    while (cin >> d) {
        unordered_map<int, int>::const_iterator it = reps.find(d);
        if (it != reps.end()) {
            reps[d] += 1; 
        } else {
            order.push_back(d);
            reps[d] = 1;
        }
    }

    for (int i = 0; i < order.size(); i++) {
        cout << order[i] << " " << reps[order[i]] << endl;
    }
}
