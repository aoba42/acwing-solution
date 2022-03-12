#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100010;
int a[N];

void quick_sort(int *a, int s, int e) {
    if (s >= e) return;
    int x = a[s + e >> 1];
    int i = s - 1, j = e + 1;
    while (i < j) {
        do i++; while (a[i] < x);
        do j--; while (a[j] > x);
        if (i < j) swap(a[i], a[j]);
    }
    quick_sort(a, s, j);
    quick_sort(a, j + 1, e);
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    quick_sort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
