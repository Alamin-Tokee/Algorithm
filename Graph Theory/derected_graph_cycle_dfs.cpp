#include <bits/stdc++.h>
using namespace std;

bool cycleUtill(int u,vector<bool>& vis){
	if(vis[i]==true)
		return true;

	for(int i=0;i<adj[u].size();i++){
		int flag=cycleUtill(adj[u][i],vis);
		if(flag) return true;
	}
	vis[i]=false;
	
	return false;
}

bool isCycle(){
	vector<int>vis(V,false);

	for(int i=0;i<V;i++){
		for(int j=0;j<adj[i].size();i++){
			int flag=cycleUtill(adj[i][j],vis);
			if(flag) return true;
		}
	}
	return false;
}
int main(){

}