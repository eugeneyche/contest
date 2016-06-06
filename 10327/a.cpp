#include <stdio.h>
#include <stdint.h>

int n;
int arr [1000];
int tmp_arr [1000];

int count_inv(int begin, int end) 
{
    if (end - begin == 1) {
        return 0;
    }
    if (end - begin == 2) {
        if (arr[begin] > arr[end - 1]) {
            int tmp = arr[begin];
            arr[begin] = arr[end - 1];
            arr[end - 1] = tmp;
            return 1;
        }
        return 0;
    }
    int inv = 0;
    int mid = (end - begin) / 2 + begin;
    inv += count_inv(begin, mid);
    inv += count_inv(mid, end);
    int it = begin;
    int lhs_it = 0;
    int rhs_it = mid;
    for (int i = begin; i < mid; i++) {
        tmp_arr[i - begin] = arr[i];
    }
    while (lhs_it < mid - begin && rhs_it < end) {
        if (tmp_arr[lhs_it] <= arr[rhs_it]) {
            arr[it++] = tmp_arr[lhs_it++];
        } else {
            arr[it++] = arr[rhs_it++];
            inv += mid - begin - lhs_it;
        }
    }
    while (lhs_it < mid - begin) {
        arr[it++] = tmp_arr[lhs_it++];
    }
    while (rhs_it < end) {
        arr[it++] = arr[rhs_it++];
    }
    return inv;
}

int main() 
{
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            scanf("%d", arr + i);
        }
        int inv = count_inv(0, n);
        printf("Minimum exchange operations : %d\n", inv);
    }
}
