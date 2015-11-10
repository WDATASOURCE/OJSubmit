#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int a, d, n;

bool isprime(int x){
    int i, f = 0;
    if(x < 2)
        return false;
    else if(x == 2 || x == 3 || x == 5)
        return true;
    else {
        for(i = 2; i * i <= x; i++)
            if(x % i == 0){
                f = 1;
                break;
            }
        if(f == 0)
            return true;
        else
            return false;
    }
}

int main(){
    while(scanf("%d%d%d", &a, &d, &n) != EOF){
        if(a == 0 && d == 0 && n == 0)
            break;
        int di = 0;
        while(1){
            if(isprime(a))
                di++;
            if(di == n)
                break;
            a += d;
        }
        printf("%d\n", a);
    }
    return 0;
}
