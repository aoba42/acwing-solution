#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;
int a[N];

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int adr = a[n / 2];
    long long res = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < adr) res += adr - a[i];
        else res += a[i] - adr;
    }
    cout << res << endl;
}