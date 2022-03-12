#include <cstdio>
#include <cstring>

const int N = 1e5 + 10;
int n, a[N], tmp[N];

void merge_sort(int *a, int s, int e) {
    if (s >= e) return;
    int m = s + e >> 1;
    merge_sort(a, s, m);
    merge_sort(a, m + 1, e);
    int i = s, j = m + 1, k = 0;
    while (i <= m && j <= e) {
        if (a[i] <= a[j]) tmp[k++] = a[i++];
        else tmp[k++] = a[j++];
    }
    while (i <= m) tmp[k++] = a[i++];
    while (j <= e) tmp[k++] = a[j++];
    memcpy(&a[s], tmp, sizeof(int) * (e - s + 1));
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    merge_sort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
