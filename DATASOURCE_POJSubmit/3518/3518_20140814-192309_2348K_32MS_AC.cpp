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
using namespace std;
int prime[100005], n;
bool a[1299800];
int find(int x){
    int mid;
    int l = 0, r = 100003;
    while(r - l > 1){
        mid = (l + r) / 2;
        if(prime[mid] < x)
        l = mid;
        else
        r = mid;
    }
    return l;
}

void makeprime(){
    int i, j;
    fill(a, a + 1299800, false);
    n = 1;
    prime[n++] = 2;
    a[0] = true;
    a[1] = true;
    for(i = 2; i < 1299710; i++){
        if(!a[i])
        prime[n++] = i;
        for(j = 1; j < n && i * prime[j] < 1299800; j++){
            a[i * prime[j]] = true;
            if(i % prime[j] == 0)
            break;
        }
    }
}

int main(){
    makeprime();
    int t, ans;
    while(scanf("%d", &t) && t){
        if(t == 0)
        break;
        else if(!a[t])
            ans = 0;
        else{
            int d = find(t);
            ans = prime[d + 1] - prime[d];
            
        }
        printf("%d\n", ans);
    }
    return 0;
}
