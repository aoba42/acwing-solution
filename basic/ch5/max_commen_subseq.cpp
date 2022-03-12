#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1010;
char a[N], b[N];
// dp[i][j]表示a[0...i]和b[0...j]之间的最长公共子序列
int n, m, dp[N][N];

int main() {
    scanf("%d%d", &n, &m);
    scanf("%s%s", &a[1], &b[1]);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            if (a[i] == b[j])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    }
    printf("%d\n", dp[n][m]);
    return 0;
}
