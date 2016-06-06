#include <iostream>
#include <vector>
using namespace std;

void impl_print_all_games(
        const vector<int>& balls, 
        vector<int>& used_balls, 
        int i, int leftover) 
{
    if (leftover == 0) {
        for (int i = 0; i < used_balls.size(); i++) {
            if (i) cout << " ";
            cout << used_balls[i];
        }
        cout << endl;
        return;
    }
    used_balls.push_back(balls[i]);
    impl_print_all_games(balls, used_balls, i + 1, leftover - 1);
    used_balls.pop_back();
    if (balls.size() - i > leftover) {
        impl_print_all_games(balls, used_balls, i + 1, leftover);
    }
}

void print_all_games(const vector<int>& balls) 
{
    vector<int> used_balls;
    impl_print_all_games(balls, used_balls, 0, 6);
}

int main()
{
    int d;
    int tc = 0;
    while (cin >> d) {
        if (d == 0) break;
        vector<int> balls;
        for (int i = 0; i < d; i++) {
            int ball;
            cin >> ball;
            balls.push_back(ball);
        }
        if (tc) cout << endl;
        print_all_games(balls);
        tc++;
    }
}
