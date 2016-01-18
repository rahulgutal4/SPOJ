#include <iostream>
#include <cstring>
using namespace std;

int l1,l2,dp1[1005][1005];
int next1[1005][1005];
string s1,s2;

int dp(int i,int j){
	
	if(i == l1) return 1005;
	
	if(dp1[i][j] == -1){
		
		int x = s2.find(s1[i],j);
		int ans = 0;
		
		if(x == -1){
			ans = 1;
		}else{
			
			if(dp1[i+1][x+1] == -1){
				dp1[i+1][x+1] = dp(i+1,x+1);
			}
			
			if(dp1[i+1][j] == -1){
				dp1[i+1][j] = dp(i+1,j);
			}
			ans = min(1 + dp1[i+1][x+1] , dp1[i+1][j]); 
		}
		
		dp1[i][j] = ans;
	}
	
	return dp1[i][j];
}	

int main() {
	
	
	cin>>s1>>s2;
	l1 = s1.length();
	l2 = s2.length();
	
	memset(dp1,-1,sizeof(dp1));
	cout<<dp(0,0);
//	cout<<s2.find(s1[0],3);	
	return 0;
}