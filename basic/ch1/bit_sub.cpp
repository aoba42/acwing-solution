#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool gt_eq(vector<int> &A, vector<int> &B) {
    if (A.size() != B.size()) return A.size() > B.size();
    for (int i = A.size() - 1; i >= 0; i--) {
        if (A[i] != B[i]) return A[i] > B[i];
    }
    return true;
}

void big_sub(vector<int> &A, vector<int> &B, vector<int> &C) {
    for (int i = 0, t = 0; i < A.size(); i++) {
        t += A[i];
        if (i < B.size()) t -= B[i];
        if (t < 0) C.push_back(t + 10), t = -1;
        else C.push_back(t), t = 0;
    }
    while (C.size() > 1 && C.back() == 0)
        C.pop_back();
}

int main() {
    string a, b; cin >> a >> b;
    vector<int> A, B, C;
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--)
        B.push_back(b[i] - '0');
    if (gt_eq(A, B)) {
        big_sub(A, B, C);
    } else {
        big_sub(B, A, C);
        printf("-");
    }
    for (int i = C.size() - 1; i >= 0; i--)
        printf("%d", C[i]);
    return 0;
}