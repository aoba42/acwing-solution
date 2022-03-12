#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1e5+10;
int h[N], e[2 * N], ne[2 * N], idx, color[N], n, m;

bool dfs(int u, int c) {
    if (color[u] != 0) {
        if (color[u] != c) return false;
        return true;
    }
    color[u] = c;
    for (int i = h[u]; i; i = ne[i]) {
        int v = e[i];
        if (!dfs(v, 3 - c)) return false;
    }
    return true;
}

void add(int a, int b) {
    e[++idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
}

int main() {
    memset(h, 0, sizeof h);
    memset(color, 0, sizeof color);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y);
        add(y, x);
    }
    bool flag = true;
    for (int i = 1; i <= n; i++)
        if (!color[i])
            if (!dfs(i, 1)) {
                flag = false;
                break;
            }

    if (flag) printf("Yes\n");
    else printf("No\n");
    return 0;
}