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
    int a, b, c;
    double A, B, C;
    while(scanf("%d%d%d", &a, &b, &c) != EOF){
        A = (c - 2 * b + a) / 2.0;
        B = (-3 * a + 4 * b - c) / 2.0;
        C = a;
        int x;
        for(x = 3; x <= 5; x++){
            printf("%d",(int)(A * x * x + B * x + C));
            if(x == 5)
                printf("\n");
            else
                printf(" ");
        }
    }
    return 0;
}
