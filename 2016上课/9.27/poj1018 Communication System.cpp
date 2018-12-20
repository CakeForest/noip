#include<cstdio>
#include<algorithm>
using namespace std;
int d[]={0,1,2,2,2,2,2,3};

int nor_find(int s,int e,int key){//��ͨ���� 
	while(s<=e){
		int m=(s+e)>>1;
		if(d[m]==key) return m;
		else if(d[m]<key) s=m+1;
		else e=m-1;
	}
	return -1;
}

int front_find(int s,int e,int key){//�ҵ�һ�γ��ֵ�λ�� 
	while(s<=e){
		int m=(s+e)>>1;
		if(d[m]>=key) e=m-1;
		else s=m+1;
	}
	if(d[s]==key) return s;//ע�� 
	return -1;
}

int tail_find(int s,int e,int key){//�����һ�γ��ֵ�λ�� 
	while(s<=e){
		int m=(s+e)>>1;
		if(d[m]<=key) s=m+1;
		else e=m-1;
	}
	if(d[e]==key) return e;//ע�� 
	return -1;
}
int main(){
//	freopen("in.txt","r",stdin);

//	sort(d,d+10);
	printf("%