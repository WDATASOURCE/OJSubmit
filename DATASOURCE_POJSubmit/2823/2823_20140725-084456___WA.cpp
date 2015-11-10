#include<iostream>
#include<cstdio>
#include<queue>
#define M 1000010
using namespace std;

struct win{
    int p, d;
};

struct cmp1{
    bool operator()(win x, win y){
        return x.d > y.d;
    }
};
struct cmp2{
    bool operator()(win x, win y){
        return x.d < y.d;
    }
};

priority_queue<win, vector<win>, cmp1> pq1;
priority_queue<win, vector<win>, cmp2> pq2;
win a[M];
int n, k;

int main(){
    int i;
    ios_base::sync_with_stdio(false);
    while(cin >> n >> k){
        if(n == 0){
            cout << 0 << endl << 0 << endl;
            continue;
        }
        for(i = 0; i < n; i++){
            cin >> a[i].d;
            a[i].p = i;
        }
        if(n <= k){
            for(i = 0; i < n; i++)
                pq1.push(a[i]);
            win b = pq1.top();
            printf("%d\n", b.d); 
            while(!pq1.empty())
                pq1.pop();
            for(i = 0; i < n; i++)
                pq2.push(a[i]);
            win c = pq2.top();
            printf("%d\n", c.d);
            continue;
        }
        for(i = 0; i < n; i++){
            if(i > k - 1){
                win b = pq1.top();
                while(b.p <= i - k){
                    pq1.pop();
                    b = pq1.top();
                }
            }
            pq1.push(a[i]);
            if(i < k - 1)
                continue;
            win c = pq1.top();
            printf("%d ", c.d);
        }
        printf("\n");
        while(!pq1.empty())
            pq1.pop();
        for(i = 0; i < n; i++){
            if(i > k - 1){
                win b = pq2.top();
                while(b.p <= i - k){
                    pq2.pop();
                    b = pq2.top();
                }
            } 
            pq2.push(a[i]);
            if(i < k - 1)
                continue;
            win c = pq2.top();
            printf("%d ", c.d);
        }
        printf("\n");
    }
    return 0;
}
