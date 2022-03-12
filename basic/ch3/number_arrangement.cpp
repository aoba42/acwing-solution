#include <cstdio>
using namespace std;

int path[10], n;
bool st[10];

void dfs(int x) {
    if (x == n) {
        for (int i = 0; i < n; i++) {
            printf("%d ", path[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (st[i] == false) {
            st[i] = true;
            path[x] = i;
            dfs(x + 1);
            st[i] = false;
        }
    }
}

int main() {
    scanf("%d", &n);
    dfs(0);
    return 0;
}
