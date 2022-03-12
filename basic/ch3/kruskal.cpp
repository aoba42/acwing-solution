#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1e5+10, M = 2e5+10;
struct Edge {
    int a, b, w;
    bool operator<(Edge &e) const {
        return this->w < e.w;
    }
} edges[M];

int ans, n, m, p[N];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

bool kruskal() {
    int cnt = 0;
    sort(edges, edges + m);
    for (int i = 1; i <= n; i++) p[i] = i;
    for (int i = 0; i < m; i++) {
        int a = edges[i].a;
        int b = edges[i].b;
        int w = edges[i].w;
        if (find(a) != find(b)) {
            ans += w;
            p[find(b)] = a;
            cnt++;
        }
    }
    return cnt == n - 1;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        edges[i] = { .a = x, .b = y, .w = z};
    }
    if (kruskal()) printf("%d\n", ans);
    else printf("impossible\n");
    return 0;
}