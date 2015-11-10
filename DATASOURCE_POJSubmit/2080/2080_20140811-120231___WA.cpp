/*=============================================================================
# Author: He Shuwei
# Last modified:	2014-08-11 11:07
# Filename:			b.cpp
# Description: 
=============================================================================*/
#include <cstdio>
#include <iostream>
using namespace std;
int year[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char ch[7][10] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

bool isrun(int x){
    if(x % 100 == 0)
        return true;
    else if(x % 4 == 0 && x % 100)
        return true;
    else 
        return false;
}

int main(){
    int n, i, y, m, d; 
    while(scanf("%d", &n) != EOF && n != -1){
        int s = 0, sum = 0;
        for(i = 0; ; i++){
            s = 365;
            if(i % 4 == 0)
                s++;
            sum += s;
            if(sum > n)
                break;
        }
        sum -= s;
        y = i + 2000;
        if(isrun(y))
            year[2] = 29;
        else 
            year[2] = 28;
        i = 0;
        while(sum <= n){
            s = year[++i];
            sum += s;
        }
        sum -= s;
        m = i;
        for(i = 1; i <= year[m]; i++){
            if(sum == n)
                break;
            sum++;
        }
        d = i;
        printf("%d-", y);
        if(m <= 9)
            printf("0%d-", m);
        else
            printf("%d-", m);
        if(d <= 9)
            printf("0%d ", d);
        else
            printf("%d ", d);
        printf("%s\n", ch[n % 7]);
    }
    return 0;
}
