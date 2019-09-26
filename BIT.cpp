#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i = 1;i<=n;i++)
#define sf(n) scanf("%lld",&n);
#define pf(n) printf("%lld\n",n);
#define MAX 100000

ll n;
ll tree[MAX];

ll read(ll i)
{
  ll sum = 0;

  while(i>0)
  {
    sum+=tree[i];
    i-=(i&-i);
  }

  return sum;
}

void update(ll i,ll val)
{
    while(i<=n)
    {
       tree[i]+=val;
       i+=(i&-i);
    }
}

int main()
{

n = 100;
ll x;

//rep(i,n)
//tree[i] = 0;
/*
rep(i,n)
{
  cin>>x;
  update(i,x);
}

*/
//update(10,10);
//update(5,15);
//update(3,5);

update(1,1);
//update(3,-1);
//update(2,1);
//update(3,-1);

cout<<read(1)<< " ";

return 0;
}
