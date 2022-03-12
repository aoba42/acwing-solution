#include <cstdio>
using namespace std;

const int N = 1e6+10;
int a[N], q[N], hh = 0, tt = -1; //[hh, tt]

int main() {
    int n, k; scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    hh = 0, tt = -1;
    for (int i = 0; i < n; i++) {
        if (tt >= hh && q[hh] <= i - k) hh++;
        while (tt >= hh && a[q[tt]] >= a[i]) tt--;
        q[++tt] = i;
        if (i >= k - 1) printf("%d ", a[q[hh]]);
    }
    printf("\n");

    hh = 0, tt = -1;
    for (int i = 0; i < n; i++) {
        if (tt >= hh && q[hh] <= i - k) hh++;
        while (tt >= hh && a[q[tt]] <= a[i]) tt--;
        q[++tt] = i;
        if (i >= k - 1) printf("%d ", a[q[hh]]);
    }
    printf("\n");

    return 0;
}
