#include<queue>
#include<cstdio>
#include<cstring>
int n,m;
int g[210][210]={0};
int s,t;
struct Edge{
    int next,to,f;
}e[1000010]={0};
int cnt=2,head[1000010]={0};
void add(int u,int v,int f)
{
    e[cnt]={head[u],v,f};
    head[u]=cnt++;
    e[cnt]={head[v],u,0};
    head[v]=cnt++;
}

int dis[1000010]={0};
bool bfs()
{
    memset(dis,0,sizeof(dis));
    dis[s]=1;
    std::queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=head[u];i;i=e[i].next)
        {
            int v=e[i].to;
            if(!dis[v]&&e[i].f>0)
            {
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
    return dis[t]!=0;
}

int dfs(int u,int flow)
{
    if(u==t||flow==0) return flow;
    int flow_sum=0;
    for(int i=head[u];i;i=e[i].next)
    {
        int v=e[i].to,f=e[i].f;
        if(dis[v]!=dis[u]+1||f==0) continue;
        int temp=dfs(v,std::min(flow-flow_sum,f));
        e[i].f-=temp;
        e[i^1].f+=temp;
        flow_sum+=temp;
        if(flow_sum>=flow) break;
    }
    if(!flow_sum) dis[u]=-1;
    return flow_sum;
}

int dinic()
{
    int ans=0;
    while(bfs())
    {
        while(int temp=dfs(s,0x7fffffff))
            ans+=temp;
    }
    return ans;
}

inline int id(int x,int y)
{
    return (x-1)*n+y;
}

int main()
{
    scanf("%d%d",&n,&m);
    s=n*n+1,t=s+1;
    int ans=n*n-m;
    for(int i=1,x,y;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        g[x][y]=-1;//不可到
    }
    int bh[8][2]={{1,2},{2,1},{-2,1},{-1,2},{1,-2},{2,-1},{-1,-2},{-2,-1}};
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(g[i][j]==-1) continue;
            if((i+j)&1)
            {
                add(s,id(i,j),1);
                for(int k=0;k<8;k++)
                {
                    int ii=i+bh[k][0],jj=j+bh[k][1];
                    if(ii>0&&ii<=n&&jj>0&&jj<=n&&g[ii][jj]==0)
                        add(id(i,j),id(ii,jj),0x7fffffff);
                }
            }
            else
            {
                add(id(i,j),t,1);
            }
        }
    }
    printf("%d\n",ans-dinic());
    return 0;
}