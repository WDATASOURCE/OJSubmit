#include<map>
#include <cstdio> 
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
#define eps 1e-8//精度处理
using namespace std;
int n,m;
struct Edge {
	int u,v;
	double w;


	Edge(int uu,int vv,double ww) {
		u = uu;	v = vv;	w = ww;
	}
};

int fa[100000];
vector<Edge> E;

void init() {
	for(int i = 1;i <= n;++i)
		fa[i] = i;
}

int Find(int x) {
	if(x == fa[x])	return x;
	else return fa[x] = Find(fa[x]);
}

bool cmp(Edge a,Edge b) {
	return a.w + eps < b.w;
}
double Kruscal() {
	double ans = 0;
	int u,v;
	double w;
	for(int i = 0;i < E.size();++i) {
		u = Find(E[i].u);
		v = Find(E[i].v);
		w = E[i].w;
		if(u != v) {
			ans += w;
			fa[u] = v;
		}
	}
	return ans;
}
int main()
{
	//freopen("in.txt","r",stdin);
	double _max,w;
	char s1[100],s2[100],name[100];
	string Name;
	string S1,S2;
	map<string,int> M;
	scanf("%lf",&_max);
	scanf("%d",&n);
	init();
	for(int i = 1;i <= n;++i)
	{
		scanf("%s",name);
		Name.assign(name);
		M[Name] = i;
	}
	scanf("%d",&m);
	while(m--)
	{
		scanf("%s%s%lf",s1,s2,&w);
		S1.assign(s1);
		S2.assign(s2);
		E.push_back(Edge(M[S1],M[S2],w));
	}
	sort(E.begin(),E.end(),cmp);
	double ans = Kruscal();
	if(ans + eps < _max)
		printf("Need %.1f miles of cable\n",ans);
	else printf("Not enough cable\n");
	return 0;
}
