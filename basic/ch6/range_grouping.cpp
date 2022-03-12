#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

const int N = 1e5+10;

struct range {
    int l, r;
    bool operator<(const range &rhs) const {
        return this->l < rhs.l;
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
    priority_queue<int, vector<int>, greater<>> heap;
    for (int i = 0; i < n; i++) {
        range rng = rngs[i];
        if (!heap.empty()) {
            if (heap.top() >= rng.l) {
                // 当前区间和右端点最左的组有交点的情况下
                // 把当前区间作为新的一组
                heap.push(rng.r);
            } else {
                // 当前区间和右端点最左的组没有交点的情况下
                // 把当前区间加到该组中，并更新该组的最左右端点为当前区间的右端点
                heap.pop();
                heap.push(rng.r);
            }
        } else {
            heap.push(rng.r);
        }
    }
    cout << heap.size() << endl;
}
