#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;

#define WHITE 1
#define GRAY 2
#define BLACK 3

int adj[100][100];
int color[100];
int parent[100];
int dis[100];

int node,edge;

void bfs(int startingNode){
    for(int i=0;i<node;i++){
        color[i]=WHITE;
        dis[i]=INT_MIN;
        parent[i]=-1;
    }
    dis[startingNode]=0;
    parent[startingNode]=-1;

    queue<int>q;
    q.push(startingNode);
    while(q.empty()){
        int x=q.front();
        q.pop();
        color[x]=GRAY;
        printf("%d", x);
        for(int i=0;i<node;i++){
            if(adj[x][i]==1){
                if(color[i]==WHITE){
                    //x er neighber i
                    //x node ta hocche i number node er parent
                    dis[i]=dis[i]+1;
                    parent[i]=x;
                    q.push(i);
                }
            }
        }
        color[x]=BLACK;
    }
}

int main(){
    freopen("input","r",stdin);
    scanf("%d %d",&node,&edge);

    int n1,n2;
    for(int i=0;i<edge;i++){
        scanf("%d %d",&n1,&n2);
        adj[n1][n2]=1;
        adj[n2][n1]=1;
    }
    bfs(0);
    printf("\n%d",parent[5]);
    printf("\n%d",dis[6]);
}
