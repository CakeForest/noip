#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int n,m;
	int w[20020];
	int wi[20020];
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&wi[i]);	
	
	int i=0;
	int p=1;
	while(1)
	{
		for(int k=1;k<=m;k++)
			if(w[k]==0)//������˽�����ˮ���ͻ���һ���� 
			{
				if(p==n)//�˶���ʼ��ˮ��ʱ�����ӵ��������������ʱ�� 
				{
					w[k]=wi[p];
					int max=-1;
					for(int z=1;z<=m;z++)
						if(w[z]>max)
							max=w[z];
					i+=max;
					printf("%d",i);
					return 0;
				}
				else
				{
					w[k]=wi[p];
					p++;					
				}

			}
		for(int k=1;k<=m;k++)
			w[k]--;
		i++;
	}
	
	return 0;
}