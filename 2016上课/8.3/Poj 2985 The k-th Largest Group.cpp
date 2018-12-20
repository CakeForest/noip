#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=200020;
int father[MAX],e[MAX];
int cnt[MAX];//�洢��iֻè�ļ����� 
int n,m,op,a,b,num;
int lowbit(int x){
	return -x&x;
}
void add(int x,int t){
	for(;x<=MAX;x+=lowbit(x))
		e[x]+=t;
}
int Getfather(int p){
	if(father[p]!=p) 
		father[p]=Getfather(father[p]);
	return father[p];
}
int Get_kth(int k){
	int ans,tot;//�����ҵ�kС 
	ans=tot=0;
	for(int i=20;i>=0;i--){
		ans+=1<<i;//���� 
		if(ans>=MAX||tot+e[ans]>=k)//����γ����Ƿ񳬹���Χ 
			ans-=1<<i;//��ԭ 
		else tot+=e[ans];//��¼ 
	}
	return ans+1;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		father[i]=i;//���鼯��ʼ�� 
		cnt[i]=1;//��ʾ������iֻè����������ʼֻ��һ�� 
	}num=n;//num������ 
	add(1,n);
	for(int i=1;i<=m;i++){
		scanf("%d",&op);
		if(op){
			scanf("%d",&a);//��k����ǵ�num - k + 1С��
			printf("%d\n",Get_kth(num-a+1));
		}else{
			scanf("%d%d",&a,&b);
			a=Getfather(a); b=Getfather(b);//ȡ���� 
			if(a==b) continue;//��������һ������ 
			add(cnt[a],-1); add(cnt[b],-1);
			add(cnt[a]+cnt[b],1);
			cnt[b]=cnt[a]+cnt[b];
			father[a]=b;
			num--;
		}
	}
	return 0;
}
