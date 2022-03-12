#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5+10;
int h[N], hp[N], ph[N], sz, cnt;

void heap_swap(int a, int b) {
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void down(int k) {
    int t = k, l = k * 2, r = k * 2 + 1;
    if (l <= sz && h[l] < h[t]) t = l;
    if (r <= sz && h[r] < h[t]) t = r;
    if (k != t) {
        heap_swap(k, t);
        down(t);
    }
}

void up(int k) {
    while (k / 2 && h[k] < h[k / 2]) {
        heap_swap(k, k / 2);
        k /= 2;
    }
}

int main() {
    int n; scanf("%d", &n);
    while (n--) {
        char op[3]; scanf("%s", op);
        int k, x;
        if (!strcmp(op, "I")) {
            scanf("%d", &x);
            sz++; cnt++;
            hp[sz] = cnt, ph[cnt] = sz;
            h[sz] = x;
            up(sz);
        } else if (!strcmp(op, "PM")) {
            printf("%d\n", h[1]);
        } else if (!strcmp(op, "DM")) {
            heap_swap(1, sz--);
            down(1);
        } else if (!strcmp(op, "D")) {
            scanf("%d", &k); k = ph[k];
            heap_swap(k, sz--);
            up(k), down(k);
        } else if (!strcmp(op, "C")) {
            scanf("%d%d", &k, &x);
            k = ph[k];
            h[k] = x;
            up(k), down(k);
        }
    }
    return 0;
}
