#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#define N 1998099999
using namespace std;


int n;
long long a[6000];
char ch[6][3] = {" ", "st", "nd", "rd", "th"};
bool b[N];

void makeu(){
    n = 1;
    int j;
    long long i;
    fill(b, b + N, false);
    for(i = 1; i <= 7; i++){
        a[i] = i;
        b[i] = true;
    }
    for(i = 1; i < N; i++)
        if(b[i]){
            a[n++] = i;
            for(j = 2; j <= max(n, 7) && i * a[j] < N; j++)
            b[i * a[j]] = true;
        }
}

int main(){
    int m, i;
    makeu();
    a[5842] = 2000000000;
	while(scanf("%d", &m) && m){
        if((m >= 4 && m <= 20) || m % 10 == 0)
        i = 4;
        else
        i = m % 10;
        printf("The %d%s humble number is %lld.\n", m, ch[i], a[m]);
    }
    return 0;
}
