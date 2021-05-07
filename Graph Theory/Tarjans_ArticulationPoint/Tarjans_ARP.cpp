#include <bits/stdc++.h>
using namespace std;
#define V 5
#define pb push_back

unordered_map<int,vector<int>>adj;

void dfs(int u,vector<int>& disc,vector<int>& low,vector<int>& parent,vector<bool>& articulation){
	static int time=0;
	low[u]=disc[u]=time;
	time+=1;
	int children=0;

	for(int v:adj[u]){
		if(disc[i]==-1){
			parent[v]=u;
			children+=1;
			dfs(v,disc,low,parent,articulation);

			low[u]=min(low[u],low[v]);

			if(parent[u]==-1 && children>=1) //Case 1: U is root
				articulation[u]=true;

			if(parent[u]!=-1 && low[v]>=disc[u]) //Case 2: At least one component will be separate
				articulation[u]=true;
		}
		else if(v!=parent[u]) //Ignore child to parent edge
			low[u]=min(low[u],disc[v]);

	}
}

void tarjanFindAPS(){
	vector<int> disc(V,-1),low(V,-1),parent(V,-1);
	vector<bool> articulation(V,false); // Avoids cross-edge

	for(int i=0;i<V;i++)
		if(adj[i]==-1)
			dfs(i,disc,low,parent,articulation);


	for(int i=0;i<V;i++)
		if(articulation[i]) 
			cout<< i << " ";

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

	tarjanFindAPS();
	return 0;
}

//Time Complexity O(V+E)