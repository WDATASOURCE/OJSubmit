#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

char ch[20];
char bh[20];
int v; 
double ans;

double juli(){
    double t1 = ch[0] * 10 + ch[1] + (ch[3] * 10 + ch[4]) / 60.0 + (ch[6] * 10 + ch[7]) / 3600.0;
    double t2 = bh[0] * 10 + bh[1] + (bh[3] * 10 + bh[4]) / 60.0 + (bh[6] * 10 + bh[7]) / 3600.0;
    return (t1 - t2) * v;
}

int main(){
    ans = 0.0;
    while(gets(ch) != NULL){
        int len = strlen(ch);
        ans += juli();
        if(len < 9){
            printf("%s %.2f km\n", ch, ans);
        } else{
            v = 0;
            for(int i = 9; i < len; i++)
                v = v * 10 + ch[i] - '0';
        }
        strcpy(bh, ch);
    }
}
