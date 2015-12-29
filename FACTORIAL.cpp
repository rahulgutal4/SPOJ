#include <iostream>
#include <cmath>
using namespace std;

int main() {
	// your code goes here
	int cnt,u;
	long unsigned int t;
	long long unsigned int n,fact,i;
	cin>>t;
	while(t)
	{
		cin>>n;
		i=1;
		cnt=0;
		while(1)
		{
			fact=pow(5,i);
			if(fact>n) break;
			cnt+=n/pow(5,i);
			i++;
		}
		cout<<cnt<<"\n";
		t--;
	}
	return 0;
}