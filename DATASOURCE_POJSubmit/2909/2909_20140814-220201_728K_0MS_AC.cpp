/*************************************************************************
	> File Name: a.cpp
	> Author: He Shuwei
	> Mail: 
	> Created Time: 2014年08月13日 星期三 22时32分03秒
 ************************************************************************/
#include <cstdio>
#include <cmath>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <algorithm>
#define M ((1 << 15) + 10)
using namespace std;


int prime[3525], n;
bool a[M];

void makeprime(){
    int i, j;
    fill(a, a + M, false);
    n = 1;
    prime[n++] = 2;
    a[0] = true;
    a[1] = true;
    for(i = 2; i < M; i++){
        if(!a[i])
        prime[n++] = i;
        for(j = 1; j < n && i * prime[j] < M; j++){
            a[i * prime[j]] = true;
            if(i % prime[j] == 0)
            break;
        }
    }
}

int main(){
    makeprime();
    int ans, i, j, t;
    while(scanf("%d", &t) != EOF && t){
        ans = 0;
        for(i = 1; i < n; i++){
            if(prime[i] > t - prime[i])
            break;
            if((!a[prime[i]]) && (!a[t - prime[i]]))
            ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
