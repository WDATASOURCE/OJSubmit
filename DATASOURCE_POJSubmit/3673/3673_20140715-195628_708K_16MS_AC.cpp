#include<cstdio>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#define M 11
using namespace std;

char a[M], b[M];

int main(){
    int i, j, sum = 0;
    int lena, lenb;
    cin >> a; 
    cin >> b;
    lena = strlen(a);
    lenb = strlen(b);
    for(i = 0; i < lena; i++)
        for(j = 0; j < lenb; j++)
            sum += (a[i] - '0') * (b[j] - '0');
    cout << sum << endl;
    return 0;
}

