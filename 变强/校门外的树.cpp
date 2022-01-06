#include <stdio.h>
int main(void)
{
	int l,m,u,v;
	int i,k=0,j;
	int a[10010]={0};
	scanf("%d%d",&l,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&u,&v);
		for(j=u;j<=v;j++)
		{
			a[j]=1;
		}
	}
	for(i=0;i<=l;i++)
	{
		if(a[i]==0)
		k++;
	}
	printf("%d",k);
	return 0;
}
