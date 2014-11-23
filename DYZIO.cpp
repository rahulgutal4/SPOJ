#include <iostream>
#include <cmath>
using namespace std;

char *sequence;
int count=0,deepest=-1,ans=0,pos=0;

void visit(int depth){

	if(depth > deepest){
		deepest = depth;
		ans = count;
	}

	
	if(sequence[pos++] == '1'){
		
		count++;
		
		visit(depth+1);
		visit(depth+1);
	}else{
		return;
	}

}	

int main() {
	
	int length;
	while(scanf("%d",&length) == 1){
		
		count = 0;
		ans = 0;
		deepest = -1;
		pos = 0;
		sequence = new char[length];
		scanf("%s",sequence);
		
		visit(0);
		
		printf("%d\n",ans);
		
	}
	
	return 0;
}
