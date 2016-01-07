#include <iostream>
#include <stack>
using namespace std;
typedef long long unsigned int ll;

ll max_Area(int arr[100005],int MAX){

	int i = 0;
	ll maxArea = 0,area = 0;
	stack<int> s;
	while(i < MAX){
		
		if(s.empty() || arr[i] >= arr[s.top()]){
			s.push(i);
			i++;
		}else{
			
			int top = s.top();
			s.pop();
			int bars = 0;
			if(s.empty()){
				bars = i;
			}else{
				bars = i - s.top() - 1;
			}
			
			ll area = (ll)arr[top]*bars;
	//		cout<<arr[top]<<" "<<bars<<" "<<(long)arr[top]*bars<<"\n";
			if(maxArea < area){
				maxArea = area;
			}
		}
		
	}
	
	while(!s.empty()){
		
		int top = s.top();
		s.pop();
		int bars = 0;
		if(s.empty()){
			bars = i;
		}else{
			bars = i - s.top() - 1;
		}
			
		ll area = (ll)arr[top]*bars;
	//	cout<<arr[top]<<" "<<bars<<" "<<(long long unsigned int)arr[top]*bars<<"\n";
		if(maxArea < area){
			maxArea = area;
		}
		
	}
	
	return maxArea;
}	

int main() {

	int n,arr[100005];
	while(true){
		
		cin>>n;
		if(!n) break;
		
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		cout<<max_Area(arr,n)<<"\n";
	}
	
	return 0;
}