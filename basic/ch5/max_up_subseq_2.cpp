#include <cstdio>
using namespace std;

const int N = 100010;
// 设Sn表示长度为n的单调上升子序列构成的集合，
// 设Vn构成Sn中每个序列的最后一个数构成的集合，
// 则q[n]表示Vn中的最小值
int a[N], q[N], n, len;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    for (int i = 1; i <= n; i++) {
        int l = 0, r = len;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (q[mid] < a[i]) l = mid;
            else r = mid - 1;
        }
        if (l == len) len++;
        q[l + 1] = a[i];
    }
    printf("%d\n", len);
    for (int i = 1; i <= n; i++)
        printf("%d ", q[i]);
    printf("\n");
    return 0;
}
