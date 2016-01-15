#include <iostream>
using namespace std;

int main() {
	
    int testCases,bond[11][2],amount,years,bonds,dp[50005]={0},N,rem,counter;
    unsigned long long res;
	
	scanf("%d",&testCases);
	
	while(testCases--){
		
		scanf("%d%d%d",&N,&years,&bonds);
	
		rem=N%1000;
		N=N/1000;
		
		for(int i=1;i<=bonds;i++){
			scanf("%d%d",&bond[i][0],&bond[i][1]);
			bond[i][0] /= 1000;
		}
		
		counter = 0;
		for(int i=1;i<=years;i++){
				
			for(int i=counter;i<=N;i++) dp[i]=0;
				
				for(int k=counter;k<=N;k++){	
					for(int j=1;j<=bonds;j++){
			
						if(k >= bond[j][0]){
							dp[k] = max(dp[k], dp[k-bond[j][0]]+bond[j][1]);
						}
				}
			
			}
		
			res=dp[N];
			N=N+(res+rem)/1000;
			rem=(res+rem)%1000;
			
		}
		
		printf("%d\n",(N*1000+rem));
	
		
	}
	return 0;
}
