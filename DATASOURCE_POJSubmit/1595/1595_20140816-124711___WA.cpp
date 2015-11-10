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
    return;
}

int find(int x){
    int l = -1, r = n, mid;
    while(r - l > 1){
        mid = (l + r) / 2;
        if(prime[mid] <= x)
        l = mid;
        else
        r = mid;
    }
    return l;
}

int main(){
    makeprime();
    int i, m, c, ans, st;
    while(scanf("%d%d", &m, &c) != EOF){
        printf("%d %d: ", m, c);
        int di = m;
        while(a[di])
        di--;
        di = find(di);
        di++;
        if(di == 1){
            printf("%d\n", prime[0]);
            continue;
        }
        else if(di % 2 == 0)
        st = (di - c * 2) / 2;
        else
        st = (di - c * 2 + 1) / 2;
        if(st < 0)
        for(i = 0; i < di; i++){
            printf("%d", prime[i]);
            if(i == di - 1)
            printf("\n");
            else
            printf(" ");
        }
        else
        for(i = st; i < st + c * 2; i++){
            printf("%d", prime[i]);
            if(i == st + c * 2 - 1)
            printf("\n");
            else
            printf(" ");
        }
    }
    return 0;
}
