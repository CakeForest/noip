#include<cstdio>
#include<algorithm>
#include<cmath>
#define oo 99999999
using namespace std;
const int MAX=210000;
typedef long long LL;//!!!!!!!long long
LL n,m,S;
LL w[MAX],v[MAX],l[MAX],r[MAX];
LL cnt[MAX],sum[MAX];
//���ַ�ת��Ϊ���ַ� 


LL calc(LL W){
	cnt[0]=sum[0]=0;
	//cnt[]��ʾǰi����ʯ���ϱ�׼�ĸ���
	//sum[]��ʾǰi����ʯ��ֵ���� 
	for(int i=1;i<=n;i++){
		if(w[i]>=W){//����ѡ��˿�ʯ 
			cnt[i]=cnt[i-1]+1;
			sum[i]=sum[i-1]+v[i];
		}else{//��ѡ�˿�ʯ 
			cnt[i]=cnt[i-1];
			sum[i]=sum[i-1];
		}
	}
	
	LL tot=0;
	for(int i=1;i<=m;i++)
		tot+=(cnt[r[i]]-cnt[l[i]-1])*(sum[r[i]]-sum[l[i]-1]);
	
	return tot;
}

int main(){
	freopen("qc.in","r",stdin);
//	freopen("qc.out","w",stdout);
	
	LL s=oo,e=-oo;
	scanf("%lld%lld%lld",&n,&m,&S);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&w[i],&v[i]);
		s=min(s,w[i]);//�����½� 
		e=max(e,w[i]);//�����Ͻ� 
	}
	for(int i=1;i<=m;i++)
		scanf("%lld%lld",&l[i],&r[i]);
	
	LL log=-oo;
	while(s<=e){
		LL m=(s+e)>>1;
		LL t=calc(m);
		if(t>S) s=m+1;//t������S������������ 
		else{
			if(t>=log){//t�ոպã����´� 
				e=m-1;
				log=t;
			}
			else s=m+1;
		}
	}
	//���ַ�ת���ַ� 
	LL ans=abs(calc(s)-S);//S>tʱ����ֵ 
	ans=min(ans,abs(calc(s-1)-S));//t>Sʱ����ֵ 
	
	printf("%lld",ans);
	
}
