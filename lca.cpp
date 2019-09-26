#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,n) for(ll i = 1;i<=n;i++)
#define rep0(i,n) for(ll i = 0;i<n;i++)
#define reps(i,a,n) for(ll i = a;i<=n;i++)
#define sf(n) scanf("%lld",&n)
#define sff(n,m) scanf("%lld %lld",&n,&m)
#define pf(n) printf("%lld\n",n)
#define pfs(s) printf("%s\n",s)
#define bug printf("%BUG\n")
#define pfstr(s) printf("%s\n",s.c_str())
#define cs(i,n) printf("Case %lld: %lld\n",i,n)
#define clr(dp,v) memset(dp,v,sizeof dp)
#define pb push_back
#define mp make_pair
#define PLL pair<ll,ll>
#define ff first
#define ss second
#define mx 100002

ll L[mx];
ll P[mx][22];
ll T[mx],vis[mx];
vector<ll>adj[mx];
ll n;

void dfs(ll from,ll source,ll level)
{
  vis[source] = 1;
  L[source] = level;
  T[source] = from;

  for(ll i = 0;i<adj[source].size();i++)
  {
     if(!vis[adj[source][i]]) dfs(source,adj[source][i],level+1);
  }
}

void lca_init()
{
   clr(P,-1);
   ll i,j;

   for(i = 0;i<n;i++)
    P[i][0] = T[i];

   for(j = 1;(1<<j)<n;j++)
   for(i = 0;i<n;i++)
   {
      if(P[i][j-1]!=-1) P[i][j] = P[P[i][j-1]][j-1];
   }
}

ll lca(ll p,ll q)
{
   if(L[p]<L[q]) swap(p,q);

   ll log=1;
   while(1)
   {
     ll next = log+1;
     if((1<<next)>L[p]) break;
      log++;
   }

   ll i,j;

   for(i = log;i>=0;i--)
   {
     if(L[p]-(1<<i)>=L[q])
       p = P[p][i];
   }
   if(p==q) return p;

   for(i = log;i>=0;i--)
   {
      if(P[p][i]!=-1&&P[p][i]!=P[q][i])
      p = P[p][i], q = P[q][i];
   }

   return T[p];
}

int main()
{
clr(vis,0);

ll m,a,b;

sff(n,m);

while(m--)
{
  cin>>a>>b;
  adj[a].pb(b);
}

dfs(0,0,0);
lca_init();
cout<<lca(2,4);

return 0;
}
