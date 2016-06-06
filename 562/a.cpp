#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int num_tcs;
    cin >> num_tcs;
    while (num_tcs--) {
        int num_coins;
        cin >> num_coins;
        int sum_value = 0;
        vector<int> coins;
        for (int i = 0; i < num_coins; i++) {
            int coin;
            cin >> coin;
            coins.push_back(coin);
            sum_value += coin;
        }
        int target_value = sum_value / 2;
        vector<vector<bool> > dp (num_coins);
        for (int i = 0; i < dp.size(); i++) {
            dp[i].resize(target_value + 1);
        }
        int best_value = 0;
        vector<int> frames [2];
        frames[0].resize(target_value + 1);
        frames[1].resize(target_value + 1);
        vector<int>* cur_frame, * prev_frame;
        cur_frame = &frames[0];
        prev_frame = &frames[1];
        fill(cur_frame->begin(), cur_frame->end(), false);
        (*cur_frame)[0] = true;
        for (int i = 0; i < coins.size(); i++) {
            vector<int>* tmp = prev_frame;
            prev_frame = cur_frame;
            cur_frame = tmp;
            for (int j = 0; j < cur_frame->size(); j++) {
                (*cur_frame)[j] = (*prev_frame)[j];
                if (j >= coins[i] && (*prev_frame)[j - coins[i]]) {
                    (*cur_frame)[j] = true;
                }
                if ((*cur_frame)[j] && j > best_value) {
                    best_value = j;
                }
            }
        }
        int offset = sum_value - 2 * best_value;
        cout << offset << endl;
    }
}
