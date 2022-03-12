#include <cstdio>
using namespace std;

const int N = 1e5+10;
int e[N], l[N], r[N], idx = 0;

void init() {
    e[0] = 0, e[1] = 0;
    r[0] = 1, l[1] = 0;
    idx = 2;
}

void add(int k, int x) {
    e[idx] = x, l[idx] = k, r[idx] = r[k];
    l[r[k]] = idx;
    r[k] = idx++;
}

int main() {
    int n; scanf("%d", &n);
    init();
    char op[3];
    int k, x;
    for (int i = 0; i < n; i++) {
        scanf("%s", op);
        switch (op[0]) {
            case 'L':
                scanf("%d", &x);
                add(0, x);
                break;
            case 'R':
                scanf("%d", &x);
                add(l[1], x);
                break;
            case 'D':
                scanf("%d", &k); k += 1;
                r[l[k]] = r[k];
                l[r[k]] = l[k];
                break;
            default:
                if (op[1] == 'L') {
                    scanf("%d%d", &k, &x); k += 1;
                    add(l[k], x);
                } else {
                    scanf("%d%d", &k, &x); k += 1;
                    add(k, x);
                }
        }
    }
    for (int i = r[0]; i != 1; i = r[i])
        printf("%d ", e[i]);
    return 0;
}