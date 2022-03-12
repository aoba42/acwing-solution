#include <cstdio>
using namespace std;

const int N = 1e5+10;
int stk[N], tt = 0;

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        while (tt > 0 && x <= stk[tt - 1]) tt--;
        if (tt > 0) printf("%d ", stk[tt - 1]);
        else printf("-1 ");
        stk[tt++] = x;
    }
    return 0;
}
