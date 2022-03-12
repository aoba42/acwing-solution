#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1e5+10, INF = 0x3f3f3f3f;
int h[N], e[N], we[N], ne[N], idx;
int q[N], tt = -1, hh;
int n, m, d[N];
bool st[N];

void spfa() {
    memset(d, 0x3f, sizeof d);
    d[1] = 0; st[1] = true; q[++tt] = 1;
    while (hh <= tt) {
        int u = q[hh++]; st[u] = false;
        for (int i = h[u]; i; i = ne[i]) {
            int v = e[i];
            if (d[v] > d[u] + we[i]) {
                d[v] = d[u] + we[i];
                if (!st[v]) {
                    st[v] = true;
                    q[++tt] = v;
                }
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        e[++idx] = b;
        we[idx] = c;
        ne[idx] = h[a];
        h[a] = idx;
    }
    spfa();
    if (d[n] > INF / 2) printf("impossible\n");
    else printf("%d\n", d[n]);
    return 0;
}