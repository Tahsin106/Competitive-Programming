#include<bits/stdc++.h>
using namespace std;
typedef int ll;
#define sf(n) scanf("%lld",&n)
#define sff(n,m) scanf("%lld %lld",&n,&m)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PLL pair<ll,ll>
#define mod 1000000007
#define mx 500003
#define FILE freopen("input.txt","r",stdin)

vector<PLL>adj[mx];
vector<ll>tree[mx];

bool isbridge[mx];
int visited[mx];
int arr[mx],T;
int cmpno;
queue<int>Q[mx];
ll mp[mx];
ll ma,id;

int dfs0(int u,int edge)
{
    visited[u]=1;
    arr[u]=T++;
    int dbe = arr[u];

    for(int i=0;i<adj[u].size();i++)
    {
        int e = adj[u][i].second;
        int w = adj[u][i].first;

        if(!visited[w])
            dbe = min(dbe,dfs0(w,e));
        else if(e!=edge)
            dbe = min(dbe,arr[w]);
    }

    if(dbe == arr[u] && edge!=-1)
          isbridge[edge]=true;

    return dbe;
}

void dfs1(int v)
{
    int currcmp = cmpno;
    Q[currcmp].push(v);
    visited[v] = 1;

    while(!Q[currcmp].empty())
    {
        int u = Q[currcmp].front();
        Q[currcmp].pop();

        for(int i=0;i<adj[u].size();i++)
        {
            int e = adj[u][i].second;
            int w = adj[u][i].first;
            if(visited[w])continue;

            if(isbridge[e])
            {
                cmpno++;
                tree[currcmp].push_back(cmpno);
                tree[cmpno].push_back(currcmp);
                dfs1(w);
            }
            else
            {
                Q[currcmp].push(w);
                visited[w]=1;
            }
        }
    }


}


int main()
{
ll n,m,x,y;
T = 1,cmpno = 1;
scanf("%d %d",&n,&m);

for(ll i = 1;i<=m;i++)
{
  scanf("%d %d",&x,&y);
  adj[x].push_back({y,i});
  adj[y].push_back({x,i});
}

for(ll i = 1;i<=n;i++)
{
  if(!visited[i]){
     dfs0(i,-1);
  }
}

memset(visited,0,sizeof visited);

for(ll i = 1;i<=n;i++)
{
  if(!visited[i]){
     ma = 0;
     dfs1(i);
  }
}


return 0;
}
