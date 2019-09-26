#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i = 1;i<=n;i++)
#define sf(n) scanf("%lld",&n);
#define pf(n) printf("%lld\n",n);

ll tree[1000],a[1000];

void make(ll node,ll b,ll e)
{
   if(b==e)
   {
      tree[node] = a[b];
      return;
   }
   ll right  = 2*node+1;
   ll left = 2*node;
   ll mid = (b+e)/2;
   make(left,b,mid);
   make(right,mid+1,e);

   tree[node] = tree[left]+tree[right];
}

ll query(ll node,ll b,ll e,ll i,ll j)
{
   if(e<i||b>j) return 0;
   if(b>=i&&e<=j) return tree[node];

   ll right  = 2*node+1;
   ll left = 2*node;
   ll mid = (b+e)/2;
   return query(left,b,mid,i,j)+query(right,mid+1,e,i,j);
}

void update(ll node,ll b,ll e,ll i,ll x)
{
   if(e<i||b>i) return;
   if(b>=i&&e<=i)
   {
      tree[node] = x;
      return;
   }

   ll right  = 2*node+1;
   ll left = 2*node;
   ll mid = (b+e)/2;
   update(left,b,mid,i,x);
   update(right,mid+1,e,i,x);

   tree[node] = tree[left]+tree[right];
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

update(1,1,n,4,40);
cout<<query(1,1,n,4,4)<<endl;

return 0;
}

/*
5
3 2 1 4 5

*/
