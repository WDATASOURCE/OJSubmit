/*************************************************************************
> File Name: a.cpp
> Author: He Shuwei
> Mail: 
> Created Time: 2014年08月15日 星期五 23时26分00秒
************************************************************************/
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

int prime[280];
bool a[1105];
int n;

void makeprime(){
    n = 0;
    prime[n++] = 1;
    fill(a, a + 1102, false);
    for(int i = 2; i < 1102; i++){
        if(!a[i])
        prime[n++] = i;
        for(int j = 1; j < n && i * prime[j] < 1102; j++){
            a[i * prime[j]] = true;
            if(i % prime[j] == 0)
            break;
        }
    }
}

int find(int x){
    int l = -1, r = n, mid;
    while(r - l > 1){
        mid = (l + r) / 2;
        if(prime[mid] <= x) l = mid;
        else r = mid;
    }
    return l;
}

int main(){
    makeprime();
    int i, j, m, c, ans;
    while(scanf("%d%d", &m, &c) != EOF){
        printf("%d %d: ", m, c);
        while(a[m])
        m--;
        int mp = find(m);
        j = mp / 2 - c + 1;
        int ed = j + c * 2 - ((mp + 1) % 2);
        if(m == 2 && c == 1)
        j = 1, ed = 2;
        if(j < 0)
        j = 0, ed = mp + 1;
        for(i = j; i < ed; i++ ){
            printf("%d", prime[i]);
            if(i == ed - 1)
            printf("\n\n");
            else
            printf(" ");
        }
    }
    return 0;
}
