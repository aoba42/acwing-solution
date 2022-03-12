#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1010;
int a[N], dp[N], n;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (a[j] < a[i]) {
                dp[i] = max(dp[i], dp[j]);
            }
        }
        dp[i]++;
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
        res = max(res, dp[i]);
    printf("%d\n", res);
    return 0;
}
