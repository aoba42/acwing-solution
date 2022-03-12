#include <cstdio>
using namespace std;

const int N = 1010, M = 1e9+7;
// dp[i][j]表示从前i个数中选，和为j的方案数
int n, dp[N][N], dp[N];

int main1() {
    scanf("%d", &n);

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; i * k <= j; k++) {
                dp[i][j] += dp[i - 1][j - i * k];
                dp[i][j] %= M;
            }
        }
    }
    printf("%d\n", dp[n][n]);
    return 0;
}

int main() {
    scanf("%d", &n);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            dp[j] = (dp[j] + dp[j - i]) % M;
        }
    }
    printf("%d\n", dp[n]);
}
