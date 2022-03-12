#include <iostream>
using namespace std;

const int N = 310;
int h[N][N], R, C, f[N][N];

int dr[] = {0, -1, 0, 1};
int dc[] = {-1, 0, 1, 0};

int dp(int r, int c) {
    if (f[r][c] != 0) return f[r][c];
    f[r][c] = 1;
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (0 <= nr && nr < R && 0 <= nc && nc < C && h[nr][nc] < h[r][c])
            f[r][c] = max(f[r][c], dp(nr, nc) + 1);
    }
    return f[r][c];
}

int main() {
    cin >> R >> C;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> h[i][j];
    int res = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            res = max(res, dp(i, j));
        }
    }
    cout << res << endl;
    return 0;
}