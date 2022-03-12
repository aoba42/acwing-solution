#include <cstdio>
using namespace std;
const int N = 1e5 + 10;
int e[N], ne[N], idx = 0, head = -1;

void add_head(int x) {
    e[idx] = x;
    ne[idx] = head;
    head = idx++;
}

void add_after_k(int k, int x) {
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx++;
}

void remove_after_k(int k) {
    ne[k] = ne[ne[k]];
}

int main() {
    int n; scanf("%d", &n);
    char op[2];
    int k, x;
    for (int i = 0; i < n; i++) {
        scanf("%s", op);
        if (op[0] == 'H') {
            scanf("%d", &x);
            add_head(x);
        } else if (op[0] == 'D') {
            scanf("%d", &k);
            if (k == 0) head = ne[head];
            else remove_after_k(k - 1);
        } else if (op[0] == 'I') {
            scanf("%d%d", &k, &x);
            add_after_k(k - 1, x);
        }
    }
    while (head != -1) {
        printf("%d ", e[head]);
        head = ne[head];
    }
    return 0;
}
