#include <iostream>
#include <vector>
using namespace std;

struct Rect
{
    float nw_x;
    float nw_y;
    float se_x;
    float se_y;
};

int main()
{
    vector<Rect> rects;

    char c;
    Rect r;
    while (cin >> c) {
        if (c == '*') break;
        if (c != 'r') continue;
        cin >> r.nw_x >> r.nw_y >> r.se_x >> r.se_y;
        rects.push_back(r);
    }

    float x, y;
    int point_id = 0;
    while (cin >> x >> y) {
        if (x == 9999.9f && y == 9999.9f) break;
        point_id++;
        bool in_any = false;
        for (int i = 0; i < rects.size(); i++) {
            const Rect& r = rects[i];
            if (r.nw_x < x && x < r.se_x &&
                    r.se_y < y && y < r.nw_y) {
                in_any = true;
                cout << "Point " << point_id 
                    << " is contained in figure " 
                    << i + 1 << endl;
            }
        }
        if (!in_any) {
            cout << "Point " << point_id 
                << " is not contained in any figure" 
                << endl;
        }
    }
}
