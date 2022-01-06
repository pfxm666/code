#include <stdio.h>
struct node{
	int chinese;
	int math;
	int english;
	int zong;
};
int main(void)
{
	int n,i,j,k=0,l;
	struct node arr[1010];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d",&arr[i].chinese,&arr[i].math,&arr[i].english);
		arr[i].zong=arr[i].chinese+arr[i].math+arr[i].english;
	}
	for(l=0;l<n-1;l++)
	{	
		for(i=l+1;i<n;i++)
		{
			j=0;
			if(arr[l].chinese-arr[i].chinese>5||arr[l].chinese-arr[i].chinese<-5)
			j++;
			if(arr[l].math-arr[i].math>5||arr[l].math-arr[i].math<-5)
			j++;
			if(arr[l].english-arr[i].english>5||arr[l].english-arr[i].english<-5)
			j++;
			if(arr[l].zong-arr[i].zong>10||arr[l].zong-arr[i].zong<-10)
			j++;
			if(j==0)
			k++;
		}
	}
	printf("%d",k);
}
