#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1010, V = 2010;

int n, v, vs[12 * N], ws[12 * N], dp[12 * N];

int main() {
    scanf("%d%d", &n, &v);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int a, b, s;
        scanf("%d%d%d", &a, &b, &s);
        int j = 1;
        while (j <= s) {
            cnt++;
            vs[cnt] = a * j;
            ws[cnt] = b * j;
            s -= j;
            j *= 2;
        }
        if (s > 0) {
            cnt++;
            vs[cnt] = a * s;
            ws[cnt] = b * s;
        }
    }
    n = cnt;

    for (int i = 1; i <= n; i++) {
        for (int j = v; j >= vs[i]; j--) {
            dp[j] = max(dp[j], dp[j - vs[i]] + ws[i]);
        }
    }
    printf("%d\n", dp[v]);
    return 0;
}