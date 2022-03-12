#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1e4+10;
int a[N];
int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    priority_queue<int, vector<int>, greater<>> heap{a, a + n};
    long long res = 0;
    while (heap.size() >= 2) {
        int x = heap.top(); heap.pop();
        int y = heap.top(); heap.pop();
        res += x + y;
        heap.push(x + y);
    }
    cout << res << endl;
}