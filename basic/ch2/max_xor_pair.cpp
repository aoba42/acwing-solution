#include <cstdio>
using namespace std;

const int N = 1e5+10, M = 31 * N;
int son[M][2], idx = 1;

void insert(int x) {
    for (int i = 30, p = 0; i >= 0; i--) {
        int u = (x >> i) & 1;
        if (!son[p][u]) son[p][u] = idx++;
        p = son[p][u];
    }
}

int query(int x) {
    int res = 0;
    for (int i = 30, p = 0; i >= 0; i--) {
        int u = (x >> i) & 1;
        if (son[p][!u]) {
            p = son[p][!u];
            res = (res << 1) + !u;
        } else {
            p = son[p][u];
            res = (res << 1) + u;
        }
    }
    return res;
}

int max(int x, int y) { return x > y ? x : y; }

int main() {
    int n; scanf("%d", &n);
    int res = 0;
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        insert(x);
        int t = query(x);
        res = max(res, x^t);
    }
    printf("%d\n", res);
    return 0;
}
