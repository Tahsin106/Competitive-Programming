#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>adj[100005];
bool vis[100005];
vector<double>v;

ll fun(ll s)
{
  ll cnt = 0;
  for(ll i=0;i<adj[s].size();i++)
  {
      if(!vis[adj[s][i]]) cnt++;
  }

  return cnt;
}

bool test(ll s)
{
  for(ll i=0;i<adj[s].size();i++)
  {
      if(!vis[adj[s][i]]) return false;
  }

  return true;
}

void dfs(ll s,ll d,double p)
{
  vis[s] = true;
  ll i;

  if(test(s)) v.push_back((double)p*d);

  double prob = (double)1/fun(s);

  for(i=0;i<adj[s].size();i++)
  {
      if(!vis[adj[s][i]]) dfs(adj[s][i],d+1,p*prob);
  }

}

int main()
{

   ll n,i,a,b;
    cin>>n;

  memset(vis,false,sizeof(vis));

   for(i=1;i<=n-1;i++)
   {
       cin>>a>>b;
       adj[a].push_back(b);
       adj[b].push_back(a);
   }

   dfs(1,0,1);

   double ans = 0;

   for(i=0;i<v.size();i++)
   {
      ans+=v[i];
   }

   printf("%lf\n",ans);

return 0;
}
