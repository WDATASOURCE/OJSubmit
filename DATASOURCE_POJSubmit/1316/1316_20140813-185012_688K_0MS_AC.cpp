/*************************************************************************
	> File Name: a.cpp
	> Author: He Shuwei
	> Mail: 
	> Created Time: 2014年08月13日 星期三 22时32分03秒
 ************************************************************************/

#include <cstdio>
#include <cmath>
#include <queue>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;
int a[1000];
bool b[10010];

int cal(int x){
    int sum = x;
    int i, j;
    while(x){
        sum += x % 10;
        x = x / 10;
    }
    return sum;
}

int makea(){
    int i, j = 0;
    fill(b, b + 10010, false);
    a[j++] = 1;
    b[2] = true;
    for(i = 2; i < 10003; i++){
        if(!b[i])
        a[j++] = i;
        int t = cal(i);
        if(t < 10010)
        b[t] = true;
    }
    return j;
}

int main(){
    int n = makea();
    int i;
    for(i = 0; i < n; i++)
        printf("%d\n", a[i]);
    return 0;
}
