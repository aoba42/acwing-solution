#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int n, a[N], s[N] = { 0 };

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int i = 0, j = 0, res = 0;
    for (int i = 0, j = 0; i < n; i++) {
        s[a[i]]++;
        while (j <= i && s[a[i]] > 1) {
            s[a[j]]--;
            j += 1;
        }
        res = max(res, i - j + 1);
    }
    printf("%d\n", res);
}