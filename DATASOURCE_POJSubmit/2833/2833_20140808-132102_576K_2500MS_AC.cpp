#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

struct cmp{
    bool operator()(int x, int y){
        return x > y;
    }
};

priority_queue<int, vector<int>, cmp>low;
priority_queue<int>hig;
long long sum;

int main(){
    int l, r, n, v;
    while(scanf("%d%d%d", &r, &l, &n) != EOF){
        if(r == 0 && l == 0 && n == 0)
            break;
        sum  = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &v);
            sum += v;
            if(low.size() < r)
                low.push(v);
            else if(low.top() < v){
                low.pop();
                low.push(v);
            }
            if(hig.size() < l)
                hig.push(v);
            else if(hig.top() > v){
                hig.pop();
                hig.push(v);
            }
        }
        while(!low.empty()){
            sum -= low.top();
            low.pop();
        }
        while(!hig.empty()){
            sum -= hig.top();
            hig.pop();
        }
        double ans = sum;
        ans = ans / (double)(n - r - l);
        printf("%.6f\n", ans);
    }
    return 0;
}
