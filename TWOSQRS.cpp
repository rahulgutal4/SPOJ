#include <iostream>
#include <cmath>
using namespace std;

int main() {
	
	int testCases,prime[79000],cnt=0;
	prime[cnt++]=2;
	
	bool flag=true;
	int cap=-1,p=-1;
	for(int i=3;i<=1000000;i+=2){
		
		flag=true;
		cap=sqrt(i)+1;
		
		for(int j=0;j<cnt;j++){
			
			p=prime[j];
			
			if(p>=cap) break;
			
			if(i%p==0){
				flag=false;
				break;
			}
			
		}
		
		if(flag) prime[cnt++]=i;
		
	}
	
	//for(int i=0;i<cnt;i++) cout<<prime[i]<<" ";
	
	scanf("%d",&testCases);
	
	while(testCases--){
		
		long long int n;
		scanf("%lld",&n);
		
		if (n==0) {
			printf("Yes\n");
			continue;
		}
		
		int k=0;
		bool flag=true;
		for(int i=0;i<cnt;i++){
			
			while(n%prime[i]==0){
				if(prime[i]%4==3) k++;
				n/=prime[i];
			}
			
			if(k%2!=0) {
				printf("No\n");
				flag=false;
				break;
			}
			
		}
		
		if(flag && n%4!=3) printf("Yes\n");
		else if(flag) printf("No\n");
		
	}
	
	return 0;
}
