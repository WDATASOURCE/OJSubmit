#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define eps 1e-8
#define randin srand((unsigned int)time(NULL))
#define input freopen("input.txt","r",stdin)
#define debug(s) cout << "s = " << s << endl;
#define outstars cout << "*************" << endl;
const double PI = acos(-1.0);
const int inf = 0x3f3f3f3f;
const int INF = 0x7fffffff;
typedef long long ll;

const int maxn = 1010;
int n;
int num[maxn];
struct Node {
    int key;
    Node *lson, *rson;
} tree[maxn];

int cur;

void insert(Node *&rt, int val) {
    if (rt == NULL) {
        rt = &tree[cur ++];
        rt->lson = rt->rson = NULL;
        rt->key = val;
        return ;
    }
    if (val < (rt->key)) insert(rt->lson, val);
    else insert(rt->rson, val);
}

void create(Node *&rt) {
    rt = NULL;
    for (int i = 1; i <= n; i ++) insert(rt, num[i]);
}

void search(Node * rt, int val) {
    if (rt->key == val) {
        printf("\n");
        return;
    }
    if (val < (rt->key)) {
        printf("E");
        search(rt->lson, val);
    } else {
        printf("W");
        search(rt->rson, val);
    }
}

int main() {

    //input;
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++) scanf("%d", &num[i]);
        Node * rt;
        cur = 0;
        create(rt);
        int q;
        scanf("%d", &q);
        for (int i = 1; i <= q; i ++) {
            int tmp;
            scanf("%d", &tmp);
            search(rt, tmp);
        }
    }


    return 0;
}