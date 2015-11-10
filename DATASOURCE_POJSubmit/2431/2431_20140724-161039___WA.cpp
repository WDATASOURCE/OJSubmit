#include<iostream>
#include<queue>
#include<cstdio>
#define M 10010

using namespace std;

int d[M], f[M];

priority_queue<int> pq;

int main(){
    int n, i, p, l;
    while(scanf("%d", &n) != EOF){
        for(i = n - 1; i >= 0; i--)
            cin >> d[i] >> f[i];
        cin >> l >> p;
        for(i = 0; i < n; i++)
            d[i] = l - d[i];
        d[n] = l, f[n] = 0;
        int ans = 0, pos = 0, tank = p;
        for(i = 0; i < n; i++){
            int a = d[i] - pos;
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
            pos = d[i];
            pq.push(f[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
