#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1e5+10;
typedef pair<int, int> PII;
vector<PII> segs, res;
int n;

void range_merge(vector<PII> &segs, vector<PII> &res) {
    if (segs.size() == 0) return;
    int s = segs[0].first, e = segs[0].second;
    for (int i = 1; i < segs.size(); i++) {
        int ns = segs[i].first, ne = segs[i].second;
        if (e >= ns) e = max(e, ne);
        else {
            res.push_back({s, e});
            s = ns, e = ne;
        }
    }
    res.push_back({s, e});
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        segs.push_back({l, r});
    }
    sort(segs.begin(), segs.end());
    range_merge(segs, res);
    printf("%d\n", res.size());
}

