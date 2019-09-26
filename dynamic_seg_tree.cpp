#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sf(n) scanf("%lld",&n)
#define sff(n,m) scanf("%lld %lld",&n,&m)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PLL pair<ll,ll>
#define mod 998244353
#define mx 100002
#define FILE freopen("input.txt","r",stdin)

struct Node {
    ll sum,lazy;
    Node *l, *r;

    Node() : sum(0),lazy(0), l(NULL), r(NULL) { }
};

void add(Node *v, ll l, ll r, ll q_l, ll q_r, ll val) {
    if (l > r || q_r < l || q_l > r)
        return;

    if (q_l <= l && r <= q_r) {
        v -> sum += (r-l+1)*val;
        v -> lazy+=val;
        return;
    }

    ll mid = (l + r) >> 1;

    if (v -> l == NULL)
        v -> l = new Node();

    if (v -> r == NULL)
        v -> r = new Node();

    add(v -> l, l, mid, q_l, q_r, val);
    add(v -> r, mid + 1, r, q_l, q_r, val);

    v->sum = v->l->sum + v->r->sum + (v->lazy)*(r-l+1);
}

ll get(Node *v, ll l, ll r, ll q_l, ll q_r,ll carry){
    if (l > r || q_r < l || q_l > r)
        return 0;

    if (q_l <= l && r <= q_r){
        return (carry)*(r-l+1) + (v -> sum);
    }

    ll mid = (l + r) >> 1;
    ll ret = 0;

    if (!(v -> l == NULL)) ret+=get(v -> l, l, mid, q_l, q_r,carry+(v->lazy));
    else if(min(mid,q_r)-max(l,q_l)+1>0) ret+=(min(mid,q_r)-max(l,q_l)+1)*(carry+v->lazy);

    if (!(v -> r == NULL)) ret+=get(v -> r, mid + 1, r, q_l, q_r,carry+(v->lazy));
    else if(min(r,q_r)-max(mid+1,q_l)+1>0) ret+=(min(r,q_r)-max(mid+1,q_l)+1)*(carry+v->lazy);

    return ret;
}

ll n, m, t, x, y, val;
ll c;

int main(){
    Node *root = new Node();

    scanf("%lld %lld", &n , &m);

    for (ll i = 0; i < m; i++) {
        scanf("%lld", &c);

        if (c == 1){
            scanf("%lld %lld %lld", &x, &y, &val);
            add(root, 1, n , x, y, -val);
        } else {
            scanf("%lld %lld", &x, &y);

            printf("%lld\n",get(root, 1, n , x, y, 0));
        }
    }

    return 0;
}
