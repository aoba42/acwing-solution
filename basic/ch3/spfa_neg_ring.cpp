#include <cstdio>
#include <cstring>
using namespace std;

const int N = 2010, M = 10010;
int h[N], e[M], we[M], ne[M], idx;
int q[M], tt = -1, hh;
int n, m, d[N], cnt[N];
bool st[N];

bool spfa() {
    for (int i = 1; i <= n; i++) {
        q[++tt] = i;
        st[i] = true;
    }
    while (hh <= tt) {
        int u = q[hh++]; st[u] = false;
        for (int i = h[u]; i; i = ne[i]) {
            int v = e[i];
            if (d[v] <= d[u] + we[i])
                continue;
            d[v] = d[u] + we[i];
            cnt[v] = cnt[u] + 1;
            if (cnt[v] >= n)
                return true;
            if (st[v])
                continue;
            st[v] = true;
            q[++tt] = v;
        }
    }
    return false;
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
    bool flag = spfa();
    if (flag) printf("Yes\n");
    else printf("No\n");
    return 0;
}