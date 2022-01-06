#include <stdio.h>
void quicksort(int arr[],int l,int r); 
int main(void)
{
	int arr[9]={9,5,2,8,1,6,0,4};
	int i;
	quicksort(arr,0,7);
	for(i=0;i<8;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}

void quicksort(int arr[],int l,int r)
{
	if(l>=r)
	return ;
	int left=l;
	int right=r;
	int pivot=arr[left];
	while(left<right)
	{
		while(arr[right]>=pivot&&left<right)
		right--;
		if(left<right)
		arr[left]=arr[right];
		while(arr[left]<=pivot&&left<right)
		left++;
		if(left<right)
		arr[right]=arr[left];
		if(left==right)
		arr[left]=pivot;	
	}
	quicksort(arr,l,left);
	quicksort(arr,left+1,r); 
}
