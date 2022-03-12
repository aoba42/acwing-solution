#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 510, M = 10010, INF = 0x3f3f3f3f;
struct {
    int x, y, z;
} e[M];
int n, m, k, dist[N], backup[N];

void bellman_ford() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for (int  i = 0; i < k; i++) {
        memcpy(backup, dist, sizeof dist);
        for (int j = 0; j < m; j++) {
            int x = e[j].x, y = e[j].y, z = e[j].z;
            dist[y] = min(dist[y], backup[x] + z);
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++)
        scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].z);
    bellman_ford();
    if (dist[n] > INF / 2) printf("impossible\n");
    else printf("%d\n", dist[n]);
    return 0;
}
