#include <cstdio>

int main() {
    double x; scanf("%lf", &x);
    double l = 0, r = 0;
    if (x > 0) l = 0, r = x + 1;
    else l = x - 1, r = 0;
    while (r - l > 1e-8) {
        double m = (l + r) / 2;
        if (m * m * m < x) l = m;
        else r = m;
    }
    printf("%.6lf", l);
    return 0;
}