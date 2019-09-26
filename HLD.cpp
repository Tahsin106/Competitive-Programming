#include<bits/stdc++.h>
using namespace std;
typedef int ll;
#define sf(n) scanf("%d",&n)
#define sff(n,m) scanf("%d %d",&n,&m)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PLL pair<ll,ll>
#define mod 1000007
#define mx 10002
#define FILE freopen("input.txt","r",stdin)

ll chainHead[mx],chainInd[mx],baseArray[mx],posInBase[mx];
ll subsize[mx],otherEnd[mx];
vector<ll>adj[mx],costs[mx],indexx[mx];

ll chainNo,ptr,id;

const ll lg = 18;

ll P[mx][lg+2];
ll st[mx],en[mx];
ll tree[3*mx];

void make(ll node,ll b,ll e)
{
   if(b==e)
   {
      tree[node] = baseArray[b];
      return;
   }
   ll right  = 2*node+1;
   ll left = 2*node;
   ll mid = (b+e)/2;
   make(left,b,mid);
   make(right,mid+1,e);

   tree[node] = max(tree[left],tree[right]);
}

ll query(ll node,ll b,ll e,ll i,ll j)
{
   if(e<i||b>j) return 0;
   if(b>=i&&e<=j) return tree[node];

   ll right  = 2*node+1;
   ll left = 2*node;
   ll mid = (b+e)/2;
   return max(query(left,b,mid,i,j),query(right,mid+1,e,i,j));
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

   tree[node] = max(tree[left],tree[right]);
}

ll query_ans(ll u,ll v)
{
  if(u==v) return 0;

  ll ret = -1,tmp;
  ll vchain = chainInd[v];

  while(true)
  {
    ll uchain = chainInd[u];

    if(uchain==vchain){
        if(u==v) break;
        tmp = query(1,1,ptr,posInBase[v]+1,posInBase[u]);
        ret = max(ret,tmp);
        break;
    }

    tmp = query(1,1,ptr,posInBase[chainHead[uchain]],posInBase[u]);
    ret = max(ret,tmp);
    u = chainHead[uchain];
    u = P[u][0];
  }

  return ret;
}

void HLD(ll curNode, ll cost, ll prev)
{
	if(chainHead[chainNo] == -1){
		chainHead[chainNo] = curNode;
	}

	chainInd[curNode] = chainNo;
	posInBase[curNode] = ptr;
	baseArray[ptr++] = cost;

	ll sc = -1, ncost;

	for(int i = 0; i<adj[curNode].size(); i++)
    if(adj[curNode][i] != prev){
		if(sc == -1 || subsize[sc] < subsize[adj[curNode][i]]){
			sc = adj[curNode][i];
			ncost = costs[curNode][i];
		}
	}

	if(sc != -1){
		HLD(sc, ncost, curNode);
	}

	for(int i=0; i<adj[curNode].size(); i++)
    if(adj[curNode][i] != prev){
		if(sc != adj[curNode][i]) {
			chainNo++;
			HLD(adj[curNode][i], costs[curNode][i], curNode);
		}
	}
}

void dfs(ll u,ll p)
{
  st[u] = id++;

  P[u][0] = p;

  for(int j = 1;j<=lg;j++)
  {
    if(P[u][j-1]!=-1){
     P[u][j] = P[P[u][j-1]][j-1];
    }
  }

  subsize[u] = 1;

  for(int i = 0;i<adj[u].size();i++)
  {
    if(adj[u][i]!=p){
        otherEnd[indexx[u][i]] = adj[u][i];
        dfs(adj[u][i], u);
        subsize[u] += subsize[adj[u][i]];
    }
  }

  en[u] = id++;
}

bool fun(ll u,ll v)
{
  if(st[v]>=st[u]&&en[v]<=en[u]) return true;
  else return false;
}

ll lca(ll u,ll v)
{
  if(u==v) return u;
  if(fun(u,v)) return u;
  if(fun(v,u)) return v;

  for(int j = lg;j>=0;j--)
  {
    if(P[u][j]==-1) continue;

    if(!fun(P[u][j],v)){
       u = P[u][j];
    }
  }

  return P[u][0];
}

int main()
{
ll t,n,a,b,c;
sf(t);

while(t--)
{
  sf(n);

  for(int i = 1;i<=n-1;i++)
  {
    sff(a,b);
    sf(c);
    adj[a].push_back(b);
    adj[b].push_back(a);
    costs[a].push_back(c);
    costs[b].push_back(c);
    indexx[a].push_back(i);
    indexx[b].push_back(i);
  }

  memset(P,-1,sizeof P);
  memset(chainHead,-1,sizeof chainHead);
  ptr = 1;
  chainNo = 1;
  id = 1;

  dfs(1,1);
  HLD(1,-1,-1);
  ptr--;
  make(1,1,ptr);

  char s[10];

  while(true)
  {
    scanf("%s",s);
    if(strcmp(s,"DONE")==0) break;

    sff(a,b);

    if(strcmp(s,"CHANGE")==0){
       update(1,1,ptr,posInBase[otherEnd[a]],b);
    }
    else{
       ll lc = lca(a,b);
       printf("%d\n",(ll)max(query_ans(a,lc),query_ans(b,lc)));
    }
  }

  for(ll i = 1;i<=n;i++)
  {
    adj[i].clear();
    costs[i].clear();
    indexx[i].clear();
  }
}

return 0;
}
