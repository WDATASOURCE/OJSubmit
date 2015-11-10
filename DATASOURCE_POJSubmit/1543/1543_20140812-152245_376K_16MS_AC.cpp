/*=============================================================================
# Author: He Shuwei
# Last modified:	2014-08-11 16:02
# Filename:			b.cpp
# Description: 
=============================================================================*/
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
    int n, l, i, j, k;
    while(scanf("%d", &n) != EOF){
        for(l = 2; l <= n; l++)
            for(i = 2; i < l; i++)
                for(j = i + 1; j < l; j++)
                    for(k = j + 1; k < l; k++)
                        if(l * l * l == i * i * i + j * j * j + k * k *k)
                            printf("Cube = %d, Triple = (%d,%d,%d)\n", l, i, j, k);
    }
    return 0;
}
