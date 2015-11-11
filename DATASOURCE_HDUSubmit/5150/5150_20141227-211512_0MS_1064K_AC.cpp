#include <cstdio>
#include <algorithm>
using namespace std;

int a[1100];
bool is[1100];

void make(){
    fill(is, is + 1100, false);
    is[0] = true;
    int id = 0;
    for(int i = 2; i < 1100; i++){
        if(!is[i]) a[id++] = i;
        for(int j = 0; j < id && i * a[j] < 1100; j++){
            is[a[j] * i] = true;
            if(i % a[j] == 0) break;
        }
    }
}

int main(){
    int n, v;
    make();
    //for(int i = 0; i < 10; i++) printf("%d ", a[i]);
    while(scanf("%d", &n) != EOF){
        int sum = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &v);
            if(!is[v]) sum += v;
        }
        printf("%d\n", sum);
    }
    return 0;
}