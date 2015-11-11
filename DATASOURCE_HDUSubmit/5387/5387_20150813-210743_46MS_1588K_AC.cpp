/*=============================================================================
# Author:           He Shuwei
# Last modified:     2015-08-13 15:07
# Filename:         b.cpp
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
#define ABS(a) ((a) > 0 ? (a) : (-(a)))
using namespace std;

struct Frac{
    int a, b;

    int GCD(int a, int b){
        if(a == 0) return b;
        else return GCD(b % a, a);
    }

    Frac(int aa, int bb = 1){
        a = aa, b = bb;

        int temp = GCD(a, b);
        a /= temp, b /= temp;
    }

    Frac(){}

    Frac huaJian(Frac t){
        int temp = GCD(t.a, t.b);
        t.a /= temp, t.b /= temp;
        return t;
    }

    Frac addFrac(Frac t){
        Frac ans;

        ans.a = a * t.b + b * t.a;
        ans.b = b * t.b;
        ans = huaJian(ans);
        return ans;
    }

    Frac jianFrac(Frac t){
        Frac ans;

        ans.a = a * t.b - b * t.a;
        ans.b = b * t.b;

        if(ans.a < 0) ans.a = -ans.a;

        ans = huaJian(ans);

        return ans;
    }

    Frac quYu(int t){
        Frac ans(a, b);
        t *= b;
        while(ans.a >= t) ans.a -= t; 
        ans = huaJian(ans);
        return ans;
    }
};

Frac getAngle(int s, int i){
    if(i == 1){
        Frac ans(s, 120);
        return ans.quYu(360);
    }else if(i == 2){
        Frac ans(s, 10);
        return ans.quYu(360);
    }else{
        Frac ans(6 * s);
        return ans.quYu(360);
    }
}

Frac ruiJiao(Frac i){
    Frac t(i.b * 360 - i.a, i.b);
    if(t.a < i.a) return t.huaJian(t);
    else return i;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int h, m, s;
        scanf("%d:%d:%d", &h, &m, &s);
        int ss = h * 3600 + m * 60 + s;
        Frac H(ss);
        Frac M(ss);
        Frac S(ss);

        Frac HH = getAngle(ss, 1);
        Frac MM = getAngle(ss, 2);
        Frac SS = getAngle(ss, 3);

        Frac HM = HH.jianFrac(MM);
        Frac MS = MM.jianFrac(SS);
        Frac HS = HH.jianFrac(SS);

        HM = ruiJiao(HM);
        HS = ruiJiao(HS);
        MS = ruiJiao(MS);

        if(HM.b == 1) printf("%d ", HM.a);
        else printf("%d/%d ", HM.a, HM.b);
        if(HS.b == 1) printf("%d ", HS.a);
        else printf("%d/%d ", HS.a, HS.b);
        if(MS.b == 1) printf("%d ", MS.a);
        else printf("%d/%d ", MS.a, MS.b);
        printf("\n");
    }
    return 0;
}
