#include <queue>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
 
int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        if(!n) break;
        long long ans = 1;
        queue <long long> que;
        while(!que.empty()) que.pop();
        que.push(ans);
        while(!que.empty()){
            long long tt = que.front();
            que.pop();
            tt = tt * 10;
            if(tt % n == 0){
                ans = tt;
                break;
            }else que.push(tt);
            tt = tt + 1;
            if(tt % n == 0){
                ans = tt;
                break;
            }else que.push(tt);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
