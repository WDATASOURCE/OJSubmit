#include<iostream>
#include<cstdio>
#include<algorithm>
#include<iomanip>
#define N 105
#define M 0x3f3f3f3f

using namespace std;

int m, n;                                       // m 为等级差, n 为物品数目;
int mp[N][N];                                   // 物品 i 在第 t 号物品的替代下的优惠价为 mp[t][i],当 t == 0 时,说明 i 无替代品,即为原价;
int lv[N];                                      // 第 i 号物品的主人的等级;                    
int x[N];                                       // 第 i 号物品的替代品总数 x[i];
int low[N];                                     // 源点到其余各点的距离;
int vis[N];                                     // 记录 i 点是否已被访问;

int Dijkstra(){                                 // Dijkstra 算法,求最短路;
    int i, j, mi, mip;
    for(i = 1; i <= n; i++)
       low[i] = mp[0][i];
    while(1){
        mi = M, mip = 0;
        for(i = 1; i <= n; i++)
            if(!vis[i] && mi > low[i]){         
                mi = low[i];
                mip = i;
            }
        if(mip == 0)
            break;
        vis[mip] = 1;
        for(i = 1; i <= n; i++)
            if(!vis[i] && mp[mip][i] > 0 && low[i] > low[mip] + mp[mip][i])
                low[i] = low[mip] + mp[mip][i];
    }
    return low[1];
}


int main(){
    int i, j, miprice, mlv, t;                     // miprice 用来存储每一步 dijkstra 得到的最小值的最小值  mlv 来存储最大的等级;
    while(scanf("%d%d", &m, &n) == 2){          // 输入等级差距 m 和物品的个数 n;
        miprice = M;                            // 初始化 miprice 为最大值;
        fill(mp[0], mp[n + 1], 0);               // 初始化 mp 使其全为零;
        fill(lv, lv + n + 1, 0);                // 将等级全部初始化为零;
        fill(vis, vis + n + 1, 0);              // 全部点都未访问到;
        for(i = 1; i <= n; i++){
            scanf("%d%d%d", &mp[0][i], &lv[i], &x[i]);  //输入第 i 个物品的原价 主人的地位和其替代品的个数;
            for(j = 1; j <= x[i]; j++){
                int t, v;
                scanf("%d%d", &t, &v);          // 输入替代品编号和优惠价;
                mp[t][i] = v;                   // 第 i 个物品在有编号为 t 的替代品时的优惠价;
            }
        }
      /*  for(i = 0; i <= n; i++){
            for(j = 0; j <= n; j++)
                cout <<setw(5)<< mp[i][j] << " ";
            cout << endl;
        }
        */
        for(i = 1; i <= n; i++){                // 在等级限制下寻找允许被当前点访问的点;
            mlv = lv[i];                        // 当前物品的主人的等级设为初值;
            for(j = 1; j <= n; j++){
                if(lv[j] > mlv || mlv - lv[j] > m)  // 当其他物品主人的等级比当前物品高,或者两者差别大于等级差时;
                    vis[j] = 1;                 // 强制将这一点置为以访问,不参与算法的处理;
                else
                    vis[j] = 0;
            }
            t = Dijkstra();
            if(miprice > t)
                miprice = t;
        }
        printf("%d", miprice);
    }
    return 0;
}


