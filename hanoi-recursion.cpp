#include<bits/stdc++.h>
using namespace std;
void hanoi(int disk,int source,int aux,int dest)
{
  if(disk==1) printf("%d -->> %d\n",source,dest);
  else
  {
    hanoi(disk-1,source,dest,aux);
    printf("%d -->> %d\n",source,dest);
    hanoi(disk-1,aux,source,dest);
  }

}

int main()
{
    int d;
    cout<<"Number of disks: ";
    cin>>d;
    cout<<"Moves: "<<endl;

    hanoi( d,1,2,3);

}
