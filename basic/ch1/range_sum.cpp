#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 3 * 1e5 + 10;
int a[N], s[N];
vector<int> all;
typedef pair<int, int> PII;
vector<PII> insert, query;

int find(int x) {
    int l = 0, r = all.size() - 1;
    while (l < r) {
        int mid = l + r >> 1;
        if (all[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l + 1;
}

int main() {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        int x, c; scanf("%d%d", &x, &c);
        insert.push_back({x, c});
        all.push_back(x);
    }
    for (int i = 0; i < m; i++) {
        int l, r; scanf("%d%d", &l, &r);
        query.push_back({l, r});
        all.push_back(l);
        all.push_back(r);
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    for (auto item : insert) {
        int p = find(item.first);
        a[p] += item.second;
    }
    s[0] = 0;
    for (int i = 1; i <= all.size(); i++)
        s[i] = s[i - 1] + a[i];
    for (auto item : query) {
        int l = find(item.first);
        int r = find(item.second);
        printf("%d\n", s[r] - s[l - 1]);
    }
    return 0;
}
