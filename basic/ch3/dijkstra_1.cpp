#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 510, INF = 0x3f3f3f3f;
int g[N][N], dist[N], n, m;
bool st[N];

void dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 0; i < n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        if (t == -1) break;
        st[t] = true;
        for (int j = 1; j <= n; j++)
            if (g[t][j] != INF)
                dist[j] = min(dist[j], dist[t] + g[t][j]);
    }
}

int main() {
    memset(g, 0x3f, sizeof g);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b, w; scanf("%d%d%d", &a, &b, &w);
        if (a == b) continue;
        g[a][b] = min(g[a][b], w);
    }

    dijkstra();
    if (dist[n] > INF / 2) printf("-1");
    else printf("%d\n", dist[n]);
    return 0;
}
