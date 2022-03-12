#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 110;
int n, v, vs[N], ws[N], ss[N], dp[N][N];

int main() {
    scanf("%d%d", &n, &v);
    for (int i = 1; i <= n; i++)
        scanf("%d%d%d", &vs[i], &ws[i], &ss[i]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= v; j++)
            for (int k = 0; k <= ss[i] && k * vs[i] <= j; k++)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - vs[i] * k] + ws[i] * k);

    printf("%d\n", dp[n][v]);
    return 0;
}
