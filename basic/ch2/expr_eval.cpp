#include <cstdio>
#include <cctype>
#include <cstring>
using namespace std;

const int N = 1e5+10;
char e[N], os[N];
int ns[N], ott = 0, ntt = 0;

int getp(char op) {
    if (op == '(') return 0;
    else if (op == '+' || op == '-') return 1;
    else if (op == '*' || op == '/') return 2;
}

void eval() {
    int b = ns[--ntt];
    int a = ns[--ntt];
    char op = os[--ott];
    switch (op) {
        case '+': ns[ntt++] = a + b; break;
        case '-': ns[ntt++] = a - b; break;
        case '*': ns[ntt++] = a * b; break;
        case '/': ns[ntt++] = a / b; break;
    }
}

int main() {
    scanf("%s", e);
    int elen = strlen(e), i = 0;
    while (i < elen) {
        if (isdigit(e[i])) {
            int num = e[i++] - '0';
            while (isdigit(e[i]))
                num = num * 10 + e[i++] - '0';
            ns[ntt++] = num;
        } else if (e[i] == '(') {
            os[ott++] = '(';
            i++;
        } else if (e[i] == ')') {
            while (os[ott - 1] != '(')
                eval();
            ott--, i++;
        } else {
            int p1 = getp(e[i]);
            int p2 = ott > 0 ? getp(os[ott - 1]) : 0;
            while (p1 <= p2) {
                eval();
                p2 = ott > 0 ? getp(os[ott - 1]) : 0;
            }
            os[ott++] = e[i++];
        }
    }
    while (ott > 0) eval();
    printf("%d\n", ns[ntt - 1]);
    return 0;
}
