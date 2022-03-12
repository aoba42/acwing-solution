#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int a[N];

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    long long res = 0;
    for (int i = 0, j = n - 1; i < n; i++, j--) {
        res += a[i] * j;
    }
    cout << res << endl;
}