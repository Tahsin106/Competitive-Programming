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
#define mpr make_pair
#define PLL pair<ll,ll>
#define ff first
#define ss second
#define mx 100005

struct edges{
  ll a,b,w;

  edges(ll s,ll e,ll p)
  {
      a = s;
      b = e;
      w = p;
  }
};
vector<edges>vec;

ll d[10000+5],verteces;

void relax(ll u,ll v,ll w)
{
   if(d[u]+w<d[v]) d[v] = d[u]+w;
}

void bellman(ll source)
{
   ll i,j;

   for(i=1;i<=verteces;i++)
    d[i] = INFINITY;

   d[source] = 0;

   for(j=1;j<verteces;j++)
   {
       for(i=0;i<vec.size();i++)
       {
          edges nd = vec[i];
          relax(nd.a,nd.b,nd.w);
       }
   }
}

int main()
{
ll n,w,e;
cin>>n;
verteces = n;
ll a,b;

cin>>e;

while(e--)
{
   cin>>a>>b>>w;
   vec.push_back(edges(a,b,w));
}
bellman(1);

for(ll i=2;i<=verteces;i++)
cout<<d[i]<<" ";

return 0;
}

/*
5 5
1 2 5
1 3 2
3 4 1
1 4 6
3 5 5

ans: 5 2 3 7

*/
