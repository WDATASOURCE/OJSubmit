/*************************************************************************
	> File Name: a.cpp
	> Author: He Shuwei
	> Mail: 
	> Created Time: 2014年10月31日 星期五 22时15分04秒
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
using namespace std;

int a[50050];

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
        for(int i = 1; i <= n; i++){
            if(i == 1 && a[i] >= a[i + 1])
            printf("%d\n", i);
            else if(i == n && a[i] >= a[i - 1])
            printf("%d\n", i);
            else{
                if(a[i] >= a[i - 1] && a[i] >= a[i + 1])
                printf("%d\n", i);
            }
        }
    }
    return 0;
}
