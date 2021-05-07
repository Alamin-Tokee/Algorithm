#include <bits/stdc++.h>
using namespace std;
#define V 5
#define pb push_back

unordered_map<int,vector<int>>adj;

void dfs(int u,vector<int>& vis){
	int children=0;
	vis[u]=true;

	for(int v:adj[u]){
		if(vis[v]==false){
			children+=1;
			dfs(v,vis);
		}
		else if(vis[v]){
			if(children>=1) 
				value.pb(v);
		}
	}
}

void dfsArticulation(){

	vector<int> vis(V,false),value(V,-1);

	for(int i=0;i<V;i++)
		if(vis[i])
			dfs(i,vis);
}

int main(){
	adj[0].pb(2);
	adj[2].pb(0);
	adj[0].pb(3);
	adj[3].pb(0);
	adj[1].pb(0);
	adj[0].pb(1);
	adj[2].pb(1);
	//adj[2].pb(4);
	//adj[4].pb(2);
	adj[1].pb(2);
	adj[3].pb(4);
	adj[4].pb(3);

	dfsArticulation();
	return 0;
}

//Time Complexity O(V*(V+E))