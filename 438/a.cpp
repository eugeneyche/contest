#define USE_MATH_DEFINES_
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    double x1, y1, x2, y2, x3, y3;
    while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3) {
        double mx1, my1, vx1, vy1, mx2, my2, vx2_p, vy2_p;

        mx1 = (x1 + x2) / 2.;
        my1 = (y1 + y2) / 2.;
        vx1 = y1 - y2;
        vy1 = x2 - x1;
        mx2 = (x2 + x3) / 2.;
        my2 = (y2 + y3) / 2.;
        vx2_p = x3 - x2;
        vy2_p = y3 - y2;

        double scale = ((mx2 - mx1) * vx2_p + (my2 - my1) * vy2_p) / 
            (vx1 * vx2_p + vy1 * vy2_p);

        double dx = x1 - mx1 + scale * vx1;
        double dy = y1 - my1 + scale * vy1;
        double radius = sqrt(dx * dx + dy * dy);
        cout << setprecision(2) << fixed << 2 * radius * M_PI << endl;
    }
}
