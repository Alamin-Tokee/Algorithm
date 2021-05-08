#include <bits/stdc++.h>
using namespace std;
#define V 5
#define pb push_back

unordered_map<int,vector<int>>mp;

void dfs(int u,vector<int>& vis){
	vis[u]=true;

	for(auto it:adj[u]){
		if(!vis[it])
			dfs(it,vis);
	}
}

bool ConnectedGraph(){
	vector<int> vis(V,false);
	int node=-1; //Node start dfs

	for(int i=0;i<V;i++)
		if(adj[i].size()>0){
			node=i; //Found a node to start dfs
			break;
		}

	if(node==-1) //No start node was found -> No edges are present in a graph
	     return true // Its always eulerian


	dfs(node,vis);
	//Check if all non zero vertices are visited
	for(int i=0; i<V; i++)
		if(vis[i]==false && adj[i].size()>0)
			return false; //We have a edge multicomponent

	return true;
}

void findEuler(){
	if(!ConnectedGraph()) //Multi-component edge graph
		return 0; //All non zero degree vertices should be connected

	//Count odd degree vertices
	int odd=0;
	for(int i=0;i<V;i++)
		if(adj[i].size()>0)
			odd++;

	if(odd>2) return 0; //Only start and end node can have odd degree

	return odd==0 ? 1 : 2; //1-> Eulerian ..2->Semi-Eulerian
}

void findEuler_Path_Cycle(){
	int res=findEuler();
	if(res==0) cout<<" Graph is not euler graph" <<'\n';
	else if(res==1) cout<< "Graph is euler graph" <<'\n';
	else cout<< "Graph is semi euler graph"<< '\n';
}

int main(){
	adj[0].pb(1);
	adj[1].pb(0);
	adj[0].pb(2);
	adj[2].pb(0);
	adj[2].pb(1);
	adj[1].pb(2);
	adj[0].pb(3);
	adj[3].pb(0);
	adj[3].pb(4);
	adj[4].pb(3);
	findEuler_Path_Cycle();

	return 0;
}

//Time Complexity O(V+E)