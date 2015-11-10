/*************************************************************************
	> File Name: a.cpp
	> Author: He Shuwei
	> Mail: 
	> Created Time: 2014年09月12日 星期五 18时08分52秒
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
char ch[1005][20];
int a[1005];
char s[1005];
char s1[20];

int main(){
    int i, j, ans, n, m;
    scanf("%d%d", &m, &n);
    for(i = 0; i < m; i++){
        scanf("%s", ch[i]);
        scanf("%d", &a[i]);
    }
    for(i = 0; i < n; i++){
        long long ans = 0;
        while(1){
            gets(s);
            if(strlen(s) == 1 && s[0] == '.'){
                printf("%lld\n", ans);
                break;
            }
            int l = 0;
            int len = strlen(s);
            for(j = 0; j <= len; j++){
                if(s[j] == ' ' || s[j] == '\0' || s[j] == '\n'){
                    s1[l] = '\0';
                    for(int k = 0; k < m; k++){
                        if(strcmp(s1, ch[k]) == 0){
                            ans += a[k];
                            break;
                        }
                    }
                    l = 0;
                }
                else{
                    s1[l++] = s[j];
                }
            }
        }
    }
    return 0;
}
