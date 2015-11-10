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

char ch[100];
int a[4];

void change(int len){
    for(int i = 0; i < len; i++)
        a[i] = ch[i] - '0';
}

int main(){
    while(scanf("%s", ch) != EOF){
        int len = strlen(ch);
        if(len == 2 && ch[0] == '-')
            break;
        else if(len != 4){
            printf("N=%s:\nNo!!\n", ch);
            continue;
        }
        change(len);
        int ma = 0, mi = 0;
        int id = 0;
        sort(a, a + len);
        for(int i = 0; i < len; i++){
            mi = mi * 10 + a[i];
            ma = ma * 10 + a[len - 1 - i];
        }
        if(ma == mi){
            printf("N=%s:\nNo!!\n", ch);
            continue;
        }
        int c = ma - mi;
        printf("N=%s:\n", ch);
        while(1){
            id++;
            printf("%d-%d=%d\n", ma, mi, ma - mi);
            if(c == 0 || c == 6174)
            break;
            sprintf(ch, "%d", c);
            len = strlen(ch);
            change(len);
            sort(a, a + len);
            mi = 0, ma = 0;
            for(int i = 0; i < len; i++){
                mi = mi * 10 + a[i];
                ma = ma * 10 + a[len - 1 - i];
            }
            c = ma - mi;
        }
        printf("Ok!! %d ", id);
        if(id == 1)
        printf("time\n");
        else printf("times\n");
    }
    return 0;
}
