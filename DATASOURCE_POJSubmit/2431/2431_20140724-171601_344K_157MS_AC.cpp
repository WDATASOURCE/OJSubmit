#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdio>
#define M 10010

using namespace std;

struct station{
    int d;
    int f;
};

int cmp(const void *a, const void *b){
    station aa = *(station *)a;
    station bb = *(station *)b;
    return aa.d - bb.d;
}

priority_queue<int> pq;
station s[M];

int main(){
    int n, i, p, l;
    while(scanf("%d", &n) != EOF){
        for(i = n - 1; i >= 0; i--)
            cin >> s[i].d >> s[i].f;
        cin >> l >> p;
        for(i = 0; i < n; i++)
            s[i].d = l - s[i].d;
        s[n].d = l, s[n].f = 0;
        n++;
        qsort(s, n, sizeof(s[0]), cmp);
        int ans = 0, pos = 0, tank = p;
        for(i = 0; i < n; i++){
            int a = s[i].d - pos;
            while(tank - a < 0){
                if(pq.empty()){
                    cout << -1 << endl; 
                    return 0;
                }
                tank += pq.top();
                pq.pop();
                ans++;
            }
            tank -= a;
            pos = s[i].d;
            pq.push(s[i].f);
        }
        cout << ans << endl;
    }
    return 0;
}
