#include<stdio.h> 
  
int n,a[1000000]; 
  
int q[1000000]; 
void merge(int l,int m,int r) 
{ 
    int i=l,j=m+1,k=0; 
    while(i<=m&&j<=r)//��ǰi/j ������������  
    { 
        if(a[i]<a[j]) 
        { 
            q[k]=a[i]; 
            i++; 
        } 
        else
        { 
            q[k]=a[j]; 
            j++; 
        } 
        k++; 
    } 
    int now=i<=m?i:j; 
    for(int g=k;g<=r-l;g++)//�Ժ��������������  
    { 
        q[g]=a[now]; 
        now++; 
    } 
      
    for(int g=0;g<=r-l;g++)//����������ִ�������  
        a[g+l]=q[g]; 
  
} 
  
/* 
int h[1000000]; 
void merge(int x,int m,int y){ 
    int p=x,q=m+1,i=x; 
    while(p<=m && q<=y){ 
        if(a[p]<a[q]) h[i++]=a[p++]; 
        else h[i++]=a[q++]; 
    } 
    if(p<=m){ 
        while(p<=m) h[i++]=a[p++];  
    } 
    if(q<=y){ 
        while(q<=y) h[i++]=a[q++];  
    } 
    for(i=x;i<=y;i++) a[i]=h[i]; 
} 
  
  
*/
  
  
  
  
  
  
void merge_sort(int l,int r) 
{ 
    if(l>=r) return;//�Ѿ������������� 
    else{ 
        int m=(l+r)/2; 
        merge_sort(l,m);//�ֽ��������ֱ�����  
        merge_sort(m+1,r); 
        merge(l,m,r);//�ۺ�  
    }  
} 
  
  
int main() 
{ 
//  freopen("in.txt","r",stdin); 
    scanf("%d",&n); 
    for(int i=1;i<=n;i++) 
        scanf("%d",&a[i]); 
    merge_sort(1,n); 
      
    for(int i=1;i<=n;i++) 
    { 
        printf("%d",a[i]); 
        if(i!=n) 
            printf("\n"); 
    } 
      
    return 0; 
} 

