#include<cstdio>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#define M 800
using namespace std;

struct ss{
    int x, y;
};

ss s[M];
int n;

void solute(){
    int i, j, k, su = 2, sum = 0;
    double kl;
    for(i = 0; i < n - 2; i++){
        for(j = i + 1; j < n - 1; j++){
            su = 2;
            if(s[i].x == s[j].x){
                for(k = j + 1; k < n; k++)
                    if(s[k].x == s[i].x)
                        su++;
            }
            else{
                kl = ((double)(s[j].y - s[i].y)) / (s[j].x - s[i].x);
                for(k = j + 1; k < n; k++){
                    if(s[k].y - (kl * s[k].x + s[i].y - kl * s[i].x) < 1e-5)
                        su++;
                }
            }
            sum = (sum > su ? sum : su);
        }
    }
    cout << sum << endl;
    return;
}

int main(){
    int i, j;
    while(1){
        cin >> n;
        if(n == 0)
            break;
        else
            for(i = 0; i < n; i++)
                cin >> s[i].x >> s[i].y;
        if(n == 1)
            cout << 1 << endl;
        else if(n == 2)
            cout << 2 << endl;
        else
            solute();
    }
    return 0;
}
