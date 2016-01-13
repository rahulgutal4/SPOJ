#include <iostream>
#include <cstring>
using namespace std;

int main() {
	
	int k,l,m;
	scanf("%d%d%d",&k,&l,&m);
	
	int coins;
	bool dp[1000005];
	dp[0] = false;
	
	for(int j=1;j<=1000005;j++){
			
			dp[j] = false;
			if( (j-1)>=0 && dp[j-1] == false) dp[j] = true;
			else if((j-k)>=0 && dp[j-k] == false) dp[j] = true;
			else if((j-l)>=0 && dp[j-l] == false) dp[j] = true;
			
	}
	
	for(int i=0;i<m;i++){
		
		scanf("%d",&coins);
	
		if(dp[coins] ==  true) printf("A");
		else printf("B");
	}
	
	return 0;
}