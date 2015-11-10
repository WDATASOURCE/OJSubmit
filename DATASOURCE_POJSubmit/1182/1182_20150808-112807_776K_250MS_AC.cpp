#include<cstdio>
#define N 50005
using namespace std;

int par[N], rela[N];                                                                //  rela[a] == 0  表示  a 与 par[a] 同类
int n, k, a, b;                                                                     //  rela[a] == 1  表示  a 吃 par[a] 
                                                                                    //  rela[a] == 2  表示  a 被 par[a] 吃
void init(){                                                                //  *******************************************************************
    int i;                                                                          //  若 rela[a] == 0，rela[par[a]] == 0 -> rela[a] == 0;
    for(i = 1; i <= n; i++){                                                        //  若 rela[a] == 0, rela[par[a]] == 1 -> rela[a] == 1;
        par[i] = i;                                                                 //  若 rela[a] == 0, rela[par[a]] == 2 -> rela[a] == 2;
        rela[i] = 0;                                                                //  若 rela[a] == 1, rela[par[a]] == 0 -> rela[a] == 1;
    }                                                                               //  若 rela[a] == 1, rela[par[a]] == 2 -> rela[a] == 0;
}                                                                                   //  若 rela[a] == 2, rela[par[a]] == 0 -> rela[a] == 2;
                                                                                    //  若 rela[a] == 2, rela[par[a]] == 1 -> rela[a] == 0;
int find(int x){                                                                    //  若 rela[a] == 2, rela[par[a]] == 2 -> rela[a] == 1;
    int y;
    if(par[x] == x)                                                                 //  综合所有情况，可以得出结论  rela[a] = (rela[a] + rela[par[a]]) % 3;
        return x;
    y = par[x];                                                             //  ******************************************************************************
    par[x] = find(y);
    rela[x] = (rela[x] + rela[y]) % 3;
    return par[x];                                                                  //  若 d == 1, 若 rela[a] == 0, rela[b] == 0 时，rela[a] == 0;
}                                                                                   //     (同类)                   rela[b] == 1 时，rela[a] == 1;
                                                                                    //                              rela[b] == 2 时，rela[a] == 2;
void unit(int x, int y, int d){   //  此处的 d 传入的实参为 d - 1;                  //             若 rela[b] == 0, rela[a] == 0 时，rela[a] == 0;
    int fx = find(x);                                                               //                              rela[a] == 1 时，rela[a] == 1;
    int fy = find(y);                                                               //                              rela[a] == 2 时，rela[a] == 2;
    if(fx == fy)                                                                    //  若 d == 2, 若 rela[a] == 0, rela[b] == 0 时，rela[a] == 1;
        return;                                                                     //    (a 吃 b)                  rela[b] == 1 时，rela[a] == 2;
    else{                                                                           //                              rela[b] == 2 时，rela[a] == 0;
        par[fx] = fy;                                                               //             若 rela[b] == 0, rela[a] == 0 时，rela[a] == 1;
        rela[fx] = (rela[y] - rela[x] + d + 3) % 3;                                 // (注意，此时的a是原a的根节点) rela[a] == 1 时，rela[a] == 0;
    }                                                                               //                              rela[a] == 2 时，rela[a] == 2;
    return;                                                                         //  综合所有情况，可以得出结论  rela[a] = (rela[b] - rela[a] + d - 1 + 3) % 3;
}
                                                                            //  ***********************************************************************************
int main(){
    int i, sum = 0, d, fx, fy;
    scanf("%d %d",&n,&k);  
    init();
    for(i = 1; i <= k; i++){
       scanf("%d %d %d",&d,&a,&b); 
        if(a > n || b > n ||(d == 2 && a == b))
            sum++;                                                                  //  真话的条件：  当d == 1(a 与 b 同类)
        else{                                                                       //  a 与 par[a] 同类，即 rela[a] == 0 时，rela[b] == 0;
            fx = find(a);                                                           //  a 吃 par[a]，     即 rela[a] == 1 时，rela[b] == 1;
            fy = find(b);                                                           //  a 被 par[a]吃，   即 rela[a] == 2 时，rela[b] == 2;
            if(fx == fy && ((rela[a] - rela[b] + 3) % 3 != d - 1))                  //  当 d == 2(a 吃 b) 
                 sum++;                                                             //  a 与 par[a] 同类，即 rela[a] == 0 时，rela[b] == 2;
            else unit(a, b, d - 1);                                                 //  a 吃 par[a],      即 rela[a] == 1 时，rela[b] == 0;
        }                                                                           //  a 被 par[a]吃，   即 rela[a] == 2 时，rela[b] == 1;
    }
    printf("%d\n",sum);
    return 0;
}
