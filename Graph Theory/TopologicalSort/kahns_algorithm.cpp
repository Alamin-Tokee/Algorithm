#include <bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	list<int>* adj;

public:
	Graph(int V);
	void addEdge(int u,int v);
	void topologicalSort();
};

void Graph:Graph(int V){
	this->V=V;
	adj=new list<int>[V];
}

void Graph:addEdge(int u,int v){
	adj[u].push_back(v);
}

void Graph:topologicalSort(){
	vector<int>in_degree(V,0);

	for(int u=0;u<V;u++){
		list<int>::iterator it;
		for(it=adj[u].begin();it!=adj[u].end();it++){
			in_degree[*it]++;
		}
	}
	queue<int>q;
	for(int i=0;i<V;i++){
		if(in_degree[i]==0)
			q.push(i);
	}

	int cnt;
	vector<int>top_order;

	while(!q.empty()){
		auto u=q.front();
		q.pop();
		top_order.push_back(u);

		list<int>::iterator it;
		for(it=adj[u].begin();it!=adj[u].end();it++){
			if(--in_degree[*it]==0)
				q.push(*it);
		}
		cnt++;
	}
	if(cnt!=V){
		cout<<"There exits a cycle in the graph";
		return;
	}
	for(int i=0;i<top_order.size();i++)
		cout<<top_order[i]<< ' ';
	cout<<endl
}

int main(){
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
  
    cout << "Following is a Topological Sort of\n";
    g.topologicalSort();
  
    return 0;
}