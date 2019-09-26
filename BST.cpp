#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio ios_base::sync_with_stdio(0);cin.tie(nullptr);
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

struct node
{
  ll info;
  node *right,*left;
};

node* make(ll val)
{
   node* temp  = (node*)malloc(sizeof(node));
   temp->info = val;
   temp->right = NULL;
   temp->left = NULL;
   return temp;
}

node* bst_insert(node *root,ll val)
{
  if(root==NULL) return make(val);

  if(val<=root->info)
    root->left = bst_insert(root->left,val);
  else
    root->right = bst_insert(root->right,val);

  return root;
}

void inorder(node *root)
{
  if(root==NULL) return;

  inorder(root->left);
  cout<<root->info<<endl;
  inorder(root->right);
}

int main()
{
node *root = make(20);
bst_insert(root,10);
bst_insert(root,7);
bst_insert(root,99);
bst_insert(root,0);

inorder(root);

return 0;
}
