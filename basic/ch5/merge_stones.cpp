#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 310;
int n, a[N], s[N], dp[N][N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];

    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            int res = 1e9;
            for (int k = i; k <= j - 1; k++) {
                res = min(res, dp[i][k] + dp[k + 1][j] + s[j] - s[i - 1]);
            }
            dp[i][j] = res;
        }
    }
    printf("%d\n", dp[1][n]);
    return 0;
}
