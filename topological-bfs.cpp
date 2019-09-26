#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
ll e,a,b,n,i;

cin>>n;
cin>>e;

vector<ll>adj[n+5];

ll indeg[n+5];

for(i=1;i<=n;i++)
indeg[i] = 0;

while(e--)
{
   cin>>a>>b;
   adj[a].push_back(b);
   indeg[b]++;
}

priority_queue<ll,vector<ll>,greater<ll> >q;

for(i=1;i<=n;i++)
if(indeg[i]==0) q.push(i);

ll ans[n+3];
ll cnt = 1;

while(!q.empty())
{
   ll u = q.top();
   q.pop();
   //cout<<u<<" ";
   ans[u] = cnt++;

  for(i = 0;i<adj[u].size();i++)
   {
       ll v  = adj[u][i];
       indeg[v]--;
       if(indeg[v]==0) q.push(v);
   }
}

for(i=1;i<=n;i++)
{
  cout<<ans[i]<<" ";
}

return 0;
}
