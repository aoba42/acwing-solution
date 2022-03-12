#include <iostream>
#include <algorithm>
using namespace std;

const int N = 50010;
typedef pair<int, int> PII;
PII a[N];

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int w, s; cin >> w >> s;
        a[i] = {w + s, w};
    }
    sort(a, a + n);
    long long res = -1e9;
    for (int i = 0, sum = 0; i < n; i++) {
        int s = a[i].first - a[i].second;
        int w = a[i].second;
        res = max(res, (long long)sum - s);
        sum += w;
    }
    cout << res << endl;
}