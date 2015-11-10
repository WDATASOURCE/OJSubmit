/*=============================================================================
# Author:			He Shuwei
# Last modified:	2014-09-28 16:05
# Filename:			b.cpp
# Description:
=============================================================================*/

#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int prime[2540];
bool istrue[20010];

void make_prime(){
    int i, di = 0, j;
    fill(istrue, istrue + 20010, false);
    for(i = 2; i < 20010; i++){
        if(!istrue[i])
            prime[di++] = i;
        for(j = 0; (j < di) && (i * prime[j] < 20010); j++){
            istrue[i * prime[j]] = true;
            if(i % prime[j] == 0)
                break;
        }
    }
}

int count_sum(int x){
    int sum = 0;
    while(x){
        sum += (x % 10);
        x /= 10;
    }
    return sum;
}

int main(){
    make_prime();
    int i, n;
    while(scanf("%d", &n) != EOF && n){
        for(i = n + 1; ; i++){
            int di = 0, nn = i;
            int sum1 = 0;
            while(nn && di < 2262){
                while(nn % prime[di] == 0){
                    sum1 += count_sum(prime[di]);
                    nn /= prime[di];
                }
                di++;
            }
            if(nn == 0){
                if(sum1 == count_sum(i))
                    goto A;
                else continue;
            }
            else{
                sum1 += count_sum(nn);
                if(sum1 == count_sum(i))
                    goto A;
                else continue;
            }
        }
A:      printf("%d\n", i);
    }
    return 0;
}
