#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 1e5 + 10;
int n, k, a[N];

int kth(int *a, int l, int r, int k) {
    if (l >= r) return a[l];
    int x = a[l + r >> 1];
    int i = l - 1, j = r + 1;
    while (i < j) {
        do i++; while(a[i] < x);
        do j--; while(x < a[j]);
        if (i < j) swap(a[i], a[j]);
    }
    int ls = j - l + 1;
    if (ls <= k) return kth(a, j + 1, r, k - ls);
    else return kth(a, l, j, k);
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("%d\n", kth(a, 0, n - 1, k - 1));
}
