#include <stdio.h>
#include <string.h>
main()
{
    char x[200],y[200];
    int a[200]={0},b[200]={0},k,i;
    freopen("add.in","r",stdin); 
	freopen("add.out","w",stdout);
    scanf("%s%s",x,y);
    k=strlen(x);
    for(i=0;i<k;i++) a[k-i-1]=x[i]-'0';
    k=strlen(y);
    for(i=0;i<k;i++) b[k-i-1]=y[i]-'0';
    k=strlen(x)>strlen(y)?strlen(x):strlen(y);
    for(i=0;i<k;i++)
    {
        a[i]+=b[i];
        a[i+1]+=a[i]/10;
        a[i]%=10;
    }
    if(a[k]!=0) k++;
    for(i=k-1;i>=0;i--) printf("%d",a[i]);
}
