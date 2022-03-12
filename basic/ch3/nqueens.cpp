#include <cstdio>
using namespace std;

const int N = 12;
bool row[N], col[N], dg[2 * N], ndg[2 * N];
char board[N][N];
int n, cnt;

bool check(int x) {
    int r = x / n, c = x % n;
    if (r >= n || c>= n) return false;
    //printf("%d %d %d %d\n", r, c, r + c, n - r + c - 1);
    return !row[r] && !col[c] && !dg[r + c] && !ndg[n - r + c - 1];
}

bool state(int x, bool set) {
    int r = x / n, c = x % n;
    row[r] = col[c] = dg[r + c] = ndg[n - r + c - 1] = set;
}

void _dfs1(int x, bool set) {
    if (x == n * n) {
        if (cnt != n) return;
        for (int i = 0; i < n; i++)
            printf("%s %d\n", board[i]);
        printf("\n");
        return;
    }

    int r = x / n, c = x % n;
    if (set) {
        cnt++;
        board[r][c] = 'Q';
        state(x, true);

        if (check(x + 1))
            _dfs1(x + 1, true);
        _dfs1(x + 1, false);

        cnt--;
        board[r][c] = '.';
        state(x, false);
    } else {
        board[r][c] = '.';
        if (check(x + 1))
            _dfs1(x + 1, true);
        _dfs1(x + 1, false);
    }
}

void dfs1() {
    _dfs1(0, true);
    _dfs1(0, false);
}

void _dfs2(int u) {
    if (u == n) {
        for (int i = 0; i < n; i++)
            printf("%s\n", board[i]);
        printf("\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!col[i] && !dg[u + i] && !ndg[n - u + i - 1]) {
            board[u][i] = 'Q', col[i] = dg[u + i] = ndg[n - u + i - 1] = true;
            _dfs2(u + 1);
            board[u][i] = '.', col[i] = dg[u + i] = ndg[n - u + i - 1] = false;
        }
    }
}

void dfs2() {
    _dfs2(0);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = '.';
    //dfs1();
    dfs2();
    return 0;
}
