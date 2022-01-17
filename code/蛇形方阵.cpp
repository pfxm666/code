#include <stdio.h>
int main(void)
{
	int n,i,j;
	int arr[100][100]={0};
	int dy[]={0,1,0,-1};
	int dx[]={1,0,-1,0};
	scanf("%d",&n);
	int d=0,x=1,y=1,a=1,b=1; 
	for(i=1;i<=n*n;i++)
	{
		arr[y][x]=i;
		b=y+dy[d];
		a=x+dx[d];
		if(b<1||b>n||a<1||a>n||arr[b][a])
		{
			d=(d+1)%4;
			b=y+dy[d];
			a=x+dx[d];
		}
		y=b;
		x=a;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(arr[i][j]<10)
			printf("  %d",arr[i][j]);
			if(arr[i][j]>=10)
			printf(" %d",arr[i][j]);
		}
		printf("\n");
	}
	return 0;	
} 
