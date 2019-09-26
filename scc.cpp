#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,vis[1000];
vector<ll>adj[1000],radj[1000];
stack<ll>s;

void dfs(ll u)
{
   vis[u] = 1;


   for(ll i = 0;i<adj[u].size();i++)
   {
      if(vis[adj[u][i]]==0) dfs(adj[u][i]);
   }

   s.push(u);
}

void dfs1(ll u)
{
   cout<<u<<" ";
   vis[u] = 1;

   for(ll i = 0;i<radj[u].size();i++)
   {
      if(vis[radj[u][i]]==0) dfs1(radj[u][i]);
   }

}
int main()
{
ll e,a,b,u;

cin>>n;
cin>>e;

memset(vis,0,sizeof vis);

while(e--)
{
   cin>>a>>b;
   adj[a].push_back(b);
   radj[b].push_back(a);
}

for(ll i=1;i<=n;i++)
if(!vis[i]) dfs(i);

memset(vis,0,sizeof vis);

ll ans = 0;

while(!s.empty())
{
   u = s.top();
   if(!vis[u])
   {
      dfs1(u);
      ans++;
   }
   cout<<endl;
   s.pop();
}

cout<<ans<<endl;

return 0;
}
