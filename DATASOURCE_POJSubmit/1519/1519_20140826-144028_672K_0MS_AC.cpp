#include <cmath>
#include <cstdio>
#include <queue>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

char ch[2001];


int main(){
    int i, j, n;
    while(scanf("%s", ch) != EOF && ch[0] != '0'){
        int sum = 0;
        for(i = 0; ch[i]; i++)
        sum += ch[i] - '0';
        while(1){
            n = sum;
            sum = 0;
            while(n){
                sum += n % 10;
                n /= 10;
            }
            if(sum < 10)
            break;
        }
        printf("%d\n", sum);
    }
    return 0;
}
