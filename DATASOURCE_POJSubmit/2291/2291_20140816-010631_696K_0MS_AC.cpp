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

int a[1005], le[1005], rig[1005];
int n;

int main(){
    int i, t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(i = 0; i < n; i++){
            le[i] = i; 
            rig[i] = i;
        }
        for(i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        for(i = 1; i < n; i++){
            int k = i - 1;
            while(a[k] >= a[i] && k >= 0){
                le[i] = le[k];
                k = le[k] - 1;
            }
        }
        for(i = n - 2; i >= 0; i--){
            int k = i + 1;
            while(a[k] >= a[i] && k <= n - 1){
                rig[i] = rig[k];
                k = rig[k] + 1;
            }
        }
        int ans = 0;
        for(i = 0; i < n; i++)
            ans = ans > a[i] * (rig[i] - le[i] + 1) ? ans : a[i] * (rig[i] - le[i] + 1);
        printf("%d\n", ans);
    }
}
