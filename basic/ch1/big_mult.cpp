#include <iostream>
#include <vector>
using namespace std;

void big_mult(vector<int> &A, int b, vector<int> &C) {
    int t = 0;
    for (int i = 0; i < A.size(); i++) {
        t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    while (t != 0) {
        C.push_back(t % 10);
        t /= 10;
    }
    while (C.size() > 1 && C.back() == 0)
        C.pop_back();
}

int main() {
    int b;
    string a; cin >> a >> b;
    vector<int> A, C;
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');
    big_mult(A, b, C);
    for (int i = C.size() - 1; i >= 0; i--)
        printf("%d", C[i]);
    return 0;
}