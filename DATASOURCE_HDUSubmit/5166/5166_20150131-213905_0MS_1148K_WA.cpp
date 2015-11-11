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
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;
bool is[1005];
 
int main(){
    int t, n, v;
    scanf("%d", &t);
    while(t--){
        fill(is, is + 1005,  false);
        scanf("%d", &n);
        int ma = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &v);
            is[v] = true;
            ma = ma > v ? ma : v;
        }
        int sum = 0;
        for(int i = 1; i <= ma; i++)
            if(!is[i]){ 
                sum++;
                printf("%d%c", i, sum == 2 ? '\n': ' ');
            }
        sum++;
        for(; sum < 3; sum++){
            printf("%d%c", sum + ma, sum == 2 ? '\n' : ' ');
        }
    }
    return 0;
}
