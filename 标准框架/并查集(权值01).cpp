//ȨֵΪ0��1�Ĳ��鼯 
#include<cstdio>
using namespace std;
const int MAX=10000;
int father[MAX],val[MAX];
int Getfather(int p){
	if(p==father[p]) return p;
	int temp=father[p];//��¼�ɸ��� 
	father[p]=Getfather(father[p]);//���¸��� 
	val[p]=(val[p]+val[temp])%2;//����Ȩֵ 
	return father[p];
}
void unions(int a,int b,int v){
	int x=Getfather(a),y=Getfather(b);
	if(x==y) return;
	father[x]=y;
	val[x]=(val[a]+val[b])^1;
/*	�ϲ��������ϲ�����ֱ�Ӽӱ�Ȩ������Ҫ�жϱ�Ȩ��С
ʹ��Ȩ�Ժ�����֮��Ȩֵ�պ�Ϊv 	*/
}
int judge(int a,int b){
	if(Getfather(a)!=Getfather(b)) return -1;//δ�ϲ�
	return (val[a]+val[b])%2; 
}
int setfa(int n){
	for(int i=1;i<=n;i++) father[i]=i;
}
int main(){
//	freopen("in.txt","r",stdin); 
	
	setfa(MAX);
	unions(1,2,0);
	unions(4,3,1);
	unions(2,3,1);
	
	printf("%d %d",judge(1,4),judge(2,5));
	
	return 0;
}
