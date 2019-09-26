#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i = 1;i<=n;i++)

vector<pair<ll,ll> >adj[10000+5];
ll ans;
ll we[10000+5],taken[10000+5],par[1000],verteces;
priority_queue< pair<ll,ll>, vector <pair<ll,ll> > , greater<pair<ll,ll> > > pq;

void prims(ll source)
{
   //memset(par,-1,sizeof par);

   we[source] = 0;
   pq.push(make_pair(0,source));

   for(ll i=2;i<=verteces;i++)
    we[i] = INFINITY;

    for(ll i=1;i<=verteces;i++)
     taken[i] = 0;


   while(!pq.empty())
   {
     ll u = pq.top().second;

     if(taken[u]==1) { pq.pop(); continue; }

     ans = ans+pq.top().first;
     pq.pop();

     taken[u] = 1;

     for(ll i = 0;i<adj[u].size();i++)
     {
        ll v = adj[u][i].first;
        ll w = adj[u][i].second;

        if(taken[v]==0&&w<we[v])
        {
           pq.push(make_pair(w,v));
           we[v] = w;
          // par[v] = u;
        }
     }
   }

}
int main()
{
ll n,w,e;
cin>>n;
verteces = n;
ll a,b;
ans = 0;
cin>>e;
while(e--)
{
   cin>>a>>b>>w;
   adj[a].push_back(make_pair(b,w));
   adj[b].push_back(make_pair(a,w));
}

prims(1);

cout<<ans<<endl;

return 0;
}

/*
4 5
1 2 10
2 3 15
1 3 5
4 2 2
4 3 40

Ans: 17

*/
