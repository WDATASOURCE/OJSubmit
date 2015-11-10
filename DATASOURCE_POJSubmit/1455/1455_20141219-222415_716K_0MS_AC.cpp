#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int main(){
    int n, t, i;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        if(n == 1)
            printf("%d\n", 0);
        else if(n == 2)
            printf("%d\n", 0);
        else if(n == 3)
            printf("%d\n", 1);
        else if(n % 2 == 0){
            n = n / 2;
            int a = n * (n - 1);
            printf("%d\n", a);
        }
        else{
            n = (n - 1) / 2;
            int b = n * (n - 1) + n;
            printf("%d\n", b);
        }
    }
    return 0;
}
