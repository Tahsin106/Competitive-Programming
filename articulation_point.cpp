#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sf(n) scanf("%lld",&n)
#define sff(n,m) scanf("%lld %lld",&n,&m)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PLL pair<ll,ll>
#define mod 1000000007
#define mx 200003

ll t;
vector<ll>adj[mx];
ll vis[mx],disc[mx],low[mx],par[mx];
set<ll>ans;

void dfs(ll u)
{
    ll children = 0;
    vis[u] = 1;
    disc[u] = low[u] = ++t;

    for(ll v:adj[u])
    {
      if(!vis[v])
      {
        children++;
        par[v] = u;
        dfs(v);
        low[u]  = min(low[u],low[v]);

        if((par[u]==-1)&&(children>1)) { ans.insert(u); }
        else if((par[u]!=-1)&&(low[v]>=disc[u])) { ans.insert(u); }
      }
      else if(v!=par[u]) low[u] = min(low[u], disc[v]);
    }
}

int main()
{
ll n,m,x,y;

while(sff(n,m)!=EOF)
{
  if(n==0&&m==0) break;

  for(ll i = 1;i<=m;i++)
  {
    sff(x,y);
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  memset(vis,0,sizeof vis);
  memset(par,-1,sizeof par);

  t = 0;

  dfs(1);

  printf("%lld\n",(ll)ans.size());

  for(ll i = 1;i<=n;i++) adj[i].clear();
  ans.clear();
}

return 0;
}
