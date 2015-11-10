#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int func(int x, int k){
    int sum = 0;
    while(x){
        sum += x % k;
        x /= k;
    }
    return sum;
}

int main(){
    for(int i = 1000; i < 10000; i++)
    if(func(i, 10) == func(i, 16) && func(i, 10) == func(i, 14))
    printf("%d\n", i);
    return 0;
}
