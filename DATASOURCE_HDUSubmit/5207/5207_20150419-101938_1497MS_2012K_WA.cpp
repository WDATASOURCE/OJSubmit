#include <cstdio>
#include <iostream>
#include <algorithm>
#define N 100010
#define M (1 << 29)
using namespace std;

int a[N], n;

int s[N], cnt;
bool is[N];

void sushu(){
    cnt = 0;
    fill(is, is + N, true);
    is[0] = is[1] = false;
    for(int i = 2; i < N; i++){
        if(is[i]) s[cnt++] = i;
        for(int j = 0; j < cnt && s[j] * i < N; j++){
            is[s[j] * i] = false;
            if(i % s[j] == 0) break;
        }
    }
}

int main(){
    //sushu();
//    for(int i = 0; i < 10; i++)
        //printf("%d%c", s[i], i==9? '\n' : ' ');
    int t, v, di = 1;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        fill(a, a + N, 0);
        a[1] = 2;
        while(n--){
            scanf("%d", &v);
            int vv = v;
            for(int i = 2; i * i <= vv; i++){
                if(v % i == 0) a[i]++;
                while(v % i == 0) v /= i;
            }
            if(v != 1) a[v]++;
        }
        int ans = 0;
        for(int i = 100000; i >= 0; i--)
            if(a[i] >= 2) {ans = i; break;}
        printf("Case #%d: %d\n", di++, ans);
    }
    return 0;
}
