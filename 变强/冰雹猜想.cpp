#include <stdio.h>
int main(void)
{
	int a,i=0;
	int arr[1000];
	scanf("%d",&a);
	arr[0]=a;
	while(a!=1)
	{
		if(a%2==0)
		{ 
			a=a/2;
			arr[++i]=a;
		}
		else
		{
			a=a*3+1;
			arr[++i]=a;
		}
	}
	for(;i>=0;i--)
	{
		if(i!=0)
		printf("%d ",arr[i]);
		else
		printf("%d",arr[i]);		
	}
	return 0;
}
