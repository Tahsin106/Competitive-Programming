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
#define mx 100000

bool prime[mx] ;
ll spf[mx];

void seive(ll n)
{
  for(ll i = 1;i<=n;i++)
  spf[i] = i,prime[i] = true;

  for(ll i = 4;i<=n;i+=2)
  prime[i] = false,spf[i] = 2;

  for(ll i = 3;i*i<=n;i++)
  {
     if(prime[i])
     {
       for(ll j = i*i;j<=n;j+=(2*i))
       {
          prime[j] = false;
          if(spf[j]==j) spf[j] = i;
       }
     }
  }
  prime[1] = false;
}

vector<ll> fact(ll n)
{
   vector<ll>ans;

   while(n!=1)
   {
     ans.push_back(spf[n]);
     n = n/spf[n];
   }
   return ans;
}

int main()
{
seive(1000);

return 0;
}
