#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
#define M 30
using namespace std;

vector <int> vec[M];                            // 邻接表;
int ingree[M];                                  // 存储节点的入度;
int ans[M];                                     // 存储排序后的数字;
bool is[M];
int n, m, nn;                                       // 点数;

int TOSort(){                                  // 排序成功返回 true  否则返回 false;
    int i, j;
    stack <int> sta;
    int count = 0;
    fill(ingree, ingree + M, 0);
    for(i = 1; i <= n; i++){                    // 初始化入度数组, 统计所有点的入度;
        int end = vec[i].size();
        for(j = 0; j < end; j++)
            ingree[vec[i][j]]++;
    }
    for(i = 1; i <= n; i++)                     // 初始化栈;
        if(ingree[i] == 0)
            sta.push(i);
    while(!sta.empty()){                           // -1  为栈底;
        int t = sta.top();
        sta.pop();
        ans[count++] = t;
        int end = vec[t].size();
        for(i = 0; i < end; i++){               // 删除入度为零的点的边;
            ingree[vec[t][i]]--;
            if(ingree[vec[t][i]] == 0){
                sta.push(vec[t][i]);
            }
        }
    }
    return count;
}
 
int main(){
    int ff;
    while(scanf("%d%d", &n, &m) != EOF){
        if(n == 0 && m == 0)
            break;
        char a, b, c;
        nn = 0;
        int f = 0;
        int fx = 0;
        int fac = 0;
        int facx = 0;
        fill(is, is + M, false);
        for(int  i = 0; i < m; i++){
            getchar();
            scanf("%c<%c", &a, &b);
            int aa = a - 'A' + 1;
            int bb = b - 'A' + 1;
            if(!is[aa]){
                nn++;
                is[aa] = true;
            }
            if(!is[bb]){
                nn++;
                is[bb] = true;
            }
            vec[aa].push_back(bb);
            ff = TOSort();
            if(ff == nn && nn == n && !fac){
                fac = 1;
                facx = i + 1;
            }
            else if(ff < nn && !f){
                f = 1;
                fx = i + 1;
            }
        }
        if(f)
            printf("Inconsistency found after %d relations.\n", fx);
        else if(ff < n)
            printf("Sorted sequence cannot be determined.\n");
        else{
            printf("Sorted sequence determined after %d relations: ", facx);
            for(int i = 0; i < n; i++)
                printf("%c", ans[i] - 1 + 'A');
            printf(".\n");
        }
    }
    return 0;
}
