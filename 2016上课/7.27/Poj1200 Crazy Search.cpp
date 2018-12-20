#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int Z1=1000000007;
bool hashtable[Z1+100];
int n,nc,ans=0,asc[300],num,len,sum;
char str[8000000];
int main(){
//	freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&nc);
	scanf("%s",str);
	len=strlen(str);
	for(int i=0;i<len;i++)
		if(!asc[str[i]])
			asc[str[i]]=++num;
	for(int i=0;i<len-n+1;i++){
		sum=0;
		for(int j=i;j<i+n;j++)
			sum+=sum*nc+asc[str[j]];//将字符串作为nc进制数，转化为十进制 
		if(!hashtable[sum])
			hashtable[sum]=1,ans++;
	}
	printf("%d",ans);
	
	return 0;
}
