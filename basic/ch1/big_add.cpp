#include <cstdio>
#include <vector>
using namespace std;

vector<int> a, b, c;
const int N = 1e5 + 10;
char num[N];

void big_add(vector<int> &a, vector<int> &b, vector<int> &c) {
    int t = 0;
    for (int i = 0; i < a.size() || i < b.size(); i++) {
        if (i < a.size()) t += a[i];
        if (i < b.size()) t += b[i];
        c.push_back(t % 10);
        t /= 10;
    }
    if (t != 0) c.push_back(1);
}

int main() {
    scanf("%s", num);
    for (int i = 0; num[i] != '\0'; i++)
        a.push_back(num[i] - '0');
    for (int i = 0, j = a.size() - 1; i < j; i++, j--)
        swap(a[i], a[j]);

    scanf("%s", num);
    for (int i = 0; num[i] != '\0'; i++)
        b.push_back(num[i] - '0');
    for (int i = 0, j = b.size() - 1; i < j; i++, j--)
        swap(b[i], b[j]);

    big_add(a, b, c);
    for (int i = c.size() - 1; i >= 0; i--)
        printf("%d", c[i]);
    printf("\n");
    return 0;
}