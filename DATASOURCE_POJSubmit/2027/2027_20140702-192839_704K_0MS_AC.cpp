#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct a
{
	int a,b;
};
int main(int argc, char** argv) {
	int n,i;
	cin>>n;
	a *s=new a[n];
	for(i=0;i<n;i++)
	{
		cin>>s[i].a>>s[i].b;
	}
	for(i=0;i<n;i++)
	{
		if(s[i].a>=s[i].b)
		cout<<"MMM BRAINS"<<endl;
		else
		cout<<"NO BRAINS"<<endl;
	}

	return 0;
}
