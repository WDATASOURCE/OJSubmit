#include <queue>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

struct Point{
    int vis[10];
};

Point dic[1000010];
char ch[1000010][20];
 
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        int dx = 0;
        memset(dic, 0, sizeof(dic));
        for(int k = 1; k <= n; k++){
            int x = 0;
            scanf(" %s", ch[k]);
            int len = strlen(ch[k]);
            for(int i = 0; i < len; i++){
                if(!dic[x].vis[ch[k][i] - '0']) dic[x].vis[ch[k][i] - '0'] = dx++, x = dx;
                else x = dic[x].vis[ch[k][i] - '0'];
            }
        }
        int f = 1;
        for(int k = 1; k <= n; k++){
            int len = strlen(ch[k]);
            int x = 0;
            for(int i = 0; i < len; i++)
                x = dic[x].vis[ch[k][i] - '0'];
            if(x){ f = 0; break;}
        }

        /*
        for(int i = 0; i < dx; i++){
            for(int j = 0; j < 10; j++)
                cerr <<"i = "<< i <<", j = "<< j << ", dic[i].vis[j] = "<< dic[i].vis[j] << endl;
            cerr << endl;
        }
        */


        if(f)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
