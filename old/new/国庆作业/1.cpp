#include<cstdio>
#include<cstdlib>

int main()
{
    int year,month;
	scanf("%d %d",&year,&month);
	int day=1;
	for(int i=1;i<=year-1900;i++)
	{
        int sum=1900+i-1;
        if((sum%4==0&&sum%100!=0)||sum%400==0)
            day+=2;
        else
            day++;
        if(day>=8)
            day-=7;
    }
    

    for(int i=1;i<month;i++)
    {
        if(i!=2)
        {
            switch(i)
            {
                case 1:case 3:case 5:case 7:case 8:case 10:case 12:day+=31%7;break;
                case 4:case 6:case 9:case 11:day+=30%7;break;

            }
        }
        else
        {
            if((year%4==0&&year%100!=0)||year%400==0)
                day+=29%7;
            else
                day+=28%7;
        }
        if(day>=8)
            day-=7;
    }
    
    int count;
    if(month!=2)
    {
        switch(month)
        {
            case 1:case 3:case 5:case 7:case 8:case 10:case 12:count=31;break;
            case 4:case 6:case 9:case 11:count=30;break;
        }
    }
    else
    {
        if((year%4==0&&year%100!=0)||year%400==0)
            count=29;
        else
            count=28;
    }

	printf("Sun Mon Tue Wed Thu Fri Sat\n");
    for(int i=day==7?0:day;i!=0;i--)
    {
        printf("    ");
    }
    int n=day;
    for(int i=1;i<=count;i++)
    {
        if(i<=9)
            printf("  %d",i);
        else
            printf(" %d",i);
        if(i==count)
        	;
        else if(n%7==6)
            printf("\n");
        else
            printf(" ");
        n++;
    }

	return 0;
}
