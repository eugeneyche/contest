#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

struct Point {
    double x;
    double y;
};

struct Path {
    int from;
    int to;
    double dist;
};

struct PathCmp {
    bool operator() (const Path& lhs, const Path& rhs) {
        return lhs.dist > rhs.dist;
    }
};

int main()
{
    int num_tcs;
    cin >> num_tcs;

    bool  touched [100];
    double dist_mat [100][100];

    for (int tc = 0; tc < num_tcs; tc++) {
        int num_nodes;
        cin >> num_nodes;
        fill(touched, touched + num_nodes, false);
        vector<Point> points;
        Point p;
        for (int i = 0; i < num_nodes; i++) {
            cin >> p.x >> p.y;
            for (int j = 0; j < points.size(); j++) {
                double dx = p.x - points[j].x;
                double dy = p.y - points[j].y;
                double d = sqrt(dx * dx + dy * dy);
                dist_mat[i][j] = d;
                dist_mat[j][i] = d;
            }
            points.push_back(p);
        }
        priority_queue<Path, vector<Path>, PathCmp> pq;
        Path pt;
        touched[0] = true;
        pt.from = 0;
        for (int i = 1; i < num_nodes; i++) {
            pt.to = i;
            pt.dist = dist_mat[pt.from][pt.to];
            pq.push(pt);
        }
        double total_dist = 0.f;
        while (!pq.empty()) {
            Path cur_pt = pq.top();
            pq.pop();
            if (touched[cur_pt.to])
                continue;
            total_dist += cur_pt.dist;
            touched[cur_pt.to] = true;
            Path new_pt;
            new_pt.from = cur_pt.to;
            for (int i = 0; i < num_nodes; i++) {
                if (touched[i])
                    continue;
                new_pt.to = i;
                new_pt.dist = dist_mat[new_pt.from][new_pt.to];
                pq.push(new_pt);
            }
        }
        if (tc > 0) cout << endl;
        cout << setprecision(2) << fixed << total_dist << endl;
    }
}
