#include <stdio.h>
int main(void)
{
	int a[110];
	int i=0;
	scanf("%d",&a[i]);
	while(a[i]!=0)
	{
		i++;
		scanf("%d",&a[i]);
	}
	for(i=i-1;i>=0;i--)
	{	
		if(i!=0)
		printf("%d ",a[i]);
		else
		printf("%d",a[i]);
	}
	return 0;
}
