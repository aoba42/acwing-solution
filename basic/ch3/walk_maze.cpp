#include <cstdio>
#include <map>
using namespace std;

const int N = 110;
typedef pair<int, int> PII;
PII q[N * N];
int maze[N][N], hh = 0, tt = -1, d[N][N];
bool st[N][N];

int main() {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &maze[i][j]);
    q[++tt] = {1, 1}, d[1][1] = 0;
    int dr[] = {0, -1, 0, 1};
    int dc[] = {-1, 0, 1, 0};
    while (tt >= hh) {
        PII p = q[hh++];
        for (int i = 0; i < 4; i++) {
            int nr = p.first + dr[i];
            int nc = p.second + dc[i];
            if (0 < nr && nr <= n &&
                0 < nc && nc <= m &&
                !st[nr][nc] && maze[nr][nc] == 0) {
                st[nr][nc] = true;
                d[nr][nc] = d[p.first][p.second] + 1;
                q[++tt] = {nr, nc};
            }
            if (p.first == n && p.second == m) {
                printf("%d\n", d[n][m]);
                break;
            }
        }
    }
    return 0;
}
