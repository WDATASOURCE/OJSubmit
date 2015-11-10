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
char ch[1000];

int main(){
    int i, j;
    while(gets(ch) != NULL){
        int len = strlen(ch);
        bool f = true;
        for(i = 0; i < len; i++){
            if(ch[i] == '"'){
                if(f)
                printf("``");
                else
                printf("''");
                f = !f;
            }
            else
            printf("%c", ch[i]);
        }
        printf("\n");
    }
    return 0;
}
