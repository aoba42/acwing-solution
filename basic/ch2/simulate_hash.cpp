#include <cstdio>
#include <cstring>
using namespace std;

const int N = 200003, null = 0x3f3f3f3f;
int h[N];

int find(int x) {
    int i = (x % N + N) % N;
    while (h[i] != x && h[i] != null) i++;
    return i;
}

int main() {
    memset(h, 0x3f, sizeof h);
    int n, x; scanf("%d", &n);
    char op[2];
    while (n--) {
        scanf("%s%d", op, &x);
        if (*op == 'I') {
            h[find(x)] = x;
        } else {
            int t = find(x);
            if (h[t] == x) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
