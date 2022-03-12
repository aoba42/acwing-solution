#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1010, M = 15;
int n, m, dp[M][M];
char str[N][M];

int edit_distance(char *s1, char *s2) {
    int l1 = strlen(s1 + 1), l2 = strlen(s2 + 1);
    for (int i = 0; i <= l1; i++) dp[i][0] = i;
    for (int i = 0; i <= l2; i++) dp[0][i] = i;

    for (int i = 1; i <= l1; i++) {
        for (int j = 1; j <= l2; j++) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (s1[i] != s2[j]));
        }
    }
    return dp[l1][l2];
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", &str[i][1]);
    for (int i = 0; i < m; i++) {
        char s[M];
        int limit;
        scanf("%s%d", &s[1], &limit);
        int res = 0;
        for (int j = 0; j < n; j++) {
            if (edit_distance(str[j], s) <= limit)
                res++;
        }
        printf("%d\n", res);
    }
    return 0;
}
