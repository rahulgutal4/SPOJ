#include <iostream>
using namespace std;

int **matrix;

int count(int n,int k){
	
	if(matrix[n][k] != -1)
		return matrix[n][k];
	
	if(n == 0)
		return 0;
	if(k == 0)
		return 1;
	
	int val = 0;
	for(int i = 0; i < n && k-i >= 0; i++)
		val += count(n-1,k-i);
	return (matrix[n][k] = val);
}	

int main() {
	
	int testCases,number,inversion;
	scanf("%d",&testCases);
	
	while(testCases--){
		
		scanf("%d%d",&number,&inversion);
		
		matrix = new int*[number+1];
		for(int i=0;i<=number;i++){
			
			matrix[i] = new int[inversion+1];
			
		}
		
		for(int i=1;i<=number;i++){
			
			for(int j=0;j<=inversion;j++){
				
				matrix[i][j] = -1;
			
			}
		}
		
		printf("%d\n",count(number,inversion));
	
	}
	
	return 0;
}
