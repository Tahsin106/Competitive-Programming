#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sf(n) scanf("%lld",&n)
#define sff(n,m) scanf("%lld %lld",&n,&m)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PLL pair<long double,long double>
#define mod 1000000007
#define mx 100005

vector<pair<ll,ll> >adj[mx];
ll ans,n;
ll d[mx],vis[mx];
priority_queue< pair<ll,ll>, vector <pair<ll,ll> > , greater<pair<ll,ll> > > pq;

void dijkstra(ll source)
{
   ll i;

   for(i=0;i<=n;i++)
    d[i] = INFINITY;

   d[source] = 0;
   pq.push(make_pair(0,source));

   while(!pq.empty())
   {
      ll u = pq.top().second;
      pq.pop();

      if(vis[u]) continue;

      vis[u] = 1;

      for(i=0;i<adj[u].size();i++)
      {
         ll v = adj[u][i].first;
         ll w = adj[u][i].second;

         if(d[u]+w<d[v])
         {
            d[v] = d[u]+w;
            pq.push(make_pair(d[v],v));
         }
      }
   }

}
int main()
{
//freopen("input.txt","r",stdin);
ll w,a,b,m;

cin>>n>>m;

for(ll i = 1;i<=m;i++)
{
   cin>>a>>b>>w;
   adj[a].push_back(make_pair(b,w));
   adj[b].push_back(make_pair(a,w));
}

memset(vis,0,sizeof vis);

dijkstra(1);

for(ll i=1;i<=n;i++)
cout<<d[i]<<" ";

return 0;
}
