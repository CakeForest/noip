#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=1e7+10;
int l[MAX],r[MAX],f[MAX],d[MAX],rt;

void Zig(int x){//˳ʱ����ת 
	int y=f[x];
	l[y]=r[x];//diff
	if(r[x]) f[r[x]]=y;//diff
	f[x]=f[y];
	if(f[y]){//�޸�x�ĸ��׵Ķ�����Ϣ 
		if(y==l[f[y]]) l[f[y]]=x;
		else r[f[y]]=x;
	}
	r[x]=y;//diff
	f[y]=x;
}

void Zag(int x){//��ʱ����ת 
	int y=f[x];
	r[y]=l[x];//diff
	if(l[x]) f[l[x]]=y;//diff
	f[x]=f[y];
	if(f[y]){
		if(y==l[f[y]]) l[f[y]]=x;
		else r[f[y]]=x;
	}
	l[x]=y;//diff
	f[y]=x;
	
}

void Splay(int x,int y){//��ת 
	while(f[x]!=y){
		if(f[f[x]]==y)//�Ѵﵽ����� 
			(l[f[x]]==x)?Zig(x):Zag(x);
		else{
			if(l[f[f[x]]]==f[x]){//��һ��Ϊ�� 
				if(l[f[x]]==x){//�ڶ���Ϊ�� 
					Zig(f[x]);
					Zig(x);
				}else{//�ڶ���Ϊ�� 
					Zag(x);
					Zig(x);
				}
			}else{//��һ��Ϊ�� 
				if(r[f[x]]==x){//�ڶ���Ϊ�� 
					Zag(f[x]);
					Zag(x);
				}else{//�ڶ���Ϊ�� 
					Zig(x);
					Zag(x);
				}
				
			}
		}
	}
	if(y==0) rt=x;//�޸ĸ���� 
}

int Find(int x,int key){
	if(!x) return 0;//�Ҳ��� 
	if(d[x]==key){
		Splay(x,0);
		return x;//���ظý������ 
	}else{
		if(d[x]>key) return Find(l[x],key);
		else return Find(r[x],key);
	}
	
}

void Insert(int id,int key){
	int ptr=rt,y=0;
	int lrChose=0;
	while(1){
		if(!ptr){//�ҵ��˲����λ�� 
			ptr=id;
			l[ptr]=r[ptr]=0;
			d[ptr]=key;
			f[ptr]=y;
			if(y!=0){//����ò���㲻�Ǹ��ڵ㣬��ô�丸�׽��Ķ�����Ҫ���� 
				if(lrChose==0) l[y]=ptr;
				else r[y]=ptr;
			}
			Splay(ptr,0);
			break;
		}
		y=ptr;//yΪ��ǰ���ĸ��׽�� 
		if(d[ptr]>key){
			ptr=l[ptr];
			lrChose=0;
		}else{
			ptr=r[ptr];
			lrChose=1;
		}
	}
}

int Join(int n1,int n2){
	f[n1]=f[n2]=0;//�������� 
	//һ�û�������Ϊ�� 
	if(!n1) return n2;
	if(!n2) return n1;
	
	int temp=n1;
	while(r[temp]) temp=r[temp];//�����
	Splay(temp,0);
	
	/*��Ϊn1Ϊ���㣬n2Ϊ�ҽڵ㣬
	���Ժϲ�ʱn2���Ǵ���n1������������*/
	r[temp]=n2;
	f[n2]=temp;
	return temp;
}

void Delete(int x){//ɾ�� 
	Splay(x,0);//ֱ�ӽ��ý����ת������㣬�ϲ��������� 
	rt=Join(l[x],r[x]);
}

int main(){
//	freopen("in.txt","r",stdin);
	int cmd,k,p;
	while(~scanf("%d",&cmd)&&cmd){
		if(cmd==1){
			scanf("%d%d",&k,&p);
			Insert(k,p);
		}else if(cmd==2){
			int temp=rt;
			while(r[temp]) temp=r[temp];
			printf("%d\n",temp);
			Delete(temp);
		}else{
			int temp=rt;
			while(l[temp]) temp=l[temp];
			printf("%d\n",temp);
			Delete(temp);
		}
	}
	
	return 0;
}
