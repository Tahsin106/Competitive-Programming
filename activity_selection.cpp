#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i = 1;i<=n;i++)
#define sf(n) scanf("%lld",&n);
#define pf(n) printf("%lld\n",n);

struct node{
ll st,en;
};

bool cmp(node a,node b)
{
  if(a.en!=b.en) return a.en<b.en;
  return a.st>b.st;
}

int main()
{
node a[100];
ll n;

cin>>n;

for(ll i = 0;i<n;i++)
cin>>a[i].st>>a[i].en;

sort(a,a+n,cmp);

ll last = 0;

cout<<1<<endl;

for(ll i=1;i<n;i++)
{
  if(a[i].st>=a[last].en) { cout<<i+1<<endl; last = i; }
}

return 0;
}
