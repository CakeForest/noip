#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=60;
int n,k,p,cnt[MAX],sum[MAX],c,np;
int main()
{
	freopen("hotel.in","r",stdin);
	freopen("hotel.out","w",stdout);
	long long ans=0;
	scanf("%d%d%d",&n,&k,&p);
	
	for(int i=1;i<=n;i++){
		scanf("%d%d",&c,&np);
		cnt[c]++;//�ݴ汾�ε�ÿ����ɫ�õ������ 
		if(np<=p){
			for(int j=0;j<=k-1;j++)
				sum[j]+=cnt[j];//����ÿ����ɫ�õ�������� 
			memset(cnt,0,sizeof(cnt));
			ans--;//���ȹݱ���ᱻ����һ�� 
		}
		ans+=sum[c];
	}
	printf("%lld",ans);
}
