#include <cstdio>
using namespace std;

const int N = 1e5+10;
int p[N], size[N];

int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main() {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) p[i] = i, size[i] = 1;
    for (int i = 0; i < m; i++) {
        char op[3]; scanf("%s", op);
        if (op[0] == 'C') {
            int a, b; scanf("%d%d", &a, &b);
            if (find(a) == find(b)) continue;
            size[find(b)] += size[find(a)];
            p[find(a)] = find(b);
        } else if (op[1] == '1') {
            int a, b; scanf("%d%d", &a, &b);
            if (find(a) == find(b)) printf("Yes\n");
            else printf("No\n");
        } else {
            int x; scanf("%d", &x);
            printf("%d\n", size[find(x)]);
        }
    }
    return 0;
}
