#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void big_div(vector<int> &A, int b, vector<int> &C, int &r) {
    r = 0;
    for (int i = A.size() - 1; i >= 0; i--) {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end());
    while (C.size() > 1 && C.back() == 0)
        C.pop_back();
}

int main() {
    string a;
    int b, r;
    vector<int> A, C;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');
    big_div(A, b, C, r);
    for (int i = C.size() - 1; i >= 0; i--)
        printf("%d", C[i]);
    printf("\n%d\n", r);
}