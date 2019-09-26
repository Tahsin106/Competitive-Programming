#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sf(n) scanf("%lld",&n)
#define sff(n,m) scanf("%lld %lld",&n,&m)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PLL pair<ll,ll>
#define mod 1000007
#define mx 100002

ll a[mx];
ll tree[3*mx];
ll lazy[3*mx];

void build(ll node,ll b,ll e)
{
  if(b==e){
     tree[node] = a[b];
     return;
  }

  ll left = 2*node;
  ll right = 2*node+1;
  ll mid = (b+e)/2;

  build(left,b,mid);
  build(right,mid+1,e);

  tree[node] = tree[left] + tree[right];
}

void update(ll node,ll b,ll e,ll i,ll j,ll x)
{
  if(lazy[node]){
     tree[node]+=(lazy[node]*(e-b+1));

     if(b!=e)
     {
       lazy[2*node]+=lazy[node];
       lazy[2*node+1]+=lazy[node];
     }

     lazy[node] = 0;
  }

  if(b>e||i>e||j<b) return;

  if(b>=i&&e<=j){
     tree[node]+=x*(e-b+1);
     if(b!=e)
     {
       lazy[2*node]+=x;
       lazy[2*node+1]+=x;
     }
     return;
  }

  ll left = 2*node;
  ll right = 2*node+1;
  ll mid = (b+e)/2;
  update(left,b,mid,i,j,x);
  update(right,mid+1,e,i,j,x);

  tree[node] = tree[left] + tree[right];
}

ll query(ll node,ll b,ll e,ll i,ll j)
{
  if(lazy[node]){
     tree[node]+=(lazy[node]*(e-b+1));

     if(b!=e)
     {
       lazy[2*node]+=lazy[node];
       lazy[2*node+1]+=lazy[node];
     }

     lazy[node] = 0;
  }

  if(b>e||i>e||j<b) return 0;

  if(b>=i&&e<=j){
     return tree[node];
  }

  ll left = 2*node;
  ll right = 2*node+1;
  ll mid = (b+e)/2;

  ll r1 = query(left,b,mid,i,j);
  ll r2 = query(right,mid+1,e,i,j);

  return r1+r2;
}

int main()
{
ll t,n,q,l,s,r,v;
sf(t);

while(t--)
{
  sff(n,q);

  for(ll i = 1;i<=n;i++)
  {
    a[i] = 0;
  }

  build(1,1,n);
  memset(lazy,0,sizeof lazy);

  while(q--)
  {
    sf(s);
    if(s==0){
        sff(l,r);
        sf(v);
        update(1,1,n,l,r,v);
    }
    else{
        sff(l,r);
        printf("%lld\n",query(1,1,n,l,r));
    }
  }
}

return 0;
}
