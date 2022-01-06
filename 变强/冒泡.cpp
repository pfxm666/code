#include <stdio.h>
int main(void)
{
	int arr[8]={1,0,8,9,7,11,12};
	int i,j,n=7,temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
			
		}
	}
	for(i=0;i<n;i++)
	printf("%d ",arr[i]);
		
} 
