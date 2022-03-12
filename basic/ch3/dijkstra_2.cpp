#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int, int> PII;
const int N = 1.5 * 1e5 + 10, INF = 0x3f3f3f3f;
int h[N], e[N], ew[N], ne[N], idx = 1, d[N];
bool st[N];

void dijkstra() {
    memset(d, 0x3f, sizeof d); d[1] = 0;
    priority_queue<PII, vector<PII>, greater<>> q;
    q.push({0, 1});
    while (!q.empty()) {
        PII t = q.top(); q.pop();
        int dist = t.first, id = t.second;
        if (st[id]) continue;
        for (int i = h[id]; i; i = ne[i]) {
            int j = e[i];
            if (d[j] > ew[i] + dist) {
                d[j] = ew[i] + dist;
                q.push({d[j], j});
            }
        }
        st[id] = true;
    }
}

int main() {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b, w; scanf("%d%d%d", &a, &b, &w);
        e[++idx] = b;
        ew[idx] = w;
        ne[idx] = h[a];
        h[a] = idx;
    }
    dijkstra();
    if (d[n] > INF / 2) printf("-1\n");
    else printf("%d\n", d[n]);
    return 0;
}
