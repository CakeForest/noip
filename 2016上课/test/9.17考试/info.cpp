#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=120;
int fa[MAX],val[MAX];//ά��val[]���飬��ʾsum[i]-sum[fa[i]]=val[i] 
void in(int n){
	for(int i=0;i<=n;i++) fa[i]=i;
	memset(val,0,sizeof(val));
}

int Getfather(int p){
	if(fa[p]==p) return p;
	int temp=fa[p];
	fa[p]=Getfather(fa[p]);
	val[p]+=val[temp];//p��ǰȨֵ�����Լ���Ȩֵ���ϸ��׵�Ȩֵ 
	return fa[p];
}

int main(){
	freopen("INPUT.008.in","r",stdin);
//	freopen("info.out","w",stdout);
	
	int w,n,m,s,t,v;
	scanf("%d",&w);
	while(w--){
		scanf("%d%d",&n,&m);
		in(n); bool flag=0;
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&s,&t,&v);
			if(flag) continue;
			s--;
			if(Getfather(s)!=Getfather(t)){//���ײ�ͬ���ϲ� 
				val[fa[t]]=val[s]-val[t]+v;//val[fa[t]]+val[t]=val[s]+v
				fa[fa[t]]=fa[s];
			}
			else if(val[t]-val[s]!=v) flag=1;//������ͬ���ж��Ƿ���� 
		}
		if(flag) printf("false\n");
		else printf("true\n");
	}
	
	return 0;
}
