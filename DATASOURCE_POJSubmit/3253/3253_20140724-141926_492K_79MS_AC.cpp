#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

struct cmp{
    bool operator ()(int x, int y){
        return x > y;
    }
};

priority_queue<long long, vector<long long>, cmp> pq;

int main(){
    ios_base::sync_with_stdio(false);
    long long v;
    int n, i, j;
    while(cin >> n){
        long long sum = 0;
        for(i = 0; i < n; i++){
            cin >> v;
            pq.push(v);
        }
        while(pq.size() > 1){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            sum += a + b;
            pq.push(a + b);
        }
        cout << sum << endl;
        pq.pop();
    }
    return 0;
}
            

    
