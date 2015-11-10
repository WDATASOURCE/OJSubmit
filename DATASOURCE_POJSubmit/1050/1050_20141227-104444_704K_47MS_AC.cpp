#include<iostream>
using namespace std;

int large(int *a,int n){
	int i,ans,sum=0;
	ans=a[0];
	for(i=0;i<n;i++) {
		sum+=a[i];
		ans=ans>sum?ans:sum;
		if(sum<0)
			sum=0;
	}
	return ans;
}

int main() {
	int a[100][100];
	int n,i,j,ans=0,f=1,k,l,b;
	int s[100]={0};
    ios_base::sync_with_stdio(false);
	cin>>n;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin>>a[i][j];
	for(f=0;f<n;f++) {
		for(i=0;i<n-f;i++) {
			for(k=i;k<i+f+1;k++) {
				for(j=0;j<n;j++)
					s[j]=s[j]+a[k][j];
			}
			b=large(s,n);
			ans=ans>b?ans:b;
			for(l=0;l<n;l++) s[l]=0;
		}
	}
	cout<<ans<<endl;
	return 0;
}
