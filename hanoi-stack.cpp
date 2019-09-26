#include<bits/stdc++.h>
using namespace std;

struct hanoi
{
  int disk;
  int source,aux,dest;
};

int main()
{
 int dd;
    cout<<"Number of disks: ";
    cin>>dd;
    cout<<"Moves: "<<endl;

    stack<struct hanoi>s;

    struct hanoi a,b;
    a.disk = dd;
    a.source = 1;
    a.aux = 2;
    a.dest = 3;

    s.push(a);

  while(!s.empty()) {

      a = s.top();
      if(a.disk==1) { printf("%d -->> %d\n",a.source,a.dest); s.pop(); }
      else
      {
          s.pop();

          b.disk = a.disk-1;
          b.source = a.aux;
          b.aux = a.source;
          b.dest = a.dest;

          s.push(b);

          b.disk = 1;
          b.source = a.source;
          b.aux = a.aux;
          b.dest = a.dest;

          s.push(b);

          b.disk = a.disk-1;
          b.source = a.source;
          b.aux = a.dest;
          b.dest = a.aux;

          s.push(b);

      }

    }



return 0;
}
