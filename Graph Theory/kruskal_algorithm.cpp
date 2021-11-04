#include <bits/stdc++.h>
 
#define MAXN 100000
 
using namespace std;
 
struct edge
{
    int u,v,w;
    bool operator < ( const edge& p ) const
    {
        return w < p.w;
    }
};
 
int pr[MAXN];
vector<edge>e;
 
int find(int r)
{
    return pr[r]= (pr[r]==r) ? r:  find(pr[r]);
}
 
int mst(int n)
{
    sort(e.begin(),e.end());
    for(int i=1; i<=n; i++)pr[i]=i;
 
    int count=0,s=0;
    for(int i=0; i<(int)e.size(); i++)
    {
        int u=find(e[i].u);
        int v=find(e[i].v);
        if(u!=v)
        {
            pr[u]=v;
            count++;
            s+=e[i].w;
            if(count==n-1) break;
        }
    }
    return s;
}
 
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edge get;
        get.u=u;
        get.v=v;
        get.w=w;
        e.push_back(get);
    }
    cout<<mst(n)<<endl;
    return 0;
}

//Time Complexity ElogE// When edge is minimum then it work well.
// If edge is high like dense graph then prims algorithm work well
