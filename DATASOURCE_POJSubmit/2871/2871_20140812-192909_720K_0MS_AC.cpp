/*=============================================================================
# Author: He Shuwei
# Last modified:	2014-08-11 16:02
# Filename:			b.cpp
# Description: 
=============================================================================*/
#include <cstdio>
#include <iostream>
using namespace std;

int main(){
    double a, b;
    scanf("%lf", &a);
    while(scanf("%lf", &b) != EOF){
        if(999 - b < 1e-4){
            printf("End of Output\n");
            break;
        }
        printf("%.2f\n", b - a);
        a = b;
    }
    return 0;
}
