#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;
int bag[3410][3410];
int w[3410],v[3410];
int main(void)
{
	int n,m;
	cin >> n >> m;
	for(int i=1; i<=n; i++)
		cin >> w[i] >> v[i];
	memset(bag,0,sizeof(bag));
	for(int i=1; i<=n; i++)	
		for(int k=1; k<=m; k++)
			if( k >= w[i])
			{
				if(	bag[i-1][k-w[i]]+ v[i] > bag[i-1][k] )
					bag[i][k] = bag[i-1][k-w[i]]+ v[i];
				else
					bag[i][k] = bag[i-1][k];
			}
			else
				bag[i][k] = bag[i-1][k];
	cout << bag[n][m] << endl;
return 0;
}
