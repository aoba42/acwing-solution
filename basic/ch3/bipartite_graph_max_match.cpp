#include <cstdio>
#include <cstring>
using namespace std;

const int N = 510, M = 1e5+10;

int h[N], e[M], ne[M], idx, r[N], n1, n2, m;
bool st[N];

void add(int a, int b) {
    e[++idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
}

bool find(int i) {
    for (int j = h[i]; j; j = ne[j]) {
        int v = e[j];
        if (!st[v]) {
            st[v] = true;
            if (r[v] == 0 || find(r[v])) {
                r[v] = i;
                return true;
            }
        }
    }
    return false;
}

int main() {
    memset(h, 0, sizeof h);
    memset(r, 0, sizeof r);
    scanf("%d%d%d", &n1, &n2, &m);
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }

    int ans = 0;
    for (int i = 1; i <= n1; i++) {
        memset(st, false, sizeof st);
        if (find(i))  ans++;
    }
    printf("%d\n", ans);
    return 0;
}
