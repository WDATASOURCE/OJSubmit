#include <cstdio>
#include <iostream>
#define N 15
using namespace std;

char ch[N][N];
int a[N][N];
bool r[10][10];
bool c[10][10];
bool g[10][10];
int sum;
bool f;

void dfs(int x, int y, int di){
    if(f) return;
    if(di == sum + 1){
        for(int k = 0; k < 9; k++){
            for(int j = 0; j < 9; j++)
                printf("%d", a[k][j]);
            printf("\n");
        }
        return;
    }
    //cerr <<"x = "<< x <<" y = "<< y << endl;
    for(int i = x; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(!a[i][j]){
                //cerr <<"i = "<< i <<" j = "<< j << endl;
                for(int k = 1; k < 10; k++){
                    if(f) return;
                    if(r[i][k] && c[j][k] && g[(i / 3) * 3 + j / 3][k]){ 
                        //cerr <<"i = "<< i <<" j = "<< j <<" k = "<< k << endl;
                        r[i][k] = c[j][k] = g[(i / 3) * 3 + j / 3][k] = false;
                        a[i][j] = k;
                        dfs(i, j, di + 1);
                        r[i][k] = c[j][k] = g[(i / 3) * 3 + j / 3][k] = true;
                    }
                }
                a[i][j] = 0; 
                return;
            }
        }
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        for(int i = 0; i < 9; i++)
            scanf(" %s", ch[i]);
        sum = 0;
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++){
                a[i][j] = ch[i][j] - '0';
                if(!a[i][j]) sum++;
            }
        //cout <<"sum = "<< sum << endl;
        fill(r[0], r[10], true);
        fill(c[0], c[10], true);
        fill(g[0], g[10], true);
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++){
                r[i][a[i][j]] = false;
                c[j][a[i][j]] = false;
                g[(i / 3) * 3 + j / 3][a[i][j]] = false;
            }
        f = false;
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
                if(!a[i][j]){ 
                    dfs(i, j, 1);
                    goto A;
                }
A: ;
    }
    return 0;
}
