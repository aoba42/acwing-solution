#include <cstdio>
using namespace std;

const int N = 1e5+10, M = 2e4 + 10;
int son[N][26], cnt[N], idx = 1;
char op[2], str[M];

void insert(char *str) {
    int p = 0;
    while (*str) {
        int u = *str++ - 'a';
        if (!son[p][u]) son[p][u] = idx++;
        p = son[p][u];
    }
    cnt[p] += 1;
}

int query(char *str) {
    int p = 0;
    while (*str) {
        int u = *str++ - 'a';
        if (!son[p][u]) return 0;
        else p = son[p][u];
    }
    return cnt[p];
}

int main() {
    int n; scanf("%d", &n);
    while (n--) {
        scanf("%s%s", op, str);
        if (op[0] == 'I') insert(str);
        else printf("%d\n", query(str));
    }
    return 0;
}
