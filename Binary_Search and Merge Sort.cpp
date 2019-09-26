#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,a[10000];

void merge_sort(int lo,int hi)
{
   if(lo==hi) return;
   int mid,h,l,i,m,arr[10000];
   mid = (hi+lo)/2;

   merge_sort(lo,mid);
   merge_sort(mid+1,hi);

   for(l=lo,m=mid+1,i=lo;i<=hi;i++)
   {
      if(l>mid) { arr[i] = a[m]; m++;  }
      else if(m>hi) { arr[i] = a[l]; l++; }
      else if(a[l]<a[m]) { arr[i] = a[l]; l++; }
      else { arr[i] = a[m]; m++; }

   }

   for(i=lo;i<=hi;i++)
    a[i] = arr[i];

}

void bin_search(int s)
{
   int low,high,mid;

   low = 1;
   high = n;

   while(low<=high)
   {
     mid = (low+high)/2;
     if(a[mid]==s) { cout<<"Found!"<<endl; return; }
     else if(s>a[mid]) low = mid+1;
     else high = mid-1;
   }

   cout<<"Not Found!"<<endl;
}

int main()
{
 clock_t t;
 t = clock();
 int i,value;
 cin>>n;
 srand(time(NULL));

 for(i=1;i<=n;i++)
 {
    value = rand()%100;
    a[i] = value;
 }

 merge_sort(1,n);

 for(i=1;i<=n;i++)
 cout<<a[i]<<" ";
 cout<<endl;

 int s;

 cout<<"Enter a number to search"<<endl;
 cin>>s;

 bin_search(s);

 t = clock()-t;
 printf ("\n\n%f seconds\n",((float)t)/CLOCKS_PER_SEC);

return 0;
}
