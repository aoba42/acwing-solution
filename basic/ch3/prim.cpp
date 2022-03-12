#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 510, INF = 0x3f3f3f3f;
int g[N][N], n, m, d[N];
bool st[N];

int prim() {
    memset(d, 0x3f, sizeof d);
    int res = 0;
    for (int i = 0; i < n; i++) {
        int t = 0;
        for (int j = 1; j <= n; j++) {
            if (!st[j] && (t == 0 || d[j] < d[t]))
                t = j;
        }
        if (i && d[t] == INF) return INF;
        if (i) res += d[t];
        st[t] = true;
        for (int j = 1; j <= n; j++)
            if (!st[j]) d[j] = min(d[j], g[t][j]);
    }
    return res;
}

int main() {
    memset(g, 0x3f, sizeof g);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if (a == b) continue;
        g[a][b] = min(g[a][b], c);
        g[b][a] = min(g[b][a], c);
    }
    int ans = prim();
    if (ans == INF) printf("impossible\n");
    else printf("%d\n", ans);
    return 0;
}