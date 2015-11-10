#include <cstdio>
#include <iostream>
#include <algorithm>
#define MAX 1000
using namespace std;

struct Node{                            // 节点
    int v;
    Node *next;
};
struct AdjList{                         // 邻接表, n 为点数  m 为边的数目
    int n, m;
    Node node[MAX];
};

AdjList alist;
int ans[MAX];                           // 用于存放排序后的结果

bool TOSort(){
    int d[MAX];                         // d[i] 为 i 点的入度
    fill(d, d + MAX, 0);                    
    for(int i = 1; i <= alist.n; i++){  // 初始化数组 d[i] 
        Node *p = alist.node[i].next;
        while(p != NULL){
            d[p -> v]++;
            p = p -> next;
        }
    }
    int top = -1;                       // top 为站定元素的下标
    for(int i = 1; i <= alist.n; i++){  // 初始化栈, 将入度为0的元素放入栈内
        if(d[i] == 0){
            d[i] = top;
            top = i;
        }
    }
    int count = 0;                      // count 记录排好序的元素的个数

    /* 拓扑排序核心代码*/

    while(top != -1){                   // top = -1 为最后一个入度为零的点
        ans[count++] = top;             // 将栈顶元素放在数组中
        Node *p = alist.node[top].next; // 一下重新初始化d[i]数组
        top = d[top];
        while(p != NULL){
            d[p -> v]--;
            if(d[p -> v] == 0){
                d[p -> v] = top;
                top = p -> v;
            }
            p = p -> next;
        }
    }
    if(count < alist.n)                 // 数组中的数字个数小于总个数时, 有环
        return false;
    else
        return true;
}

int main(){
    int i, j;
    Node *p;
    int n;
    while(scanf("%d", &n) != EOF){
        alist.n = alist.m = n;
    for(i = 0; i < MAX; i++)
        alist.node[i].next = NULL;
    for(i = 0; i < alist.m; i++){
        int s, t;
        scanf("%d", &s);
        t = s;
        while(t){
            scanf("%d", &t);
            if(t == 0)
                break;
        p = new Node;
        p -> v = t;
        p -> next = alist.node[s].next;
        alist.node[s].next = p;
        }
    }
    TOSort();
        for(i = 0; i < alist.n; i++)
            printf("%d%c", ans[i], i == n - 1 ? '\n': ' ');
    }
    return 0;
}
