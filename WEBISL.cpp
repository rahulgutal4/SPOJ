#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> *graph,*graphT,*component;
stack<int> myStack;
bool *visited;
int *minIndex;

void DFS(int i){

	visited[i] = true;
	
	for(int j=0;j<graph[i].size();j++){
		
		if(!visited[graph[i][j]]) DFS(graph[i][j]);
		
	}
	
	myStack.push(i);
}	

void DFST(int i,int count){

	visited[i] = false;
	component[count].push_back(i);
	
	for(int j=0;j<graphT[i].size();j++){
		
		if(visited[graphT[i][j]]) DFST(graphT[i][j],count);
		
	}
	
}	


int main() {
	
	int noOfPages,noOfLinks,i,j;
	scanf("%d%d",&noOfPages,&noOfLinks);
	
	graph = new vector<int>[noOfPages];
	graphT = new vector<int>[noOfPages];
	component = new vector<int>[noOfPages];
	visited = new bool[noOfPages];
	minIndex = new int[noOfPages];
	
	for( i=0;i<noOfPages;i++){
		
		graph[i].clear();
		graphT[i].clear();
		visited[i] = false;
		minIndex[i] = -1;
		
	}
	
	int source,destination;
	for( i=0;i<noOfLinks;i++){
		
		scanf("%d%d",&source,&destination);
		graph[source].push_back(destination);
		graphT[destination].push_back(source);
		
	}
	
	for( i=0;i<noOfPages;i++){
		
		if(!visited[i]) DFS(i);
		
	}
	
	int top,count=0;
	while(!myStack.empty()){
		
		top = myStack.top();
		myStack.pop();
		
		if(visited[top]) DFST(top,count++);
		
	}
	
	int min;
	for( i=0;i<count;i++){
		
		min = 999999;
		for( j=0;j<component[i].size();j++){
			
			if(min>component[i][j]) min = component[i][j];
			
		}
		
		for( j=0;j<component[i].size();j++){
			
			minIndex[component[i][j]] = min;
			
		}
		
	}
	
	for( i=0;i<noOfPages;i++) printf("%d\n",minIndex[i]);
	
	return 0;
}
