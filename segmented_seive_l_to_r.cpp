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

vector<ll> seive(ll n)
{
  bool prime[n];
  vector<ll>primes;
  clr(prime,true);

  for(ll i = 4;i<=n;i+=2)
   prime[i] = false;

  for(ll i = 3;i*i<=n;i++)
  {
     if(prime[i])
     {
       for(ll j = i*i;j<=n;j+=(2*i))
       {
          prime[j] = false;
       }
     }
  }
  prime[1] = false;

  for(ll i = 2;i<n;i++)
  {
     if(prime[i]) { primes.pb(i); }
  }
  return primes;
}

void segmented_seive(ll l,ll r)
{
  ll lim = floor(sqrt(r))+1;
  vector<ll>primes;
  primes = seive(lim);
  bool prime[r-l+2];

  ll low = l; ll high = r;
  if(low==1) low++;

  if(low>high) return;

     clr(prime,true);

     for(ll i = 0;i<primes.size();i++)
     {
        ll p = primes[i];
        ll lowlim = p*p;

        if(lowlim<low) { lowlim = floor(low/p)*p; if(lowlim<low) lowlim+=p; }

        for(ll j = lowlim;j<=high;j+=p)
         prime[j-low] = false;
     }

     for(ll i = low;i<=high;i++)
     if(prime[i-low]) printf("%lld\n",i);
}

int main()
{
ll t,n,m;

sf(t);

while(t--)
{
  sff(m,n);
  segmented_seive(m,n);

  printf("\n");
}

return 0;
}
