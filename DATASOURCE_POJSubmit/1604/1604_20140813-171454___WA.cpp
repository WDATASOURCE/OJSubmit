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

int main(){
    int n, i, a;
    while(scanf("%d", &n) != EOF){
        int ans = 1;
        if(n == 0 || n == 1){
            cout << setw(5) << 1 << endl;
            continue;
        }
        for(i = 1; i <= n; i++){
            ans *= i;
            while(ans % 10 == 0)
                ans /= 10;
            ans %= 10000;
        }
        cout << setw(5) << ans % 10 << endl;
    }
    return 0;
}
