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

char ch[110][110];


int main(){
    char s1[20];
    char s[110] = {"http://www.acm.org/"};
    strcpy(ch[0], s);
    int p = 0, n = 1;
    while(1){
        scanf("%s", s1);
        if(strcmp(s1, "QUIT") == 0)
            break;
        else if(strcmp(s1, "VISIT") == 0){
            scanf("%s", s);
            strcpy(ch[p + 1], s);
            p++;
            n = p + 1;
            printf("%s\n", s);
        }
        else if(strcmp(s1, "BACK") == 0){
            if(p == 0){
                printf("Ignored\n");
            }
            else{
                printf("%s\n", ch[--p]);
            }
        }
        else if(strcmp(s1, "FORWARD") == 0){
            if(p == n - 1){
                printf("Ignored\n");
            }
            else{
                printf("%s\n", ch[++p]);
            }
        }
    }
    return 0;
}
