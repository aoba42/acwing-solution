#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5+10, INF = 2e9;

struct range {
    int l, r;
    bool operator<(const range &rhs) const {
        return this->l < rhs.l;
    }
} rngs[N];

int main() {
    int s, t, n; cin >> s >> t >> n;
    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        rngs[i] = {l, r};
    }
    sort(rngs, rngs + n);
    /*for (int i = 0; i < n; i++)
        cout << rngs[i].l << " " << rngs[i].r << endl;
    cout << "========================" << endl;*/
    int end = s, cnt = 0, i = 0, max = s;
    while (i < n && end < t) {
        int j = i;
        //cout << end << ": " << endl;
        while (i < n && rngs[i].l <= end) {
            //cout << ">>>> " << rngs[i].l << " " << rngs[i].r << endl;
            if (rngs[i].r > max) {
                max = rngs[i].r;
                j = i;
            }
            i++;
        }
        //cout << "res: " << rngs[j].l << " " << rngs[j].r << endl;
        if (rngs[j].l > end) {
            cnt = -1;
            break;
        }
        cnt++;
        end = rngs[j].r;
        if (t <= end) break;
    }
    if (end < t) cnt = -1;
    cout << cnt << endl;
    return 0;
}
