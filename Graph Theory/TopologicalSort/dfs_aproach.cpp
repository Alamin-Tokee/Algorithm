#include <bits/stdc++.h>
using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2

int adj[100][100];
int color[100];
int startTime[100];
int finishTime[100];
stack<int>st;
int time=0;
int node,edge;

void dfsVisit(int u){
	startTime[u]=time++;
	color[u]=GRAY;
	for(int i=0;i<node;i++){
		if(adj[u][i]==1){
			if(color[i]==WHITE){
				dfsVisit(i);
			}
		}
	}
	color[u]=BLACK;
	finishTime[u]=time++;
	st.push(u);
}

void dfs(){
	for(int i=0;i<node;i++){
		color[i]=WHITE;
	}
	for(int i=0;i<node;i++){
		if(color[i]==WHITE){
			dfsVisit(i);
		}
	}
}

int main(){
	freopen("input","r",stdin);
	scanf("%d %d",&node,&edge);

	int n1,n2;
	for(int i=0;i<edge;i++){
		cin>>n1>>n2;
		adj[n1][n2];
		adj[n2][n1];
	}

	dfs();

	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}
	return 0;
}