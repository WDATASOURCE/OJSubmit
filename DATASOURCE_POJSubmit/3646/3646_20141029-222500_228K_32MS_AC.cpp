/*************************************************************************
	> File Name: a.cpp
	> Author: He Shuwei
	> Mail: 
	> Created Time: 2014年10月29日 星期三 22时03分39秒
 ************************************************************************/

#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <algorithm>
#define N 20010 
using namespace std;

int a[N];
int h[N];

int main(){
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF && (n || m)){
        for(int i = 0; i < n; i++){
            scanf("%d", &h[i]);
        }
        for(int i = 0; i < m; i++){
            scanf("%d", &a[i]);
        }
        sort(a, a + m);
        sort(h, h + n);
        int id = 0;
        int sum = 0;
        for(int i = 0; i < m; i++){
            if(a[i] >= h[id]){
                id++;
                sum += a[i];
                if(id == n)
                break;
            }
        }
        if(id < n)
        printf("Loowater is doomed!\n");
        else
        printf("%d\n", sum);
    }

return 0;
}
