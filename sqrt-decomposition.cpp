#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);
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
#define mp make_pair
#define PLL pair<ll,ll>
#define ff first
#define ss second
#define MAXN 10000
#define SQRSIZE 100

int arr[] = {1, 5, 2, 4, 6, 1, 3, 5, 7, 10};
int block[SQRSIZE];
int blk_sz;

void update(int idx, int val)
{
    int blockNumber = idx / blk_sz;
    block[blockNumber] += val - arr[idx];
    arr[idx] = val;
}

int query(int l, int r)
{
    int sum = 0;

    int lid = l/blk_sz;
    int rid = r/blk_sz;

    if(lid==rid)
    {
       for(int i = l;i<=r;i++) sum+=arr[i];
       return sum;
    }

    for(int i = l;i<(lid+1)*blk_sz;i++)
    {
        sum+=arr[i];
    }

    for(int i = lid+1;i<rid;i++)
    {
        sum+=block[i];
    }

    for(int i = rid*blk_sz;i<=r;i++)
    {
        sum+=arr[i];
    }

    return sum;
}

void build(int n)
{
    int blk_idx = -1;
    blk_sz = sqrt(n);

    for (int i=0; i<n; i++)
    {
        if (i%blk_sz == 0)
        {
            blk_idx++;
            //block[blk_idx] = 0; //for multiple test case
        }
        block[blk_idx] += arr[i];
    }
}

int main()
{
    int n = sizeof(arr)/sizeof(arr[0]);

    build(n);

    cout << "query(3,8) : " << query(3, 8) << endl;
    cout << "query(1,6) : " << query(1, 6) << endl;
    update(8, 0);
    cout << "query(8,8) : " << query(8, 8) << endl;
    return 0;
}
