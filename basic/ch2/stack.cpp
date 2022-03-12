#include <cstdio>
using namespace std;

const int N = 1e5+10;
int stk[N], tt = 0;

int main() {
    int n; scanf("%d", &n);
    char cmd[10];
    int x;
    while (n--) {
        scanf("%s", cmd);
        if (cmd[0] == 'p' && cmd[1] == 'u') {
            scanf("%d", &x);
            stk[tt++] = x;
        } else if (cmd[0] == 'p' && cmd[1] == 'o') {
            tt--;
        } else if (cmd[0] == 'e') {
            if (tt > 0) printf("NO\n");
            else printf("YES\n");
        } else if (cmd[0] == 'q') {
            printf("%d\n", stk[tt - 1]);
        }
    }
}