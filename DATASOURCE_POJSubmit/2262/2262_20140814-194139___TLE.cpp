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

void makeprime(){
    int i, j;
    fill(a, a + 1299800, false);
    n = 1;
    prime[n] = 2;
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
    int t, ans, i, j;
    while(scanf("%d", &t) && t){
        if(t == 0)
        break;
        int f = 0;
        for(i = 1; i < n; i++){
            for(j = i + 1; j < n; j++)
                if(t == prime[i] + prime[j]){
                    f = 1;
                    break;
                }
            if(f == 1)
            break;
        }
        printf("%d = %d + %d\n", t, i, j);
    }
    return 0;
}
