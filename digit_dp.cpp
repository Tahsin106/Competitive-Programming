#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sf(n) scanf("%lld",&n)
#define sff(n,m) scanf("%lld %lld",&n,&m)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mx 300005
#define PLL pair<ll,ll>

vector<ll>d;

ll getDigits(ll x)
{
  d.clear();

  while(x)
  {
    d.push_back(x%10);
    x/=10;
  }
}

ll dp[20][180][2];

ll F(ll idx,ll cnt,ll t)
{
  if(idx==-1) return cnt;

  if(dp[idx][cnt][t]!=-1) return dp[idx][cnt][t];

  ll ret = 0;
  ll k = (t)?d[idx]:9;

  for(ll i = 0;i<=k;i++)
  {
    ll nT = (d[idx]==i)?t:0;
    ret+=(F(idx-1,cnt+i,nT));
  }

  return dp[idx][cnt][t] = ret;
}

int main()
{
memset(dp,-1,sizeof dp);

return 0;
}
