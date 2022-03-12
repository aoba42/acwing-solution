#include <cstdio>
using namespace std;

const int N = 1e5+10;
int n, a[N], tmp[N];
unsigned long long count = 0;

void rp(int *a, int s, int e) {
    if (s >= e) return;
    int m = s + e >> 1;
    rp(a, s, m);
    rp(a, m + 1, e);
    int i = s, j = m + 1, k = 0;
    while (i <= m && j <= e) {
        if (a[i] <= a[j]) tmp[k++] = a[i++];
        else tmp[k++] = a[j++], count += m - i + 1;
    }
    while (i <= m) tmp[k++] = a[i++];
    while (j <= e) tmp[k++] = a[j++];
    i = s, k = 0;
    while (i <= e) a[i++] = tmp[k++];
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    rp(a, 0, n - 1);
    printf("%lld\n", count);
    return 0;
}
