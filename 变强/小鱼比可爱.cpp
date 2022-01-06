#include <stdio.h>
int main(void)
{
	int a[110]={0};
	int n,i,k,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("0");
	for(i=1;i<n;i++)
	{	k=0;
		for(j=i-1;j>=0;j--)
		{
			if(a[i]>a[j])
			k++;
		}
		printf(" %d",k);
	}
	return 0;
}
