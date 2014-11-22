#include <iostream>
#include <cmath>
//#include <cstdio>
using namespace std;

struct entry{
	
	int sum,min;
		
}*M;	

int length,b;
char *bracket;

void initialise(int node,int b,int e){

	if(b == e){
		
		M[node].sum = M[node].min = (bracket[b] == '('?1:-1);
		return;
		
	}else{
	
		int m = (b+e)/2;
		initialise(2*node,b,m);
		initialise(2*node+1,m+1,e);
		
		M[node].sum = M[2*node].sum + M[2*node+1].sum;
		
		M[node].min = min(M[2*node].min,M[2*node].sum+M[2*node+1].min);
	}
	
}

void update(int node,int start,int end,int index){
	
	if(start == end){
		
		M[node].sum = M[node].min = -M[node].sum;
		return;
		
	}
	
	int mid = (start+end)/2;
	
	if(index<=mid) update(2*node,start,mid,index);
	else update(2*node+1,mid+1,end,index);
	
	M[node].sum = M[2*node].sum + M[2*node+1].sum;
	M[node].min = min(M[2*node].min,M[2*node].sum+M[2*node+1].min);
}

int main() {
	
	int testCases = 1;
	
	while(scanf("%d", &length)==1){
		
		printf("Test %d:\n",testCases++);
		scanf("%d",&length);
		int a = ceil(log2(length));
		a++;
		 b = pow(2,a);
		b--;
		
		bracket = new char[length];
		M = new struct entry[b+1];
		scanf("%s",bracket);
	
		//for(int i=1;i<=length;i++) cout<<bracket[i]<<" ";
		initialise(1,0,length-1);
		
		//for(int i=1;i<=b;i++) cout<<M[i].sum<<" "<<M[i].min<<"\n";
		
		int operations=0;
		scanf("%d",&operations);
		
		int oper=-1;
		for(int i=0;i<operations;i++){
			
			scanf("%d",&oper);
			
			if(oper == 0){
				
				if(M[1].sum==0 && M[1].min==0) printf("YES\n");
				else printf("NO\n");
				
			}else{
				
				update(1,0,length-1,oper-1);
				
			}
				
		}
		
		
	}
	return 0;
}

