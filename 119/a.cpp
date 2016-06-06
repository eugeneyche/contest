#include <iostream>
#include <sstream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    int num_ppl;

    int tc = 0;
    while (cin >> num_ppl) {
        vector<int> value (num_ppl);
        vector<string> names;
        map<string, int> name_to_index;
        cin.ignore(1000, '\n');
        string line;
        getline(cin, line);
        stringstream tokenizer (line);
        string name;
        while (tokenizer >> name) {
            name_to_index[name] = names.size();
            names.push_back(name);
        }
        for (int i = 0; i < num_ppl; i++) {
            int amount, num_getters;
            cin >> name >> amount >> num_getters;
            if (num_getters == 0)
                continue;
            int giver_id = name_to_index[name];
            int spill = amount % num_getters;
            int per_getter = amount / num_getters;
            value[giver_id] -= amount - spill;
            while (num_getters--) {
                cin >> name;
                int getter_id = name_to_index[name];
                value[getter_id] += per_getter;
            }
        }
        if (tc > 0)
            cout << endl;
        for (int i = 0; i < num_ppl; i++) {
            cout << names[i] << " " << value[i] << endl;
        }
        tc++;
    }
}
