#include <stdio.h>
double min(double x,double y); 
int main(void)
{
	int N,T,i,j;
	double L,C,VR,VT1,VT2,tmp;
	double dp[105];									//�洢����λ�ó��׮����ʱ��  
	double pos[102];
	while(scanf("%lf",&L)!=EOF)
	{ 
		scanf("%d%lf%d",&N,&C,&T);
		scanf("%lf%lf%lf",&VR,&VT1,&VT2);
		for(i=0;i<N;i++)
		{
		scanf("%lf",&pos[i]);
		}
		pos[N]=L;  									//���յ�Ҳ��Ϊһ�����׮ 
		for(i=0;i<=N;i++)
		{
			if(pos[i]<=C)
			dp[i]=pos[i]/VT1;
			else
			dp[i]=C/VT1+(pos[i]-C)/VT2;				//��dp��ʼ��
		}
		for(i=0;i<N;i++)							//�ӵ�һ�����׮��ʼ��ÿ�����׮�Ƿ�����б���
		{											 
			for(j=i+1;j<=N;j++)
			{
				if(pos[j]-pos[i]<=C)
				tmp=(pos[j]-pos[i])/VT1;
				else
				tmp=C/VT1+(pos[j]-pos[i]-C)/VT2;
				dp[j]=min(dp[j],dp[i]+T+tmp);		 //����������жϣ������д洢 
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
