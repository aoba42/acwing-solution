#include <cstdio>
using namespace std;

const int N = 1e5 + 10;
int a[N], b[N];

void insert(int l, int r, int c) {
    b[l] += c;
    b[r + 1] -= c;
}

int main() {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 0; i <= n; i++) b[i] = 0;
    for (int i = 1; i <= n; i++) insert(i, i, a[i]);
    for (int i = 0; i < m; i++) {
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
        insert(l, r, c);
    }
    for (int i = 1, s = 0; i <= n; i++) {
        s += b[i];
        printf("%d ", s);
    }
    return 0;
}