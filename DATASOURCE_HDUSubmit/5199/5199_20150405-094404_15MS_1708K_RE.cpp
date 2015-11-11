#include <map>
#include <cstdio>
#include <cstring>
using namespace std;

bool is[1000010];
map <int, int> ma;
int n, m;

int main(){
    while(scanf("%d%d", &n, &m) != EOF){
        map <int, int>:: iterator iter;
        for(iter = ma.begin(); iter != ma.end(); iter++)
            iter -> second = 0;
        for(int i = 0; i <= n; i++) is[i] = 0;
        int v;
        for(int i = 0; i < n; i++){
            scanf("%d", &v);
            if(ma.find(v) != ma.end()) ma[v]++;
            else ma[v] = 1;
            is[v] = 1;
        }
        for(int i = 0; i < m; i++){
            scanf("%d", &v);
            if(!is[v]) printf("%d\n", 0);
            else{
                printf("%d\n", ma[v]);
                is[v] = 0;
            }
        }
    }
    return 0;
}
