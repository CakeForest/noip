#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int s[1001],n,c,tot=0,flag=0,sum[1000],flags,vis[1001]; 
int mmax; 
void dfs(int t){
	//找到答案剪枝 
    if(flags==1) return;
    
    //超出目标剪枝 
    if(tot>c) return;
    
    //最优解剪枝 
    if(mmax==c){
        flags=1;
        return;
    }
    if(tot>mmax){
        mmax=tot;
    }
    //剩余量剪枝 
    if(tot+sum[t]<mmax) return;
    if(tot+s[n]>c) return;
    
    //此处循环可传递值用来剪枝 
    for(int i=1;i<=n;i++){
    	//访问标记剪枝 
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
    
    //排序剪枝 
    sort(s+1,s+n+1,greater<int>());
    
    
    //对最后一个元素进行计算 
    for(int i=n;i>=1;i--) sum[i]=sum[i+1]+s[i];
    
    dfs(1);
    //for(int i=1;i<=n;i++) printf("%d ",s[i]);
    printf("%d",mmax);
    return 0;
}
