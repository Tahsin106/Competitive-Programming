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

struct node
{
  ll l,r,k,pos;
}qr[mx];

ll block;

bool cmp(node x,node y)
{
  if (x.l/block!=y.l/block) return x.l/block<y.l/block;
  return x.r < y.r;
}

int main()
{
ll n;
sf(n);
ll a[n+1];

rep0(i,n)
sf(a[i]);

ll q;
sf(q);
ll le,ri,ka;

rep0(i,q)
{
  sff(le,ri);
  sf(ka);
  qr[i].l = le;
  qr[i].r = ri;
  qr[i].k = ka;
  qr[i].pos = i;
}

block  = (ll)sqrt(n);

sort(qr,qr+q,cmp);

ll curL = 0,curR = -1;

map<ll,ll>mp,fq;
ll ans[q+1];

rep0(i,q)
{
  le = qr[i].l;
  le--;
  ri = qr[i].r;
  ri--;

  while(curR<ri)
  {
    curR++;

    mp[a[curR]]++;
    fq[mp[a[curR]]]++;

  }
  while(curR>ri)
  {
    if(mp[a[curR]]>0)
    {
      fq[mp[a[curR]]]--;
      mp[a[curR]]--;

    }

    curR--;
  }
  while(curL<le)
  {
    if(mp[a[curL]]>0)
    {
      fq[mp[a[curL]]]--;
      mp[a[curL]]--;

    }

    curL++;
  }
  while(curL>le)
  {
    curL--;

    mp[a[curL]]++;
    fq[mp[a[curL]]]++;
  }

  //pf(fq[qr[i].k]);
  ans[qr[i].pos] = fq[qr[i].k];
}

rep0(i,q)
pf(ans[i]);

return 0;
}
