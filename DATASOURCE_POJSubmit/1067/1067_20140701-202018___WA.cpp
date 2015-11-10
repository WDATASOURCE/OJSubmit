#include<iostream>
#include<math.h>
using namespace std;

int game(float a,float b)
{
	float t,aj;
	if(a>b)
	{
		t=a;
		a=b;
		b=t;
	}
	int j;
	j=int(a*((sqrt(5.0)-1)/2));
	aj=int(j*(sqrt(5.0)+1)/2);
	cout<<a<<" "<<aj<<endl;
	if(a==aj&&b==a+j)
			return 0;
	else if(a==aj+1&&b==a+j+1)
			return 0;
	else
		return 1;
}

int main()
{
	float a,b;
	while(cin>>a>>b)
		cout<<game(a,b)<<endl;
	return 0;
}


		
