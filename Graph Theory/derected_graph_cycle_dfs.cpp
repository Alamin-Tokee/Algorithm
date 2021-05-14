#include <bits/stdc++.h>
using namespace std;

bool cycleUtill(int u,vector<bool>& vis,vector<int>adj[]){
	if(vis[u]==true)
		return true;

	bool flag=false;
	vis[u]=true;
	for(int i=0;i<adj[u].size();i++){
		flag=cycleUtill(adj[u][i],vis,adj);
		if(flag) return true;
	}
	vis[i]=false;
	
	return false;
}

bool isCycle(int V,vector<int>adj[]){
	vector<bool>vis(V,false);

	bool flag=false;
	for(int i=0;i<V;i++){
		vis[i]=true;
		for(int j=0;j<adj[i].size();i++){
			flag=cycleUtill(adj[i][j],vis,adj);
			if(flag) return true;
		}
		vis[i]=false;
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