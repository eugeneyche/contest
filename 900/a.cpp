#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

#define MAX_IN (500)

struct State {
    uint64_t vert;
    uint64_t horiz;
};

int main()
{
    vector<State> dp (MAX_IN + 1);
    dp[0].vert  = 0;
    dp[0].horiz = 0;
    dp[1].vert  = 1;
    dp[1].horiz = 0;
    for (int i = 2; i < dp.size(); i++) {
        dp[i].vert = dp[i - 1].vert + dp[i - 1].horiz;
        dp[i].horiz = dp[i - 1].vert;
    }

    int d;
    while (cin >> d) {
        if (d == 0) break;
        cout << dp[d].vert + dp[d].horiz << endl;
    }
}
