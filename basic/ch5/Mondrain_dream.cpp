#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 12, M = (1 << N) + 10;
// dp[i][j]表示从初始状态转移到第i列状态为j的方案个数
// st[i] == true表示状态i没有连续的奇数个0
long long dp[N][M];
bool st[M];
vector<int> states[M];

int main1() {
    int n, m;
    while (scanf("%d%d", &n, &m), n || m) {
        const int total_state = (1 << n);

        for (int i = 0; i < total_state; i++)
            st[i] = true;

        // 预处理，检查所有状态，把存在连续个奇数0的状态标为不合法
        for (int i = 0; i < total_state; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) {
                    if (cnt & 1) st[i] = false;
                    cnt = 0;
                } else {
                    cnt++;
                }
            }
            if (cnt & 1) st[i] = false;
        }

        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        for (int i = 1; i <= m; i++) {
            // 枚举第i列的状态j
            for (int j = 0; j < total_state; j++) {
                // 在第i列状态为j的情况下，枚举第i-1列的状态k
                for (int k = 0; k < total_state; k++) {
                    // 如果地i列和第j列的状态在地i-1列上没有重叠
                    // 同时将两种状态设置后没有奇数个连续的0
                    // 说明可以从地i-1列的状态k转移到第i列的状态j
                    if (!(j & k) && st[j | k]) {
                        dp[i][j] += dp[i - 1][k];
                    }
                }
            }
        }

        printf("%lld\n", dp[m][0]);
    }
    return 0;
}

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m), n || m) {
        const int total_state = (1 << n);

        for (int i = 0; i < total_state; i++)
            st[i] = true;

        // 预处理，检查所有状态，把存在连续个奇数0的状态标为不合法
        for (int i = 0; i < total_state; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) {
                    if (cnt & 1) st[i] = false;
                    cnt = 0;
                } else {
                    cnt++;
                }
            }
            if (cnt & 1) st[i] = false;
        }

        // 对于给定的状态i，判断能否从状态j转移过来
        // 如果可以，就把j加入status[i]
        for (int i = 0; i < total_state; i++) {
            states[i].clear();
            for (int j = 0; j < total_state; j++) {
                if (!(i & j) && st[i | j])
                    states[i].push_back(j);
            }
        }

        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        for (int i = 1; i <= m; i++) {
            // 枚举第i列的状态j
            for (int j = 0; j < total_state; j++) {
                // 取出所有可以转移到状态j的状态，作为i-1列的状态
                for (int s : states[j]) {
                    dp[i][j] += dp[i - 1][s];
                }
            }
        }

        printf("%lld\n", dp[m][0]);
    }
    return 0;
}
