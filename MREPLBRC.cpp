#include <iostream>
#include <cstring>
using namespace std;
#define MOD 100000
typedef long long ll;

ll len,dp1[205][205],ways=0;
char str[205];

ll noOfWays(int a , int b){

	if(str[a] == str[b] && str[a] == '?') return 3;
	
	if((str[a]=='(' || str[a]=='{' || str[a]=='[')&&str[b]=='?') return 1;
	
	if((str[b]==')' || str[b]=='}' || str[b]==']')&&str[a]=='?') return 1;
	
	if(str[a]=='(' && str[b]==')') return 1;
	if(str[a]=='{' && str[b]=='}') return 1;
	if(str[a]=='[' && str[b]==']') return 1;
	
	return 0;
}	

ll dp(int start, int end) {
	
    if (start > end)
        return 1;
    else if (dp1[start][end] != -1)
        return dp1[start][end];
    ll res = 0;
    for (int k = start + 1; k <= end; k++) {
        res += noOfWays(start, k) * dp(start + 1, k - 1) * dp(k + 1, end);
      /*	if(res > 100000){
      		res = res%100000;
      	}*/
      	res = res % MOD + ((res >= MOD) ? MOD : 0);
    }
    return dp1[start][end] = res;
    
}

int main() {
	char out[7];
	scanf("%d", &len);
	scanf("%s", str);
	for (int i = 0; i < len; i++)
		for (int j = 0; j < len; j++)
			dp1[i][j] = -1;
	out[6] = 0;
	int top = 5;
	ll result = dp(0, len - 1);
	do {
		out[top--] = result % 10 + '0';
		result /= 10;
	} while (result > 0);
	top++;
	while (top < 1)
		top++;
	puts(out + top);
	return 0;
}