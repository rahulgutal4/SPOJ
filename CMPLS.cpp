#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t,s,c,cnt,i,j;
	int test[100][100];
	
	cin>>t;
	while(t)
	{
		for(i=0;i<100;i++)
		for(j=0;j<100;j++)
		  test[i][j]=0;
		cin>>s>>c;
		for(i=0;i<s;i++) cin>>test[0][i];
		
		cnt=0;
		while(1)
		{
			for(i=0;i<(s-cnt);i++)
			{
				if(test[cnt][i-1]!=test[cnt][i]) break;
			}
			if(i==(s-cnt)) break;
			
			cnt++;
			
			for(int j=0;j<s-cnt;j++)
		    	test[cnt][j]=test[cnt-1][j+1] - test[cnt-1][j];
		    	
		    	
		}
		
		for(i=s-cnt;i<s-cnt+c;i++)
		{
			test[cnt][i]=test[cnt][i-1];
		}
		cnt--;
		
		while(cnt>=0)
		{
			for(int i=0;i<c;i++)
			{
				test[cnt][s-cnt+i] = test[cnt][s-cnt+i-1] + test[cnt+1][s-cnt+i-1];
			}
			cnt--;
		}
		
		for(i=s;i<s+c;i++) cout<<test[0][i]<<" ";
		cout<<"\n";
		t--;
	}
	return 0;
}