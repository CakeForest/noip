#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXSIZE=3100;
char a[MAXSIZE],b[MAXSIZE];
int ans[MAXSIZE][MAXSIZE];

int main()
{
//	freopen("in.txt","r",stdin);
	scanf("%s %s",a+1,b+1);
	int alen=strlen(a+1),blen=strlen(b+1);
	for(int i=1;i<=alen;i++)//a字符串 
		ans[i][0]=i;
	for(int i=1;i<=blen;i++)//b字符串 
		ans[0][i]=i;	
	for(int i=1;i<=alen;i++)
		for(int j=1;j<=blen;j++){
			int zs=ans[i-1][j-1],s=ans[i-1][j]+1,z=ans[i][j-1]+1;//左上角所对应的数字 
			if(a[i]!=b[j])
				zs++;
			ans[i][j]=min(min(zs,z),s);	
		}
	if(alen==0){
		printf("%d",blen);
		return 0;
	}
	if(blen==0){
		printf("%d",alen);
		return 0;
	}
	printf("%d",ans[alen][blen]);
	
	return 0;
}
