#include <cstdio>
using namespace std;

const int N = 1e5+10;
typedef long long LL;
LL A[N], B[N];

int main() {
    int n, m, x; scanf("%d%d%d", &n, &m, &x);
    for (int i = 0; i < n; i++) scanf("%lld", &A[i]);
    for (int i = 0; i < m; i++) scanf("%lld", &B[i]);
    for (int i = 0, j = m - 1; i < n && j >= 0; i++) {
        while (j >= 0 && A[i] + B[j] > x) j -= 1;
        if (A[i] + B[j] == x) {
            printf("%d %d\n", i, j);
            break;
        }
    }
    return 0;
}