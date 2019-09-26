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
     if(prime[i]) { cout<<i<<endl; primes.pb(i); }
  }
  return primes;
}

void segmented_seive(ll n)
{
  ll lim = floor(sqrt(n))+1;
  vector<ll>primes;
  primes = seive(lim);
  bool prime[lim+1];

  ll low = lim; ll high = lim+lim;

  while(low<n)
  {
     clr(prime,true);

     for(ll i = 0;i<primes.size();i++)
     {
        ll p = primes[i];
        ll lowlim = floor(low/p)*p;

        if(lowlim<low) lowlim+=p;

        for(ll j = lowlim;j<high;j+=p)
         prime[j-low] = false;
     }

     for(ll i = low;i<high&&i<n;i++)
     if(prime[i-low]) cout<<i<<endl;

     low = low+lim;
     high = high+lim;
     if(high>n) high = n;
  }

}

int main()
{
ll inp;
sf(inp);

segmented_seive(10000000);

return 0;
}
