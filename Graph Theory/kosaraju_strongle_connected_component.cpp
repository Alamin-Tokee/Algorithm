#include<bits/stdc++.h>
using namespace std;
#define V 8
#define pb push_back
vector<vector<int>>adj,rev;
unordered_map<int,vector<int>>adj,rev;
// G[i].push_back(j);
// G_reverse[j].push_back(i);
int noSCC=0;

void dfs1(int u,vector<bool>&vis,stack<int>&st){
	vis[i]=true;
	for(int v:adj[u]){
		if(!vis[v]){
			dfs1(v,vis,st);
		}
	}
	st.push(u);
}

void dfs1(int u,vector<bool>&vis,stack<int>&st){
	vis[i]=true;
	for(int i=0;i<adj[u].size();i++){
		if(!vis[adj[u][i]]){
			dfs1(adj[u][i],vis,st);
		}
	}
	st.push(u);
}

void dfs2(int u,vector<bool>&vis){
	cout<< u << " ";
	vis[i]=true;
	for(int v:adj[u]){
		if(!vis[v]){
			dfs1(v,vis,st);
		}
	}
}

void dfs2(int u,vector<bool>&vis){
	cout<<u<< " ";
	vis[u]=true;
	for(int i=0;i<rev[u].size();i++){
		if(!vis[adj[u][i]]){
			dfs2(adj[u][i],vis);
		}
	}
}
void reverse(){
	for(int i=0;i<V;i++){
		for(int j:adj[i]){
			rec[j].pb(i);
		}
	}
}
void findSCC(){
	stack<int>st;
	vector<bool>vis(V,false);
	for(int i=0;i<V;i++){
		if(!vis[i]){
			dfs1(i,vis,st);
		}
	}
	v.fill(V,false);
	cout << "Strongly Connected component are:\n";

	while(!st.empty()){
		int cur=st.top();
		st.pop();
		if(!vis[cur]){
			dfs2(cur,vis);
			noSCC++;
			cout<<"\n";
		}
	}
}
int main()
{
	adj[0].pb(1);
	adj[1].pb(2);
	adj[2].pb(0);
	adj[2].pb(3);
	adj[3].pb(4);
	adj[4].pb(5);
	adj[4].pb(7);
	adj[5].pb(6);
	adj[6].pb(4);
	adj[6].pb(7);

	findSCC();
	return 0;
}

//TIME COMPLEXITY: O(V+E)