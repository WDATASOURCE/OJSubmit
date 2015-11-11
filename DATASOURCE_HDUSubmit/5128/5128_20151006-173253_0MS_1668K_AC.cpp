#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxsize = 100;
const double eps = 1e-8;

int vis[250][250];

struct point {
    int x, y;
};

struct rect{
    point p1, p2;
    int area()
    {
        return (p2.x-p1.x)*(p1.y-p2.y);
    }
    void print()
    {
        printf ( "p1:(%d, %d), p2:(%d, %d)\n", p1.x, p1.y, p2.x, p2.y );
    }
};

point ps[maxsize];
rect regs[3000000];

int fuck(point p, rect reg)
{
//    printf ( "fuck, p:(%d, %d), reg:", p.x, p.y );
//    reg.print();
    int l, r, b, t;
    t = reg.p1.y;
    b = reg.p2.y;
    l = reg.p1.x;
    r = reg.p2.x;
//    printf ( "l: %d, r: %d, t: %d, b: %d\n", l, r, t, b );
    if(p.x<=r && l<=p.x && b<=p.y && p.y<=t)
    {
//        printf ( "return 1\n" );
        return 1;
    }
    else
        return 0;
}

int cross(rect a, rect b)
{
    point p1, p2, p3, p4;
    p1 = a.p1;
    p3 = a.p2;
    p2.x = p1.x; p2.y = p3.y;
    p4.x = p3.x; p4.y = p1.y;
    return fuck(p1, b)||fuck(p2, b)||fuck(p3, b)||fuck(p4, b);
}

bool point_in_rec(point aa, rect bb) {
    int l, r, b, t;
    l = bb.p1.x;
    r = bb.p2.x;
    t = bb.p1.y;
    b = bb.p2.y;
    if (aa.x > l && aa.y < t && aa.x < r && aa.y > b) return true;
    return false;
}

bool inside(rect aa, rect bb) {
    int l, r, b, t;
    l = bb.p1.x;
    r = bb.p2.x;
    t = bb.p1.y;
    b = bb.p2.y;
    if (point_in_rec(aa.p1, bb) && point_in_rec(aa.p2, bb)) return true;
    return false;
}

int main()
{
    int n;
    while(scanf("%d", &n), n!=0)
    {
        memset(vis, 0, sizeof(vis));
        for(int i=0; i<n; i++)
        {
            scanf ( "%d%d", &ps[i].x, &ps[i].y );
            vis[ps[i].x][ps[i].y] = 1;
        }
        int rcnt = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(ps[i].x<ps[j].x && ps[i].y>ps[j].y)
                {
                    if(vis[ps[i].x][ps[j].y] && vis[ps[j].x][ps[i].y])
                    {
                        rect tmp;
                        tmp.p1 = ps[i]; tmp.p2 = ps[j];
                        regs[rcnt++] = tmp;
//                        tmp.print();
                    }
                }
            }
        }
//        printf ( "----\n" );
        int ans = -1;
        for(int i=0; i<rcnt; i++)
        {
            for(int j=i+1; j<rcnt; j++)
            {
                if (inside(regs[i], regs[j])) ans = regs[j].area();
                else if (inside(regs[j], regs[i])) ans = regs[i].area();
                else {
                    bool flag1 = cross(regs[i], regs[j]);
                    bool flag2 = cross(regs[j], regs[i]);
                    if (!flag1 && !flag2) {
                        //regs[i].print();
                        //regs[j].print();
                        ans = max(ans, regs[i].area() + regs[j].area());
                        //printf("ans = %d\n", ans);
                    }
                }
               /* } else if ((!flag1 && flag2) || (!flag2 && flag1)) {*/
                    //printf("**********\n");
                    //regs[i].print();
                    //regs[j].print();
                    //ans = max(ans, max(regs[i].area(), regs[j].area()));
                    //printf("ans = %d\n", ans);
                /*}*/
            }
        }
        if(ans != -1)
            printf ( "%d\n", ans );
        else
            printf ( "imp\n" );
    }
    return 0;
}