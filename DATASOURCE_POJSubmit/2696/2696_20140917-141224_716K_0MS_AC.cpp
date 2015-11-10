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
using namespace std;

int ans[1010];
int a, b, c, d, e, f, g, h;

int abss(int a, int b){
    int i;
    if(a >= 0)
        return a % b;
    else{
        a = a * -1;
        for(i = 1; b * i < a; i++);
        return b * i - a;
    }
}

int main(){
    int i, t;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g, &h, &i);
        fill(ans, ans + 1010, 0);
        ans[0] = a;
        ans[1] = b;
        ans[2] = c;
        for(int j = 3; j <= i; j++){
            if(j % 2)
                ans[j] = abss(d * ans[j - 1] + e * ans[j - 2] - f * ans[j - 3], g);
            else
                ans[j] = abss(f * ans[j - 1] - d * ans[j - 2] + e * ans[j - 3], h);
        }
        printf("%d\n", ans[i]);
    }
    return 0;
}
