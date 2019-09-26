#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i = 1;i<=n;i++)
#define sf(n) scanf("%lld",&n);
#define pf(n) printf("%lld\n",n);

struct segtree{
  ll sum,prop;
}tree[3*1000];

ll a[1000];

void make(ll node,ll b,ll e)
{
   if(b==e)
   {
      tree[node].sum = a[b];
      tree[node].prop = 0;
      return;
   }
   ll right  = 2*node+1;
   ll left = 2*node;
   ll mid = (b+e)/2;
   make(left,b,mid);
   make(right,mid+1,e);

   tree[node].sum = tree[left].sum+tree[right].sum;
   tree[node].prop = 0;
}

ll query(ll node,ll b,ll e,ll i,ll j,ll carry)
{
   if(e<i||b>j) return 0;
   if(b>=i&&e<=j) return tree[node].sum+(e-b+1)*carry;

   ll right  = 2*node+1;
   ll left = 2*node;
   ll mid = (b+e)/2;
   return query(left,b,mid,i,j,carry+tree[node].prop)+query(right,mid+1,e,i,j,carry+tree[node].prop);
}

void update(ll node,ll b,ll e,ll i,ll j,ll x)
{
   if(e<i||b>j) return;
   if(b>=i&&e<=j)
   {
      tree[node].sum+=((e-b+1)*x);
      tree[node].prop+=x;
      return;
   }

   ll right  = 2*node+1;
   ll left = 2*node;
   ll mid = (b+e)/2;
   update(left,b,mid,i,j,x);
   update(right,mid+1,e,i,j,x);

   tree[node].sum = tree[left].sum+tree[right].sum+(e-b+1)*tree[node].prop;
}

int main()
{
ll n,i,j;

cin>>n;

rep(k,n)
{
  cin>>a[k];
}

make(1,1,n);

update(1,1,n,3,4,40);
cout<<query(1,1,n,3,4,0)<<endl;

return 0;
}

/*
5
3 2 1 4 5

*/
