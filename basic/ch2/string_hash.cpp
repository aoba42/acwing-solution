#include <cstdio>
using namespace std;

typedef unsigned long long ULL;

const int N = 1e5+10, P = 131;
ULL h[N], p[N];
char str[N];

ULL sub_hash(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main() {
    int  n, m; scanf("%d%d%s", &n, &m, &str[1]);
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        h[i] = h[i - 1] * P + str[i];
        p[i] = p[i - 1] * P;
    }
    while (m--) {
        int l1, r1, l2, r2;
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        if (sub_hash(l1, r1) == sub_hash(l2, r2)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
