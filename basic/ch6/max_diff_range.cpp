#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5+10, INF = 2e9;

struct range {
    int l, r;
    bool operator<(range &rhs) const {
        return this->r < rhs.r;
    }
} rngs[N];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        rngs[i] = {l, r};
    }
    sort(rngs, rngs + n);
    int cnt = 0, end = -INF;
    for (int i = 0; i < n; i++) {
        range rng = rngs[i];
        if (end < rng.l)
            cnt++, end = rng.r;
    }
    cout << cnt << endl;
}