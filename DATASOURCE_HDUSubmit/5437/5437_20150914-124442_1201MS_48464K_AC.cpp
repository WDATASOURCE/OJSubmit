#include <cstdio>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
using namespace std;
int k,m,q;
char s[300];
const int size = 2e5;
string a;
map<int, string> mp;
struct node {
    int v;
    int name;
    int ind;
    node(){}
    node(int a,int b,int c):v(a),name(b),ind(c){}
    bool operator < (const node&b) const 
    {
        if(v !=b.v) return v < b. v;
        return ind > b.ind; 
    }
};

struct letin {
    int t;
    int p;
    letin(){}
    letin(int a,int b):t(a),p(b){}
    bool operator < (const letin&b)const {
        return t < b.t;
    }
};

priority_queue<node> pq;
node afx[size];
letin op[size];
node ans[size];
int comin;
int ask[200];

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        comin = 1;
        mp.clear();
        int ms = 0;
        scanf("%d%d%d",&k,&m,&q);
        for(int i = 1 ; i <= k ;i++)
        {
            int v;
            scanf("%s%d",s,&v);
            a.assign(s);
            mp[ms] = a;
            afx[i] = node(v,ms,i+1);
            ms++;
        }
        for(int i = 0; i < m;i++)
            scanf("%d%d",&op[i].t,&op[i].p);
        sort(op, op+m);
        int mx = 0;
        for(int i = 0; i < q;i++)
        {
            scanf("%d",ask+i);
            if(ask[i] > mx)
                mx = ask[i];
        }
        int lb = 0;
        int i;
        for(i = 1; i <= k && comin <= mx ; i++)
        {
            pq.push(afx[i]);
            if(i < op[lb].t || lb >= m) continue;
            int my = op[lb].p;
            while(my && !pq.empty()){
                ans[comin++] = pq.top();
                pq.pop();
                my --;
            }
            lb++;
        }
        if(i <= k) while(!pq.empty()) pq.pop();
        else {
            while(!pq.empty() && comin <= mx)
            {
                ans[comin++] = pq.top();    
                pq.pop();
            }
            while(!pq.empty()) pq.pop();
        }
        for(int i = 0; i < q; i++) {
            printf("%s",mp[ans[ask[i]].name].c_str());
            if(i < q - 1) printf(" ");
            else printf("\n");
        }
    }
    return 0;
}
