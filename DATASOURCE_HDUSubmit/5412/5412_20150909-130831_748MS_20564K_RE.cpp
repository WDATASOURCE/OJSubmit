#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 110010
#define M 110010
#define INF 1000000000
char ctrl[M][3];
int cnt,n,m;
int P[M],Q[M],a[N],b[N],K[M];
struct treap{
   int key,wei,cnt,size,ch[2];
}T[N * 15];
int tree[N << 1],nodecnt,root;
void init(){
   T[0].size = 0;
   T[0].wei = -INF;
   nodecnt = root = 0;
}
int ID(int l,int r){return l + r | l != r;}
void update(int x){
   T[x].size = T[T[x].ch[0]].size + T[T[x].ch[1]].size + T[x].cnt;
}
void rotate(int &x,int t){
   int y = T[x].ch[t];
   T[x].ch[t] = T[y].ch[!t];
   T[y].ch[!t] = x;
   update(x);
   update(y);
   x = y;
}
void insert(int &x,int t){
   if (!x){
       x = ++ nodecnt;
       T[x].key = t;
       T[x].wei = rand();
       T[x].cnt = 1;
       T[x].ch[0] = T[x].ch[1] = 0;
   }else if (T[x].key == t) T[x].cnt ++;
   else{
       int k = T[x].key < t;
       insert(T[x].ch[k],t);
       if (T[x].wei < T[T[x].ch[k]].wei) rotate(x,k);
   }
   update(x);
}
void erase(int &x,int t){
   if (T[x].key == t){
       if (T[x].cnt == 1){
           if (!T[x].ch[0] && !T[x].ch[1]) {
               x = 0;return;
           }
           rotate(x,T[T[x].ch[0]].wei < T[T[x].ch[1]].wei);
           erase(x,t);
       }else T[x].cnt --;
   }else erase(T[x].ch[T[x].key < t],t);
   update(x);
}
int select(int x,int t){
   if (!x) return 0;
   if (T[x].key > t) return select(T[x].ch[0],t);
   return T[x].cnt + T[T[x].ch[0]].size + select(T[x].ch[1],t);
}
void treeins(int l,int r,int i,int x){
   insert(tree[ID(l,r)],x);
   if (l == r) return;
   int m = l + r >> 1;
   if (i <= m) treeins(l,m,i,x);
   else treeins(m + 1,r,i,x);
}
void treedel(int l,int r,int i,int x){
   erase(tree[ID(l,r)],x);
   if (l == r) return;
   int m = l + r >> 1;
   if (i <= m) treedel(l,m,i,x);
   else treedel(m + 1,r,i,x);
}
int query(int l,int r,int x,int y,int t){
   if (l == r) return l;
   int m = l + r >> 1;
   int ans = select(tree[ID(l,m)],y) - select(tree[ID(l,m)],x);
   if (ans >= t) return query(l,m,x,y,t);
   return query(m + 1,r,x,y,t - ans);
}
int main(){
   while(~scanf("%d",&n)){
       memset(tree,0,sizeof tree);
       init();
       cnt = 0;
       for (int i = 1;i <= n;i ++) scanf("%d",&a[i]),b[++ cnt] = a[i];
       scanf("%d", &m);
       for (int i = 1;i <= m;i ++){
           scanf("%s%d%d",ctrl[i],&P[i],&Q[i]);
           if (ctrl[i][0] == '2') scanf("%d",&K[i]);
           else b[++ cnt] = Q[i];
       }
       sort(b + 1,b + 1 + cnt);
       cnt = unique(b + 1,b + 1 + cnt) - b - 1;
       for (int i = 1;i <= n;i ++) {
           a[i] = lower_bound(b + 1,b + 1 + cnt,a[i]) - b;
           treeins(1,cnt,a[i],i);
       }
       for (int i = 1;i <= m;i ++){
           if (ctrl[i][0] == '2'){
               int id = query(1,cnt,P[i] - 1,Q[i],K[i]);
               printf("%d\n",b[id]);
           }else{
               treedel(1,cnt,a[P[i]],P[i]);
               a[P[i]] = lower_bound(b + 1,b + 1 + cnt,Q[i]) - b;
               treeins(1,cnt,a[P[i]],P[i]);
           }
       }
   }
   return 0;
}
