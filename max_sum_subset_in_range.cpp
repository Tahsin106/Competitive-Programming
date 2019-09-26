#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sf(n) scanf("%lld",&n)
#define sff(n,m) scanf("%lld %lld",&n,&m)
#define pf(n) printf("%lld\n",n)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PLL pair<ll,ll>
#define mod 998244353
#define mx 50002
#define FILE freopen("input.txt","r",stdin)

struct nd{
ll pre,suff,ma,sum;

nd()
{

}

nd(ll a,ll b,ll c,ll d)
{
  pre = a;
  suff = b;
  ma = c;
  sum = d;
}
};

nd tree[3*mx];

ll a[mx];

void make(ll node,ll b,ll e)
{
   if(b==e)
   {
      tree[node].pre = a[b];
      tree[node].suff = a[b];
      tree[node].ma = a[b];
      tree[node].sum = a[b];
      return;
   }

   ll right  = 2*node+1;
   ll left = 2*node;
   ll mid = (b+e)/2;
   make(left,b,mid);
   make(right,mid+1,e);

   ll ret = max(tree[left].ma,tree[right].ma);

   tree[node].ma = max(ret,tree[left].suff+tree[right].pre);
   tree[node].pre = max(tree[left].pre,tree[left].sum+tree[right].pre);
   tree[node].suff = max(tree[right].suff,tree[right].sum+tree[left].suff);
   tree[node].sum = tree[left].sum+tree[right].sum;

   //cout<<node<<" "<<b<<" "<<e<<endl;
}

nd query(ll node,ll b,ll e,ll i,ll j)
{
   if(e<i||b>j) return nd(-1e8,-1e8,-1e8,-1e8);
   if(b>=i&&e<=j) return tree[node];

   ll right  = 2*node+1;
   ll left = 2*node;
   ll mid = (b+e)/2;

   nd ret1 = query(left,b,mid,i,j);
   nd ret2 = query(right,mid+1,e,i,j);

   if(ret1.ma==-1e8) return ret2;
   else if(ret2.ma==-1e8) return ret1;

   nd ret;
   ret.ma = max(ret1.ma,ret2.ma);
   ret.ma = max(ret.ma,ret1.suff+ret2.pre);
   ret.pre = max(ret1.pre,ret1.sum+ret2.pre);
   ret.suff = max(ret2.suff,ret2.sum+ret1.suff);
   ret.sum = ret1.sum+ret2.sum;

   return ret;
}

int main()
{
ll n;
sf(n);

for(ll i = 1;i<=n;i++)
{
  sf(a[i]);
}

make(1,1,n);

ll q,x,y;
sf(q);

while(q--)
{
  sff(x,y);
  printf("%lld\n",query(1,1,n,x,y).ma);
}

return 0;
}
