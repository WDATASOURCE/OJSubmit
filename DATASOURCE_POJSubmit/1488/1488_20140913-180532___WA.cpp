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

int main(){
    int i, j;
    char ch;
    while(scanf("%c", &ch) != EOF){
        bool f = true;
        if(ch == '"'){
            if(f)
            printf("``");
            else
            printf("''");
            f = !f;
        }
        else
        printf("%c", ch);
    }
    return 0;
}
