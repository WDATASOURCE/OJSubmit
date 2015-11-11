#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 10000010
using namespace std;

const long long MOD = 4294967296LL;

struct Point{
    unsigned int l, r;
    int id;

};

Point point[N];
bool visl[N];

int n, l, r, a, b, c, d;

bool inline cmp1 (const Point &a, const Point &b){
    return a.l < b.l;
}

bool inline cmp2 (const Point &a, const Point &b){
    return a.r < b.r;
}

bool inline func1(int x){
    int ll = x;
    int rr = n + 1;
    int mid;
    while(rr - ll > 1){
        mid = (ll + rr) >> 1;
        if(point[mid].l > point[x].r) rr = mid;
        else ll = mid;
    }
    if(rr <= n) return true;
    else return false;
}

bool inline func2(int x){
    if(point[1].r < point[x].l) return true;
    else return false;
}

int main(){
    int t;
    scanf("%d", &t);
    for(int di = 1; di <= t; di++){
        scanf("%d%d%d%d%d%d%d", &n, &l, &r, &a, &b, &c, &d);
        unsigned int aa = a, bb = b, cc = c, dd = d;
        point[1].l = l, point[1].r = r;
        point[1].id = 1;
        for(int i = 2; i <= n; i++){
            point[i].id = i;
            point[i].l = ((aa * point[i - 1].l + bb));
            point[i].r = ((cc * point[i - 1].r + dd));
        }
        if(n > 100){
            printf("YES\n");
        }else{
            sort(point + 1, point + 1 + n, cmp1);
            for(int i = 2; i < n; i++){
                visl[point[i].id] = func1(i);
            }
            sort(point + 1, point + 1 + n, cmp2);
            bool flag = false;
            for(int i = 2; i < n; i++){
                bool f = func2(i);
                if(f && visl[point[i].id]){
                    flag = true;
                    break;
                }
            }
            if(flag) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}
