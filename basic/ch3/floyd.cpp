#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 210, INF = 1e9;
int g[N][N], n, m, k;

void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == j) g[i][j] = 0;
            else g[i][j] = INF;
        }
    }
    for (int i = 0; i < m; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        if (x == y) continue;
        g[x][y] = min(g[x][y], z);
    }
    floyd();
    while (k--) {
        int a, b; scanf("%d%d", &a, &b);
        if (g[a][b] > INF / 2) printf("impossible\n");
        else printf("%d\n", g[a][b]);
    }
    return 0;
}