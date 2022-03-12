#include <cstdio>
using namespace std;

const int N = 1e5+10;
int a[N], n;
int lowbit(int x) { return x & -x; }

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) {
        int x = a[i], cnt = 0;
        while (x != 0) {
            cnt++;
            x -= lowbit(x);
        }
        printf("%d ", cnt);
    }
    return 0;
}