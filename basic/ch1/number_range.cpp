#include <cstdio>
using namespace std;

const int N = 1e5 + 10;
int n, q, a[N];

int bs_first(int *a, int s, int e, int t) {
    while (s < e) {
        int mid = s + e >> 1;
        if (a[mid] >= t) e = mid;
        else s = mid + 1;
    }
    return s;
}

int bs_last(int *a, int s, int e, int t) {
    while (s < e) {
        int mid = s + e + 1 >> 1;
        if (a[mid] <= t) s = mid;
        else e = mid - 1;
    }
    return s;
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < q; i++) {
        int t, l, r; scanf("%d", &t);
        l = bs_first(a, 0, n - 1, t);
        if (a[l] != t) l = -1, r = -1;
        else r = bs_last(a, 0, n - 1, t);
        printf("%d %d\n", l, r);
    }
    return 0;
}