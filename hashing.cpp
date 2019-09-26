#include<bits/stdc++.h>
using namespace std;

int col[100],link[100],p[100],size = 100;

struct node
{
  int data;
  node *link;
}a[100];

int hash(int n)
{
   return n%size;
}
void separate_insert(int x)
{
  int i;
  i = hash(x);
  if(a[i].data==-1) { a[i].data = x; return;  }

  node *head,*pred;
  head = &a[i];
  pred = head;

  while(head!=NULL)
  {
     pred = head;
     if(pred->data==x) return;
     head = head->link;
  }

  node *newnode = (node*)malloc(sizeof(node));
  newnode->data = x;
  newnode->link = NULL;
  pred->link = newnode;

}

bool separate_search(int x)
{
  int i;
  i = hash(x);
  node *head;
  head = &a[i];

  while(head!=NULL)
  {

     if(head->data==x) return true;
     head = head->link;
  }
 return false;
}


void coalesced_insert(int x)
{
   if(col[hash(x)]==-1) { col[hash(x)] = x; return;  }

   int free = size-1;

   while(col[free]!=-1)
   {
      free--;
      if(free<0) { cout<<"Overflow"<<endl; return;  }
   }

   int i,prev;
   i = hash(x);
   prev = hash(x);

   while(i!=-1)
   {
     prev = i;
     if(col[prev]==x) return;
     i = link[i];
   }

   col[free] = x;
   link[free] = -1;
   link[prev] = free;

}

bool coalesced_search(int x)
{
  int i,prev;
  i = hash(x);

   while(i!=-1)
   {
     if(col[i]==x) return true;
     i = link[i];
   }

  return false;
}

bool is_full(int a[])
{
   int c = 0;
   for(int i=0;i<size;i++)
   {
       if(a[i]!=-1) c++;
   }
   if(c==size) return true;
   else return false;
}

void probing_insert(int x)
{
   if(is_full(p)) { cout<<"Overflow"<<endl; }

   int i;
   i = hash(x);
   while(p[i]!=-1)
   {
      i = (i+1)%size;
   }
   p[i] = x;
}

bool probing_search(int x)
{
   int i,c = 0;
   i = hash(x);

   while(p[i]!=-1&&c<=size)
   {
      if(p[i]==x) return true;
      i = (i+1)%size;
      c++;
   }
   return false;
}

string check(bool f)
{
  if(f) return "Found";
  else return "Not Found";
}

int main()
{
 int n,i,x;

 for(i=0;i<size;i++)
  {
      link[i] = -1;
      col[i] = -1;
      a[i].data = -1;
      p[i] = -1;
  }

 cout<<"How many numbers to insert? ";
 cin>>n;

 for(i=1;i<=n;i++)
 {
     cin>>x;
     coalesced_insert(x);
     separate_insert(x);
     probing_insert(x);
 }

 int s;

  cout<<"Enter the number you want to search: ";
  cin>>s;

  cout<<"Result using Coalesced Chaining method: ";
  cout<<check(separate_search(s))<<endl;

  cout<<"Result using Coalesced Chaining method: ";
  cout<<check(coalesced_search(s))<<endl;

  cout<<"Result using Linear Probing method: ";
  cout<<check(probing_search(s))<<endl;



return 0;
}
