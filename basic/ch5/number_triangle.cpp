#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 510, INF = -1e9;
int dp[N][N], n;

int main() {
    scanf("%d", &n);
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= i + 1; j++)
            dp[i][j] = INF;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            scanf("%d", &dp[i][j]);
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] += max(dp[i - 1][j], dp[i - 1][j - 1]);

    int res = INF;
    for (int i = 1; i <= n; i++)
        res = max(res, dp[n][i]);
    printf("%d\n", res);
    return 0;
}