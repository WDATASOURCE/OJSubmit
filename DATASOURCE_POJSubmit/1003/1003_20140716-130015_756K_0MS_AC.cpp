#include<iostream>
using namespace std;

double func(double a)
{
	double i=1;
	double b=1.0/2.0;	
	while(a>b)
	{
		b=b+1/(i+2);
		i++;
	}
	return i;
}
int main()
{
	double a;
	double i;
	while(cin>>a&&a!=0.00)
	{
		i=func(a);
		cout<<i<<" "<<"card(s)"<<endl;
	}
	return 0;

}