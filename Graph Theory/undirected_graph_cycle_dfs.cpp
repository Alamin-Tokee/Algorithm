//Using Graph Coloring To Solve The Undirected Graph Cycle
#include <bits/stdc++.h>
using namespace std;

bool cycleUtill(int u,vector<bool>& vis,vector<int>adj[]){
	if(vis[u]==2)
		return true;

	bool flag=false;
	vis[u]=1;
	for(int i=0;i<adj[u].size();i++){
		if(vis[i]==1) vis[i]=2;

		flag=cycleUtill(adj[u][i],vis,adj);
		if(flag) return true;
	}
	vis[i]=0;
	
	return false;
}

bool isCycle(int V,vector<int>adj[]){
	vector<int>vis(V,0);

	bool flag=false;
	for(int i=0;i<V;i++){
		vis[i]=1;
		for(int j=0;j<adj[i].size();i++){
			flag=cycleUtill(adj[i][j],vis,adj);
			if(flag) return true;
		}
		vis[i]=0;
	}
	return false;
}
int main(){
    int V,E;
	cin>>V>>E;
	vector<int>adj[V];

	for(int i=0;i<E;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	if(isCycle(V,adj)) cout << "Cycle found";
	else cout<< "Cycle not found";

	return 0;
}