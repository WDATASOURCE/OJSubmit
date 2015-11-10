#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 105;
const int E = 205;
const double MAX = 999999999;

struct Edge{
	int beg;
	int end;
	double r, c;
};

Edge edge[E];
double mindis[N];
int n, m, e, fn;
double fv;

void addedge(int beg, int end, double r, double c) {
	edge[e].beg = beg;
	edge[e].end = end;
	edge[e].r = r;
	edge[e].c = c;
	++e;
}

bool relax(int pe){
	double t = (mindis[edge[pe].beg] - edge[pe].c) * edge[pe].r;
	if(t > mindis[edge[pe].end]){
		mindis[edge[pe].end] = t;
		return true;
	}
	return false;
}

bool bellman_ford(){
	bool flag;
	for(int i = 0; i < n; ++i) mindis[i] = 0.0;
	mindis[fn] = fv;
	for(int i = 0; i < n - 1; ++i) {
		flag = false;
		for(int j = 0; j < e; ++j)
			if(relax(j)) flag = true;
		if(mindis[fn] > fv) return true;
		if(!flag) return false;
	}
	for(int i = 0; i < e; ++i)
		if(relax(i)) return true;
	return false;
}

int main(){
	int beg, end;
	double r1, r2, c1, c2;
	scanf("%d%d%d%lf", &n, &m, &fn, &fv);
	--fn;
	e = 0;
	for(int i = 0; i < m; ++i) {
		scanf("%d%d%lf%lf%lf%lf", &beg, &end, &r1, &c1, &r2, &c2);
		--beg;
		--end;
		addedge(beg, end, r1, c1);
		addedge(end, beg, r2, c2);
	}
	bool ans = bellman_ford();
	if(ans) printf("YES\n");
	else printf("NO\n");
	return 0;
}
