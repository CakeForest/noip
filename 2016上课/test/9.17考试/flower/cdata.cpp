#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
string s[60000];
int a[60000],b[60000],c[60000];
int main()
{
	freopen("1004.out","r",stdin);
    freopen("data11.out","w",stdout);
    int k=50000;
	int x,y,n,i,j,tot=0;
    for(i=1;i<=k;i++)
    { 
         getline(cin,s[i]);
         cout<<s[i]<<endl;
    }
    return 0;
    
}
