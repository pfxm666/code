#include <stdio.h>
int main(void)
{
	int n,i,j;
	int max,min,max1,min1;
	int arr[100102]={0};
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	scanf("%d",&arr[i]);
	max1=1;
	min1=1;
	max=arr[1];
	min=arr[1];
	for(i=1,j=n;i<=n;i++,j--)
	{
		if(arr[i]>max)
		{
			max=arr[i];
			max1=i;
		}
		if(arr[j]<min)
		{
			min=arr[j];
			min1=j;
		}
	}
	if(max1>min1)
	{
		for(i=min1,j=max1;i>0||j<=n;i--,j++)
		{	
			if(i>0)
			{
				if(arr[i]>min)
				{
					printf("3\n%d %d %d",i,min1,max1);
					break;
				}
			}
			if(j<=n)
			{
				if(arr[j]<max)
				{
					printf("3\n%d %d %d",min1,max1,j);
					break;
				}
			}
			if(j==n&&i<=1)
			printf("0");
		}
	}
	if(max1<min1)
	{
		for(i=max1,j=min1;i>0||j<=n;i--,j++)
		{	
			if(i>0)
			{
				if(arr[i]<max)
				{
					printf("3\n%d %d %d",i,max1,min1);
					break;
				}
			}
			if(j<=n)
			{
				if(arr[j]>min)
				{
					printf("3\n%d %d %d",max1,min1,j);
					break;
				}
			}
			if(j==n&&i<=1)
			printf("0");
		}
	}
	if(max1==min1)
	printf("0");
	return 0;
}
