#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1e5+10;
int h[N], e[N], ne[N], idx = 1, d[N], n, m, q[N], hh = 0, tt = -1;
bool st[N];

void edge_add(int a, int b) {
    e[++idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
}

int main() {
    memset(d, -1, sizeof d);
    memset(ne, 0, sizeof ne);
    memset(h, 0, sizeof h);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d%d", &a, &b);
        edge_add(a, b);
    }

    q[++tt] = 1; st[1] = true, d[1] = 0;
    while (hh <= tt) {
        int u = q[hh++];
        for (int i = h[u]; i; i = ne[i]) {
            int j = e[i];
            if (!st[j]) {
                st[j] = true;
                d[j] = d[u] + 1;
                q[++tt] = j;
            }
        }
    }
    printf("%d\n", d[n]);
    return 0;
}