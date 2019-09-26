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
#define bug printf("BUG\n")
#define pfstr(s) printf("%s\n",s.c_str())
#define cs(i,n) printf("Case %lld: %lld\n",i,n)
#define clr(dp,v) memset(dp,v,sizeof dp)
#define pb push_back
#define mpr make_pair
#define PLL pair<ll,ll>
#define ff first
#define ss second
#define mx 1000
#define mod 10000000
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

multiset<ll> tree[mx*4];
multiset<ll>::iterator it;

ll ara[mx];
ll f = 0;

void update(ll node, ll b, ll e, ll idx, ll val)
{
    if(e < idx || idx < b) return;

    if(f) tree[node].erase(tree[node].find(ara[idx]));
    tree[node].insert(val);

    if(idx <= b&& e <= idx) return;

    ll lson = node * 2, rson = lson + 1, mid = (b+e)/2;
    update(lson, b, mid, idx, val);
    update(rson, mid+1, e, idx, val);
}

ll query(ll node, ll b, ll e, ll i, ll j, ll val)
{
    if(e < i || j < b) return 0;
    if(i <= b && e <= j) {
        ll ans = 0;
        it = tree[node].upper_bound(val);
        if(it != tree[node].end()) ans = 1ll * (*it - ara[i]) * (ara[j] - *it);
        if(it != tree[node].begin())
        {
            it--;
            ans = max(ans, 1ll * (*it - ara[i]) * (ara[j] - *it));
        }

        return ans;
    }
    ll lson = node * 2, rson = lson + 1, mid = (b+e)/2;
    ll x = query(lson, b, mid, i, j, val);
    ll y = query(rson, mid+1, e, i, j, val);
    return max(x, y);
}

int main()
{
    ll t;
    scanf("%lld", &t);
    while(t--)
    {
        ll n, q;
        cin>>n>>q;
        f = 0;
        for(ll i = 1; i<=n; i++)
        {
            scanf("%lld", &ara[i]);
            update(1, 1, n, i, ara[i]);
        }
        f = 1;

        while(q--)
        {
            ll sig, l, r;
            scanf("%lld %lld %lld", &sig, &l, &r);
            if(sig==1){
                printf("%lld\n", query(1, 1, n, l, r, (ara[l] + ara[r])/2));
            }
            else update(1, 1, n, l, r), ara[l] = r;
        }
        for(ll i = 1; i<= n* 4; i++) tree[i].clear();

    }
    return 0;
}
