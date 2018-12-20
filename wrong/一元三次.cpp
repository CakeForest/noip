#include<cstdio>
int a,b,c,d;
float f(float x)
{
	float sum;
	sum=a*x*x*x+b*x*x+c*x+d;
	return sum;
}
void look(float x,float y)
{
	float m;
      if(x>y)
      return ;
		m=(x+y)/2.0;
		//[x,m],(m,y]
	    if(f(x)*f(m)<0){
	    	if(f(x)==0||f(x+0.0005)*f(x-0.0005)<0)
	    	printf("%.2f",x);
	    	else
	    	look(x,m);
	    }//在1区间 				
		if(f(m)*f(y)<0){
			if(f(m)==0||f(m+0.0005)*f(m-0.0005)<0)
			printf("%2.f",m);
			else
			look(m,y);
		}//在2区间 
		
	
	
}



int main()
{
	int i;
	scanf("%d%d%d%d",&a,&b,&c,&d);
    for(i=-100;i<=100;i++)
    {
    	if(f(i)==0)
    	printf("%d.00 ",i);
    	if(f(i)*f(i+1)<0)
    	look(i,i+1);    	
    }
	return 0;
}
