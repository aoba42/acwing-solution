#include <cstdio>
using namespace std;

const int N = 1e5+10;
int q[N], hh = 0, tt = 0; //[hh,tt)

int main() {
    int n; scanf("%d", &n);
    char cmd[10]; int x;
    while (n--) {
        scanf("%s", cmd);
        if (cmd[0] == 'p' && cmd[1] == 'u') {
            scanf("%d", &x);
            q[tt++] = x;
        } else if (cmd[0] == 'p' && cmd[1] == 'o') {
            hh++;
        } else if (cmd[0] == 'e') {
            if (hh == tt) printf("YES\n");
            else printf("NO\n");
        } else if (cmd[0] == 'q') {
            printf("%d\n", q[hh]);
        }
    }
    return 0;
}
