#include <cstdio>
using namespace std;

const int N = 1e5+10;
int a[N];

int main() {
    int n, m; scanf("%d%d", &n, &m);
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i] += a[i - 1];
    }
    for (int i = 0; i < m; i++) {
        int l, r; scanf("%d%d", &l, &r);
        printf("%d\n", a[r] - a[l - 1]);
    }
    return 0;
}
