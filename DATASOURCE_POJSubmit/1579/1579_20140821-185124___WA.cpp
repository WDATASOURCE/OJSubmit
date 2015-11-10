#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#define LL int
using namespace std;

int aa[21][21][21];

LL w(LL a, LL b, LL c){
    if(aa[a][b][c] > 0)
        return aa[a][b][c];
    else if(a == 0 || b == 0 || c == 0)
        return 1;
    else if(a < b && b < c)
        return w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    else
        return w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

void makebiao(){
    int i, j, k;
    for(i = 0; i < 21; i++)
        for(j = 0; j < 21; j++)
            for(k = 0; k < 21; k++)
                aa[i][j][k] = w(i, j, k);
}

int main(){
    LL a, b, c, aaa, bb, cc;
    makebiao();
    while(scanf("%d%d%d", &a, &b, &c) != EOF){
        if(a == -1 && b == -1 && c == -1)
            break;
        else if(a > 20 || b > 20 || c > 20)
            aaa = bb = cc = 20;
        else if(a < 0 || b < 0 || c < 0)
            aaa = bb = cc = 0;
        else{
            aaa = a;
            bb = b;
            cc = c;
        }
        printf("w(%d, %d, %d) = %d\n", a, b, c, aa[aaa][bb][cc]);
    }
    return 0;
}
