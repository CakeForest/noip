#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
struct string{
	char s[60];
}str[120];

int cmp(string a,string b)
{
	return strcmp(a.s,b.s)<=0;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int n=0;
	while(scanf("%s",str[n].s)!=EOF)
		n++;
	sort(str,str+n,cmp);
	
	for(int i=0;i<n;i++)
		if(strcmp(str[i].s,str[i+1].s)!=0)
			printf("%s\n",str[i].s);
	
}
