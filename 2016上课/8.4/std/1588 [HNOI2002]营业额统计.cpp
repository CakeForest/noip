#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define N 32768
using namespace std;
/*
 * 
 */
int min(int a,int b)
{return a<b?a:b;}
int top;
struct SBT
{
    int left,right;
    int key;
    int size;
    void init()
    {
        left=right=0;
        size=1;
    }
}T[N];
void R_Rotate(int &t)
{
    int k=T[t].left;
    T[t].left=T[k].right;
    T[k].right=t;
    T[k].size=T[t].size;
    T[t].size=T[T[t].left].size+T[T[t].right].size+1;
    t=k;
    return ;
}
void L_Rotate(int &t)
{
    int k=T[t].right;
    T[t].right=T[k].left;
    T[k].left=t;
    T[k].size=T[t].size;
    T[t].size=T[T[t].left].size+T[T[t].right].size+1;
    t=k;
    return ;
}
void Maintain(int &t,bool flag)
{
    if(flag==false)
    {
        if(T[T[T[t].left].left].size>T[T[t].right].size)
            R_Rotate(t);
        else if(T[T[T[t].left].right].size>T[T[t].right].size)
        {
            L_Rotate(T[t].left);
            R_Rotate(t);
        }
        else
            return ;
    }
    else
    {
        if(T[T[T[t].right].right].size>T[T[t].left].size)
            L_Rotate(t);
        else if(T[T[T[t].right].left].size>T[T[t].left].size)
        {
            R_Rotate(T[t].right);
            L_Rotate(t);
        }
        else
            return ;
    }
    Maintain(T[t].left,false);
    Maintain(T[t].right,true);
    Maintain(t,false);
    Maintain(t,true);
}
void Insert(int &t,int v)
{
    if(t==0)
    {
        t=++top;
        T[t].init();
        T[t].key=v;
    }
    else
    {
        T[t].size++;
        if(v<T[t].key)
            Insert(T[t].left,v);
        else
            Insert(T[t].right,v);
        Maintain(t,v>=T[t].key);
    }
}
int Pred(int t,int v)
{
    if(t==0)
        return v;
    if(v>T[t].key)
    {
        int ret=Pred(T[t].right,v);
        if(ret==v)
            return T[t].key;
        return ret;
    }
    else
        return Pred(T[t].left,v);
}
int Succ(int t,int v)
{
    if(t==0)
        return v;
    if(v>=T[t].key)
        return Succ(T[t].right,v);
    else
    {
        int ret=Succ(T[t].left,v);
        if(v==ret)
            return T[t].key;
        return ret;
    }
}
int Exist(int t,int x)
{
    if(t==0)
        return 0;
    if(x<T[t].key)
        return Exist(T[t].left,x);
    else if(x==T[t].key)
        return 1;
    else
        return Exist(T[t].right,x);
}
int main(int argc, char** argv)
{
    freopen("in.txt","r",stdin);
 //   freopen("out.out","w",stdout);
    int n,ans=0,root=0,key;
    top=0;
    scanf("%d",&n);
    scanf("%d",&key);
    ans+=key;
    Insert(root,key);
    for(int i=2;i<=n;i++)
    {
       if(scanf("%d",&key)==EOF)//这里特殊处理
            key=0;
       // if(key==1)
        //    printf("%d %d/n",i,key);
        if(Exist(root,key))
            continue;
        int P=Pred(root,key),S=Succ(root,key);
        if(P==key)
            ans+=abs(key-S);
        else if(S==key)
            ans+=abs(key-P);
        else
            ans+=min(abs(key-P),abs(key-S));
        Insert(root,key);
        
    }printf("%d\n",ans);
 /*   if(ans==2163807)
        ans++;
    if(ans==1143502)
        ans++;*/
    
    printf("\n\n");
    for(int i=1;i<=top;i++)
    	printf("%d %d %d\n",T[i].key,T[i].left,T[i].right);
    
    
    return 0;
}
