#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int s[1001],n,c,tot=0,flag=0,sum[1000],flags,vis[1001]; 
int mmax; 
void dfs(int t){
	//�ҵ��𰸼�֦ 
    if(flags==1) return;
    
    //����Ŀ���֦ 
    if(tot>c) return;
    
    //���Ž��֦ 
    if(mmax==c){
        flags=1;
        return;
    }
    if(tot>mmax){
        mmax=tot;
    }
    //ʣ������֦ 
    if(tot+sum[t]<mmax) return;
    if(tot+s[n]>c) return;
    
    //�˴�ѭ���ɴ���ֵ������֦ 
    for(int i=1;i<=n;i++){
    	//���ʱ�Ǽ�֦ 
        if(!vis[i]){
        	tot+=s[i];
        	vis[i]=1;
	        dfs(t+1);
	        vis[i]=0;
	        tot-=s[i];
        }
        
    }
}
 
int main()
{
    scanf("%d %d",&n,&c);
    for(int i=1;i<=n;i++) scanf("%d",&s[i]);
    
    //�����֦ 
    sort(s+1,s+n+1,greater<int>());
    
    
    //�����һ��Ԫ�ؽ��м��� 
    for(int i=n;i>=1;i--) sum[i]=sum[i+1]+s[i];
    
    dfs(1);
    //for(int i=1;i<=n;i++) printf("%d ",s[i]);
    printf("%d",mmax);
    return 0;
}
