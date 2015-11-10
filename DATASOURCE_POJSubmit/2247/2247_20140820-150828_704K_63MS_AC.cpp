#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int a[6000];
char ch[6][3] = {" ", "st", "nd", "rd", "th"};

int main(){
    int m, i;
    int n1 = 1, n2 = 1, n3 = 1, n4 = 1;
    a[1] = 1;
    for(i = 2; i <= 5900; i++){
        a[i] = min(min(a[n1] * 2, a[n2] * 3), min(a[n3] * 5, a[n4] * 7));
        if(a[i] == a[n1] * 2) n1++;
        if(a[i] == a[n2] * 3) n2++;
        if(a[i] == a[n3] * 5) n3++;
        if(a[i] == a[n4] * 7) n4++;
    }
	while(scanf("%d", &m) && m){
        if(m % 100 != 11 && m % 10 == 1)
        i = 1;
        else if(m % 100 != 12 && m % 10 == 2)
        i = 2; 
        else if(m % 100 != 13 && m % 10 == 3)
        i = 3;
        else
        i = 4;
        printf("The %d%s humble number is %d.\n", m, ch[i], a[m]);
    }
    return 0;
}
