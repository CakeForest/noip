#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
struct node{
    int s,e;
}line[1000020];
int n,left,right;
int cmp(node l1,node l2)
{
    if(l1.s!=l2.s)
        return l1.s<l2.s;//�����㲻ͬ��������� 
}
 
void Test()//���� 
{
    for(int i=1;i<=n;i++)
        printf("%d %d\n",line[i].s,line[i].e);
    printf("\n\n\n");
}
 
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d %d",&line[i].s,&line[i].e);
    scanf("%d %d",&left,&right);
    sort(line+1,line+n+1,cmp);
     
/*  Test();
    return 0;*/
    int i=1,sum=0,flag=0;
    while(i<=n&&flag==0)
    {
        int farest=-1;//��¼�ܴﵽ����Զλ�� 
        while(line[i].s<=left)
        {
            if(line[i].e>farest)
                farest=line[i].e;
            i++;
        }
        if(farest==-1)
            goto end;
        left=farest;
        sum++;
        if(left>=right)
            flag=1;
    }
    if(flag==1)
        printf("%d",sum);
    else
        end:printf("no solution!");
 
     
    return 0;
}

