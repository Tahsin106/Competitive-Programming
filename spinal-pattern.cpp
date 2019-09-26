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

ll a[802][802];

int main()
{
ll inp;
ll n,i,j;

sf(inp);

n = inp;
ll cnt=1;

ll val = n/2;
if(n%2==1) val++;

for(i=0;i<val;i++)
{
for(j=i;j<=n-i-1;j++)
{
a[i][j]= cnt;
cnt++;
}

for(j=i+1;j<=n-i-1;j++)
{
a[j][n-i-1] = cnt;
cnt++;
}

for(j=n-i-2;j>=i;j--)
{
 a[n-i-1][j] = cnt;
 cnt++;
}

for(j=n-i-2;j>i;j--)
{
 a[j][i] = cnt;
 cnt++;
}

}

for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
    if(j!=n-1) printf("%lld ",a[i][j]);
    else printf("%lld\n",a[i][j]);
}

}

return 0;
}
