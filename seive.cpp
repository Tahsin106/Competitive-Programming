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
#define mx 100000

bool prime[mx];
set<ll>p;

ll seive(ll n)
{
  clr(prime,true);

  prime[1] = false;

  for(ll i = 4;i<=n;i+=2) prime[i] = false;

  for(ll i = 3;i*i<=n;i++)
  {
    if(prime[i]){
     for(ll j = i*i;j<=n;j+=(2*i)) prime[j] = false;
    }
  }

  for(ll i = 2;i<=n;i++) if(prime[i]) p.insert(i);
}

bool prime_check(ll n)
{
  if(n==1) return false;

  for(ll i = 2;i*i<=n;i++)
  {
    if(n%i==0) return false;
  }
  return true;
}

int main()
{
string s = "baa";s.erase(2);
cout<<s<<endl;

for(ll i = 100000;i<=(100000+1000);i++)
{
  if(prime_check(i)) cout<<i<<endl;
}

return 0;
}
