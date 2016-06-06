#include <stdio.h>
#include <vector>
#include <queue>

struct RevCmpr 
{
    bool operator()(const int& lhs, const int& rhs) 
    {
        return lhs > rhs;
    }
};

int main()
{
    std::priority_queue<int> left;
    std::priority_queue<int, std::vector<int>, RevCmpr> right;

    int d;
    while (scanf("%d", &d) == 1) {
        if (!left.empty() && left.top() < d)
            right.push(d);
        else
            left.push(d);
        if (left.size() > right.size() + 1) {
            int tmp = left.top();
            left.pop();
            right.push(tmp);
        }
        if (left.size() < right.size()) {
            int tmp = right.top();
            right.pop();
            left.push(tmp);
        }
        if (left.size() > right.size()) {
            printf("%d\n", left.top());
        } else {
            printf("%d\n", (left.top() + right.top()) / 2);
        }
    }
}
