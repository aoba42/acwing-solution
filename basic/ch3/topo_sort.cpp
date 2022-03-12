#include <cstdio>
using namespace std;

const int N = 1e5+10;
int h[N], e[N], ne[N], idx = 1, q[N], hh = 0, tt = -1, in[N];

void edge_add(int a, int b) {
    e[++idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
}

int main() {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d%d", &a, &b);
        edge_add(a, b);
        in[b]++;
    }
    for (int i = 1; i <= n; i++)
        if (in[i] == 0) q[++tt] = i, in[i] = -1;
    while (hh <= tt) {
        int u = q[hh++];
        for (int i = h[u]; i; i = ne[i]) {
            int j = e[i];
            in[j]--;
            if (in[j] == 0) {
                q[++tt] = j;
                in[j] = -1;
            }
        }
    }
    if (tt == n - 1) {
        for (int i = 0; i < n; i++)
            printf("%d ", q[i]);
        printf("\n");
    } else {
        printf("-1\n");
    }
    return 0;
}