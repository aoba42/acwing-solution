#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1010;
int n, v, vs[N], ws[N], dp[N];

int main() {
    scanf("%d%d", &n, &v);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &vs[i], &ws[i]);
    for (int i = 1; i <= n; i++) {
        for (int j = vs[i]; j <= v; j++) {
            dp[j] = max(dp[j], dp[j - vs[i]] + ws[i]);
        }
    }
    printf("%d\n", dp[v]);
    return 0;
}
