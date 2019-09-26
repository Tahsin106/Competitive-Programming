#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,a[10000],comp = 0,mov = 0;

void insertion_sort()
{
  int i,j,temp;

  for(i=2;i<=n;i++)
  {
    temp = a[i];
    for(j=i-1;j>=1&&temp<a[j];j--)
    {
      a[j+1] = a[j];
      comp++; mov++;
    }
    a[j+1] = temp;
  }
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

 insertion_sort();

 for(i=1;i<=n;i++)
 cout<<a[i]<<" ";
 cout<<endl;

 cout<<"Number of Comparison: "<<comp<<endl;
 cout<<"Number of Data Movements: "<<mov<<endl;


 t = clock()-t;
 printf ("\n\n%f seconds\n",((float)t)/CLOCKS_PER_SEC);

return 0;
}
