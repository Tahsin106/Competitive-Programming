#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct edge
{
  ll a,b,cost;
}e[1000];

ll p[1000],edge,n;
ll heap_size;

void max_heapify(ll i)
{
   ll largest = i;
   ll l = 2*i;
   ll r = 2*i+1;
   if(l<=heap_size&&e[l].cost>e[largest].cost)
   {
       largest = l;
   }
   if(r<=heap_size&&e[r].cost>e[largest].cost)
   {
       largest = r;
   }

   if(i!=largest)
   {
       swap(e[largest],e[i]);
       max_heapify(largest);
   }
}
void build_heap()
{
   ll i;
   for(i=n/2;i>=1;i--)
   {
       max_heapify(i);
   }
}

void heap_sort()
{
   ll i;
   heap_size = n;
   build_heap();

   for(i=n;i>=1;i--)
   {
      swap(e[i],e[1]);
      heap_size--;
      max_heapify(1);
   }

}
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

   heap_sort();
   ll ret = 0;

   for(i=1;i<=edge;i++)
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
ll i;
cin>>n>>edge;

i = 1;

while(edge--)
{
  cin>>e[i].a>>e[i].b>>e[i].cost;
  i++;
}

ll ans = kruskal();

cout<<ans<<endl;

return 0;
}
