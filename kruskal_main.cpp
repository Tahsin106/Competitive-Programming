#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mx 100000

struct edge
{
  ll a,b,cost;
}e[mx];

bool cmp(edge a,edge b)
{
  return a.cost<b.cost;
}

ll p[mx],n,ed;

ll find_set(ll v)
{
   if(p[v]==v) return v;
   return p[v] = find_set(p[v]);
}
ll kruskal()
{
   ll i;

   for(i=1;i<=n;i++)
   {
      p[i] = i;
   }

   sort(e,e+ed,cmp);
   ll ret = 0;

   for(i=0;i<ed;i++)
   {
       if(find_set(e[i].a)!=find_set(e[i].b))
       {
          p[p[e[i].a]] = p[e[i].b];
          ret+=e[i].cost;
       }
   }
   return ret;
}
int main()
{
ll i,m;
cin>>n>>m;
ed = m;
i = 0;

while(m--)
{
  cin>>e[i].a>>e[i].b>>e[i].cost;
  i++;
}

ll ans = kruskal();

cout<<ans<<endl;

return 0;
}

/*

//modified initialize function:
void initialize( int Arr[ ], int N)
{
    for(int i = 0;i<N;i++)
    {
Arr[ i ] = i ;
size[ i ] = 1;
}
}

void weighted-union(int Arr[ ],int size[ ],int A,int B)
{
    int root_A = root(A);
    int root_B = root(B);
    if(size[root_A] < size[root_B ])
    {
Arr[ root_A ] = Arr[root_B];
size[root_B] += size[root_A];
}
    else
    {
Arr[ root_B ] = Arr[root_A];
size[root_A] += size[root_B];
}

}

*/
