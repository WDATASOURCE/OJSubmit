#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int i;
	double a[12];
	double sum=0,ave;
	for(i=0;i<12;i++)
		cin>>a[i];
	for(i=0;i<12;i++)
		sum+=a[i];
	ave=sum/12;
	cout<<setiosflags(ios::fixed)<<setprecision(2)<<"$"<<ave<<endl;
	return 0;
}

