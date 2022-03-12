#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1e5+10;
int a[N], n, m, len;

void down(int x) {
    int t = x, l = 2 * x, r = 2 * x + 1;
    if (l <= n && a[l] < a[t]) t = l;
    if (r <= n && a[r] < a[t]) t = r;
    if (t != x) swap(a[x], a[t]), down(t);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = n / 2; i > 0; i--) down(i);
    for (int i = 0; i < m; i++) {
        printf("%d ", a[1]);
        a[1] = a[len--];
        down(1);
    }
    return 0;
}
