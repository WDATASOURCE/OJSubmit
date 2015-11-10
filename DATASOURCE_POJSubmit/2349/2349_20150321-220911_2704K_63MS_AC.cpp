#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
#define Max 501
double map[Max][Max],d[Max];
int n,i,j;
struct{
    int x,y;
}point[Max];
//记录从顶点集U到V-U的代价最小的边的辅助数组定义
struct{
    int adjvex;
    double lowcost;
}closedge[Max];
bool cmp(double a,double b)//从大到小偏序
{
    return a>b;
}
//用普里姆算法从第k个顶点出发构造网G的最小生产树T
void prim(int k)
{
    for(j=1;j<=n;j++)//辅助数组初始化
        if(j!=k)
        {
            closedge[j].adjvex=k;
            closedge[j].lowcost=map[k][j];
        }
    closedge[k].lowcost=0; //初始，U={u}
    int l=0;
    for(i=1;i<n;i++)//选择其余n-1个顶点
    {
        double min=1000000;
        for(j=1;j<=n;j++)//求出T的下一个结点：第k顶点
            if(closedge[j].lowcost!=0&&min>closedge[j].lowcost)
            {
                k=j;
                min=closedge[j].lowcost;
            }
        closedge[k].lowcost=0; //第k顶点并入U集
        d[l++]=map[k][closedge[k].adjvex]; //保存该边
        for(j=1;j<=n;j++) //新顶点并入U后重新选择最小边
            if(map[k][j]<closedge[j].lowcost)
            {
                closedge[j].adjvex=k;
                closedge[j].lowcost=map[k][j];
            }
    }
}
int main()
{
    int t,m;
    cin>>t;
    while(t--)
    {
        cin>>m>>n;
        for(i=1;i<=n;i++)
            cin>>point[i].x>>point[i].y;
        for(i=1;i<=n;i++) //求出毎两个顶点之间的距离
            for(j=1;j<i;j++)
                map[i][j]=map[j][i]=sqrt((point[i].x-point[j].x)*(point[i].x
                -point[j].x)+(point[i].y-point[j].y)*(point[i].y-point[j].y));
        for(i=1;i<=n;i++)
            map[i][i]=1000000;
        prim(1);
        sort(d,d+n-1,cmp); //把构成最小生成树的n-1条边从大到小排序
        cout.setf(ios::fixed);//保留两位小数
        cout.precision(2);
        cout<<d[m-1]<<endl;//数组d从下标0开始存储，即第m条边
    }
    return 0;
}
