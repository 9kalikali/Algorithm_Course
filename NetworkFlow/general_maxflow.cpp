#include <iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include <vector>
#include <queue>

using namespace std;
const long maxn= 1200;
const long INF= 2147483647;
struct Edge{
    long from,to,cap,flow;
};
struct Dinic{
    long n,m,s,t;
    vector<Edge>edges;
    vector<long>G[maxn];
    bool vis[maxn];
    long d[maxn];
    long cur[maxn];
    void AddEdge(long from,long to,long cap){
        edges.push_back((Edge){from,to,cap,0});
        edges.push_back((Edge){to,from,0,0});
        m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }
    bool BFS(){
        long x,i;
        memset(vis,0,sizeof(vis));
        queue<long>Q;
        Q.push(s);
        d[s]=0;
        vis[s]=1;
        while(!Q.empty()){
            x=Q.front(),Q.pop();
            for(i=0;i<G[x].size();i++){
                Edge & e =edges[G[x][i]];
                if(!vis[e.to]&&e.cap>e.flow){
                    vis[e.to]=1;
                    d[e.to]=d[x]+1;
                    Q.push(e.to);
                }
            }
        }
        return vis[t];
    }
    long DFS(long x,long a){
        if(x==t||a==0)
            return a;
        long flow=0,f;
        for(long &i=cur[x];i<G[x].size();i++){
            Edge & e=edges[G[x][i]];
            if(d[x]+1==d[e.to]&&(f=DFS(e.to,min(a,e.cap-e.flow)))>0){
                e.flow+=f;
                edges[G[x][i]^1].flow-=f;
                flow+=f;
                a-=f;
                if(a==0)
                    break;
            }
        }
        return flow;
    }
    long Maxflow(long s,long t){
        this->s=s,this->t=t;
        long flow=0;
        while(BFS()){
            memset(cur,0,sizeof(cur));
            flow+= DFS(s,INF);
        }
        return flow;
    }
};
int main()
{
    long n,m,ss,tt,i,j,k,a,b,c,res, s, t;  
    //n表示n+1个点，源点0，汇点n。m条边（弧），a，b，c分别表示弧尾，弧头，权值（容量）。
    //求最大流。
    cin >> n >> m >> s >> t;
    Dinic tmp;
    for(i=0;i<m;i++){
        cin >> a >> b >> c;
        tmp.AddEdge(a, b, c);
    }
    cout << tmp.Maxflow(s,t) << endl;
    return 0;
}