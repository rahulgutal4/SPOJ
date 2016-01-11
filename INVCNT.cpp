#include <iostream>
#include <cstring>
using namespace std;
typedef long long unsigned int ll;
int bit[10000001],n;

void update(int index){

	bit[index]++;
	index += (index & -index);
	while(index <= 10000000){
		
		bit[index]++;
		index += (index & -index);
		
	}
	
}	

ll largeNumber(int index){
	
    ll cnt = 0;
	while(index > 0){
		cnt = cnt + bit[index];
		index = index - (index & -index);
	}
	return cnt;
	
}

int main() {
	
	int t;
	ll inversions = 0;
	cin>>t;
	
	while(t--){
		
		cin>>n;
		int temp;
		inversions = 0;
		memset(bit,0,sizeof(bit));
		for(int i=0;i<n;i++){
			cin>>temp;
			update(temp);
			inversions += (largeNumber(10000000)-largeNumber(temp));
		}
		cout<<inversions<<"\n";
	}
	
	return 0;
}