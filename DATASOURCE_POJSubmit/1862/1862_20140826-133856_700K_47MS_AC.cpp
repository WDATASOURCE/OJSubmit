#include <cmath>
#include <cstdio>
#include <queue>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){

    int i, j, n;
    double v, ans;
    while(scanf("%d", &n) != EOF){
        priority_queue < double > q;
        for(i = 0; i < n; i++){
            scanf("%lf", &v);
            q.push(v);
        }
        while(q.size() > 1){
            double a = q.top();
            q.pop();
            double b = q.top();
            q.pop();
            ans = 2 * sqrt(a * b);
            q.push(ans);
        }
        ans = q.top();
        printf("%.3f\n", ans);
    }
    return 0;
}
