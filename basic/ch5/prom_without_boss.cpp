#include <iostream>
using namespace std;

const int N = 6010;
int happy[N], n, f[N][2];
int h[N], e[N], ne[N], idx;
bool st[N];

void add(int k, int l) {
    e[++idx] = l;
    ne[idx] = h[k];
    h[k] = idx;
}

void dfs(int u) {
    f[u][1] = happy[u];
    f[u][0] = 0;

    for (int i = h[u]; i; i = ne[i]) {
        int j = e[i];
        dfs(j);
        f[u][1] += f[j][0];
        f[u][0] += max(f[j][0], f[j][1]);
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> happy[i];
    for (int i = 0; i < n - 1; i++) {
        int l, k;
        cin >> l >> k;
        add(k, l);
        st[l] = true;
    }

    int root = 1;
    while (st[root])
        root++;

    dfs(root);
    cout << max(f[root][0], f[root][1]) << endl;

    return 0;
}
