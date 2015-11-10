#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct a
{
	int r,e,c;
};
int main(int argc, char** argv) {
	int n,i;
	cin>>n;
	a *s=new a[n];
	for(i=0;i<n;i++)
	{
		cin>>s[i].r>>s[i].e>>s[i].c;
	}
	for(i=0;i<n;i++)
	{
		if(s[i].r>s[i].e-s[i].c)
		cout<<"do not advertise"<<endl;
		else if(s[i].r<s[i].e-s[i].c)
		cout<<"advertise"<<endl;
		else
			cout<<"does not matter"<<endl;
	}

	return 0;
}
