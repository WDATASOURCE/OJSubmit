#include <cstdio>

const double eps = 1e-9;
double x, y;

int main() {
    while (~scanf("%lf%lf", &x, &y)) {
        if (x > y) {
            printf("-1\n");
            continue;
        }
        double s = (y + 1 - eps) / x;
        double tmp = 1;
        int count = (int)x - 1;
        for (int i = 1; i <= (int)x; i++) {
            int sb = (int)(s * i - tmp);
            tmp += sb;
            tmp = tmp / i * (i + 1);
            count += sb;
        }
        printf("%d\n", count);
    }
    return 0;
}
