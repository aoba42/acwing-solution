#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1e5+10;
int tree[N], e[N * 2], ne[N * 2], n, idx = 1, ans = N;
bool st[N];

void add_edge(int x, int y) {
    e[++idx] = y;
    ne[idx] = tree[x];
    tree[x] = idx;
}

int dfs(int r) {
    st[r] = true;
    int sum = 1;
    int ss = 0;
    for (int i = tree[r]; i; i = ne[i]) {
        int j = e[i];
        if (!st[j]) {
            int s = dfs(j);
            ss = max(ss, s);
            sum += s;
        }
    }
    ans = min(ans, max(ss, n - sum));
    return sum;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d%d", &a, &b);
        add_edge(a, b);
        add_edge(b, a);
    }

    dfs(1);
    printf("%d\n", ans);
}
