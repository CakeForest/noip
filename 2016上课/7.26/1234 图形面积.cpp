#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
//˫��ɢ�Ż�
//�Ƚ�x����߶γ���ӳ���ʾ����
//���ڸõ�����Ӧ����y��ƽ�е������Ҹ��ǵ��߶γ��� 
struct node{
	int x,y;
}a[1000],b[1000],c[1000];
int totx,tx[1000],ans;
int toty,sum,ty[1000],start[1000],end[1000],flag[1000];

bool judge(node a,node b,int aim){//�ж�ab���ڵ������Ƿ������aim
	if(a.x<=aim&&b.x>aim)
	 	return 1;
	return 0;
}

void add(int a,int b){//����Ԫ�� 
	ty[++toty]=a; ty[++toty]=b;
	start[++sum]=min(a,b); 
	end[sum]=max(a,b);
}
void memoset(){//���Ԫ�� 
	toty=sum=0;
	memset(ty,0,sizeof(ty));
}

int Find(int s,int e,int aim){//��Ԫ�ص�λ�� 
	int mid;
	while(s<=e){
		mid=(s+e)>>1;
		if(ty[mid]==aim){
			while(ty[mid-1]==ty[mid]) mid--;
			return mid;
		}else if(ty[mid]>aim)
			e=mid-1;
		else s=mid+1;
	}
}

int MaxFG(){//�󸲸ǳ���
	int h=0;
	sort(ty+1,ty+1+toty);
	for(int i=1;i<=toty-1;i++)
		if(ty[i])
	for(int i=1;i<=sum;i++)
		for(int j=Find(start[i]);j<=Find(end[i])-1;j++)
			flag[j]=1;
	for(int i=1;i<=toty-1;i++)
		if(flag[i]==1)
			h+=ty[i+1]-ty[i];
	return h;
} 

int main(){
	freopen("in.txt","r",stdin);
	int n,d,h;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
		scanf("%d%d",&b[i].x,&b[i].y);
	}
	for(int i=1;i<=n;i++){
		tx[++totx]=a[i].x;
		tx[++totx]=b[i].x;
	}
	sort(tx+1,tx+1+totx);
	for(int i=1;i<=totx-1;i++){
		if(tx[i]==tx[i+1]) continue;
		memset(ty,0,sizeof(ty));
		d=tx[i+1]-tx[i];//�� 
		memoset();
		for(int j=1;j<=n;j++)
			if(judge(a[i],b[i],tx[i]))
				add(a[i].y,b[i].y);
		ans+=d*FindFG();
	}
	
	return 0;
}
