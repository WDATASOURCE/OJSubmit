#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 30
using namespace std;

double mp[N][N];
double v[N];
int n;

void floyd(){
    for(int k = 0; k <= 26; k++)
        for(int i = 0; i <= 26; i++)
            for(int j = 0; j <= 26; j++)
                if(mp[i][j] < mp[i][k] * mp[k][j] * 0.95)
                    mp[i][j] = mp[i][k] * mp[k][j];
}

int main(){
    while(scanf("%d", &n) != EOF){
        char c;
        char ch[N];
        double t;
        fill(mp[0], mp[N], 0.0);
        for(int i = 0; i < n; i++){
            scanf(" %c %lf %s", &c, &t, ch);
            //cerr <<"c = "<< c <<" t = "<< t << " ch = "<< ch << endl;
            int len = strlen(ch);
            v[c - 'A' + 1] = t;
            for(int j = 0; j < len; j++){
                if(ch[j] == '*') mp[0][c - 'A' + 1] = mp[c - 'A' + 1][0] = 1.0;
                else mp[ch[j] - 'A' + 1][c - 'A' + 1] = mp[c - 'A' + 1][ch[j] - 'A' + 1] = 1.0;
            }
        }
        floyd();
        double ans = 0.0;
        int ansp = 0;
        for(int i = 1; i < 27; i++){
            if(v[i] * mp[0][i] > ans){
                ans = mp[0][i] * v[i];
                ansp = i;
            }
        }
        printf("Import from %c\n", 'A' + ansp - 1);
    }
    return 0;
}
