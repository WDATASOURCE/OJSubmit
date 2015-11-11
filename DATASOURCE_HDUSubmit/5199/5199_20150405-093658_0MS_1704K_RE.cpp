#include <map>
#include <cstdio>
#include <cstring>
using namespace std;

bool is[1000010];
int n, m;

int main(){
    while(scanf("%d%d", &n, &m) != EOF){
        map <int, int> ma;
        for(int i = 0; i <= n; i++) is[i] = 0;
        int v;
        for(int i = 0; i < n; i++){
            scanf("%d", &v);
            ma[v]++;
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
