#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,i,j,x,value,s;
vector<ll>a;

//ll a[1000000];

void bubble_sort()
{
  ll last_swap = n-1,temp = 0;
  bool f = true;

 while(f)
 {
  f = false;
   for(i=0;i<last_swap;i++)
   {
       if(a[i]>a[i+1])
       {
         x = a[i];
         a[i] = a[i+1];
         a[i+1] = x;
         temp = i;
         f = true;
       }

   }
  last_swap  = temp;
 }

}


int main()
{
 clock_t t;
 t = clock();

 cin>>n;

 srand(time(NULL));

 for(i=0;i<n;i++)
   {
     value = rand()%100;
     a.push_back(value);
   }

 bubble_sort();

 for(i=0;i<a.size();i++)
 cout<<a[i]<<endl;

 t = clock()-t;
 printf ("\n\n%f seconds\n",((float)t)/CLOCKS_PER_SEC);

return 0;
}
