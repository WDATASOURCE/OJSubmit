/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-05-31 16:57
# Filename:         c.cpp
# Description: 
=============================================================================*/
 
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;
 
const double eps = 1e-6;

int main() {
    int T;
    double x;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        scanf("%lf", &x);
        printf("Case #%d:\n", cas);
        vector <long long> v;

        for (int len = 2; len <= 10; len++) {
            long long mul = 1;
            for (int i = 1; i < len; i++) mul *= 10;
            for (int head = 1; head < 10; head++) {
                for (int tail = 0; tail < 10; tail++) {
                    double MM = ((double)tail * mul + (double)head - (double)head * mul * x - (double)tail * x) / (10.0 * (x - 1.0));
                    //        cout << "MM = " << MM << endl;
                    if (MM < 100000000.0) {
                        int mm = (int)MM;
                        //            cout << "mm = " << mm << endl;
                        if (abs(MM - mm) > abs(MM - (mm + 1))) mm++;
                        if (abs(MM - mm) < eps) {
                            if (mm >= 0 && mm < mul / 10) {
                                //    cout << "push = " << (long long)head * mul + (long long)mm * 10 + (long long)tail << endl;
                                v.push_back((long long)head * mul + (long long)mm * 10 + (long long)tail);
                            }
                        }
                    }
                }
            }
        }
        printf("%d\n", v.size());
        for (int i = 0; i < v.size(); i++) {
            printf("%I64d", v[i]);
            if (i == v.size() - 1) printf("\n");
            else printf(" ");
        }
    }
    return 0;
}