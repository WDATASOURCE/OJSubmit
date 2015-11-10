#include<iostream>
#include<string>
using namespace std;

int vorc(char ch)
{
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
        return 1;
    else
        return 0;
}

int ac(string s)
{
    int len=s.length(),i;
    for(i=0;i<len;i++)
        if(vorc(s[i]))
            break;
    if(i>=len)
        return 0;
    for(i=0;i<len-2;i++)
        if(vorc(s[i])==vorc(s[i+1])&&vorc(s[i])==vorc(s[i+2]))
            return 0;
    for(i=0;i<len-1;i++)
        if(s[i]==s[i+1]&&s[i]!='e'&&s[i]!='o')
            return 0;
    return 1;
}

int main()
{
    string s;
    while(cin>>s&&s!="end")
    {
        if(ac(s))
            cout<<"<"<<s<<">"<<" is acceptable.\n";
        else
            cout<<"<"<<s<<">"<<" is not acceptable.\n";
    }
    return 0;
}
