#include <iostream>
using namespace std;



int main()
{
	int testCases,T,N,dp[251][101],dp1[251][101],risk[101][101],cost[101][101];
	scanf ("%d", &testCases);
	while(testCases--){
		
		scanf("%d%d",&N,&T);
		for(int i = 1; i <= N;i++)
			for(int j = 1; j <= N; j++)
				scanf("%d",&cost[i][j]);
				
		for(int i = 1; i <= N;i++)
			for(int j = 1; j <= N; j++)
				scanf("%d",&risk[i][j]);
				
		for(int i = 0;i <= N; i ++)
			for(int j = 0;j <= T; j ++)
				dp[j][i]=99999999;
				
		for(int i = 0;i <= N; i ++)
			for(int j = 0;j <= T; j ++)
				dp1[j][i]=99999999;		
        
		for(int i = 0; i <= T; i++){
			dp[i][N] = 0;
			dp1[i][N] = 0;
		}
        
		for(int i = 1; i <= T; i ++)
		{
			for(int j = 1; j <= N ;j++)
			{
				for(int k = 1; k <= N; k++)
				{
					if((j==k)||(i<cost[j][k]))
						continue;
					int a,b;
					a = risk[j][k] + dp[i-cost[j][k]][k];
					b = cost[j][k] + dp1[i-cost[j][k]][k];
						
					if(b <= T){
						if(a < dp[i][j]){
							dp[i][j] = a;
							dp1[i][j] = b;
						}
					}	
						
				}
			}
		}
		
		if(dp1[T][1] > T)
			printf("-1\n");
		else
			printf("%d %d\n", dp[T][1], dp1[T][1]);
	}
    
	return 0;
}