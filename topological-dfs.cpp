#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,vis[1000];
vector<ll>adj[1000];
stack<ll>s;

void dfs(ll u)
{
   vis[u] = 1;

   for(ll i = 0;i<adj[u].size();i++)
   {
      if(vis[adj[u][i]]==0) dfs(adj[u][i]);
   }

   vis[u] = 2;
   s.push(u);
}
int main()
{
ll e,a,b;

cin>>n;
cin>>e;

memset(vis,0,sizeof vis);

while(e--)
{
   cin>>a>>b;
   adj[a].push_back(b);
}

for(ll i=0;i<=n;i++)
if(!vis[i]) dfs(i);

cout<<"Topological Order: "<<endl;

while(!s.empty())
{
   cout<<s.top()<<endl;
   s.pop();
}

return 0;
}
