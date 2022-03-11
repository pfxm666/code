#include <stdio.h>
double min(double x,double y); 
int main(void)
{
	int N,T,i,j;
	double L,C,VR,VT1,VT2,tmp;
	double dp[105];									//存储到该位置充电桩所需时间  
	double pos[102];
	while(scanf("%lf",&L)!=EOF)
	{ 
		scanf("%d%lf%d",&N,&C,&T);
		scanf("%lf%lf%lf",&VR,&VT1,&VT2);
		for(i=0;i<N;i++)
		{
		scanf("%lf",&pos[i]);
		}
		pos[N]=L;  									//将终点也视为一个充电桩 
		for(i=0;i<=N;i++)
		{
			if(pos[i]<=C)
			dp[i]=pos[i]/VT1;
			else
			dp[i]=C/VT1+(pos[i]-C)/VT2;				//将dp初始化
		}
		for(i=0;i<N;i++)							//从第一个充电桩开始对每个充电桩是否充电进行遍历
		{											 
			for(j=i+1;j<=N;j++)
			{
				if(pos[j]-pos[i]<=C)
				tmp=(pos[j]-pos[i])/VT1;
				else
				tmp=C/VT1+(pos[j]-pos[i]-C)/VT2;
				dp[j]=min(dp[j],dp[i]+T+tmp);		 //充电与否进行判断，并进行存储 
			}										
		} 
		if(dp[N]<L/VR)
		printf("What a pity rabbit!\n");
		else
		printf("Good job,rabbit!\n");
	}
	return 0;
}

double min(double x,double y)
{
	if(x>y)
	return y;
	else
	return x;
}
