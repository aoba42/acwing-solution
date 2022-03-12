#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 110;
int n, v, ss[N], vs[N][N], ws[N][N], dp[N];

int main() {
    scanf("%d%d", &n, &v);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &ss[i]);
        for (int j = 1; j <= ss[i]; j++) {
            scanf("%d%d", &vs[i][j], &ws[i][j]);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = v; j >= 0; j--) {
            int tmpMax = 0; // 第i组中的最大值
            for (int k = 1; k <= ss[i]; k++) {
                if (j >= vs[i][k])
                    dp[j] = max(dp[j], dp[j - vs[i][k]] + ws[i][k]);
                tmpMax = max(tmpMax, dp[j]);
            }
            dp[j] = tmpMax;
        }
    }
    printf("%d\n", dp[v]);
    return 0;
}