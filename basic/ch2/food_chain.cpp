#include <cstdio>
using namespace std;

const int N = 5e4+10;
int p[N], d[N];

int find(int x) {
    if (x == p[x]) return p[x];
    int u = find(p[x]);
    d[x] += d[p[x]];
    p[x] = u;
    return p[x];
}

int main() {
    int n, k; scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) p[i] = i;
    int fake = 0;
    while (k--) {
        int t, x, y; scanf("%d%d%d", &t, &x, &y);
        if (x > n || y > n) fake += 1;
        else {
            int px = find(x), py = find(y);
            int dx = d[x], dy = d[y];
            if (t == 1) {
                if (px == py) {
                    if ((dx - dy) % 3) fake++;
                } else {
                    p[px] = py;
                    d[px] = dy - dx;
                }
            } else {
                if (px == py) {
                    if ((dx + 1 - dy) % 3) fake++;
                } else {
                    p[px] = py;
                    d[px] = dy - dx - 1;
                }
            }
        }
    }
    printf("%d\n", fake);
    return 0;
}