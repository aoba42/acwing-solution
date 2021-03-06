#include <cstdio>
using namespace std;

const int N = 1e5+10;
int p[N];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) p[i] = i;
    while (m--) {
        char op[2]; int a, b;
        scanf("%s%d%d", op, &a, &b);
        if (op[0] == 'M') {
            p[find(a)] = find(b);
        } else {
            if (find(a) == find(b)) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
