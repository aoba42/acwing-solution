#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> trans(int n) {
    vector<int> res;
    while (n) {
        res.push_back(n % 10);
        n /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

int get(int l, int r, vector<int> &ds) {
    int res = 0;
    for (int i = l; i <= r; i++)
        res = res * 10 + ds[i];
    return res;
}

int power10(int n) {
    int res = 1;
    while (n--) res *= 10;
    return res;
}

long long count(int n, int d) {
    vector<int> digits = trans(n);
    long long res = 0;
    int len = digits.size();
    for (int i = 0; i < len; i++) {
        if (!(i == 0 && d == 0) && d <= digits[i])
            res += power10(len - i - 1);
        int rv = get(0, i - 1, digits);
        res += rv * power10(len - i - 1);
    }
    return res;
}

int main() {
    int a, b;
    while (cin >> a >> b, a || b) {
        if (a > b) swap(a, b);
        for (int i = 0; i < 10; i++) {
            cout << count(b, i) - count(a - 1, i) << " ";
        }
        cout << endl;
    }
    return 0;
}