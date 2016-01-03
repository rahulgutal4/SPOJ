#include <iostream>
using namespace std;
typedef long long unsigned int ll;

int main() {
	
	int n;
	long arr[1000005][2];
	cin>>n;
	
	for(ll i=1;i<=n;i++){
		
		scanf("%ld%ld",&arr[i][0],&arr[i][1]);
		
	}
	
	int max1=-1,cnt=0;
	int i=n;
	while(i>0){
		
		int max2 = arr[i][1],j = i-1;
		while(arr[j][0] == arr[i][0] && j>0 ){
			if(max2 < arr[j][1]){
				max2 = arr[j][1];
			}
			j--;
		}
		
		if(max1 < max2){
			cnt++;
			max1 = max2;
		}		
		
		i = j;
	}
	
	cout<<cnt<<"\n";
	
	return 0;
}