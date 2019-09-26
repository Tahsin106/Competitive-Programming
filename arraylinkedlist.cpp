#include<bits/stdc++.h>
using namespace std;

int a[100][2];
int head = -1,tail = -1,avail = 0,temp;

void insert(int n)
{
  if(avail==-1) { cout<<"Overflow"<<endl; return; }

  temp = a[avail][1];
  a[avail][0] = n;
  a[avail][1] = -1;
  if(tail!=-1) a[tail][1] = avail;
  tail = avail;
  if(head==-1) head = avail;
  avail = temp;
}

void del(int n)
{
   if(head==-1) { cout<<"Empty"<<endl; return; }
  bool found = false;

  int p,pred;
  p = head;
  while(p!=-1)
  {
   if(a[p][0]==n)
    {

    found = true;
    if(p==head)
    {
       if(p==tail) tail = a[p][1];

       head = a[p][1];
       a[p][1] = avail;
       avail = p;

    }
    else
     {
       a[pred][1] = a[p][1];
       if(p==tail) { if(a[p][1]==-1) tail = pred; else tail = a[p][1]; }
       a[p][1] = avail;
       avail = p;
     }
      break;
    }
    pred = p;
    p = a[p][1];
  }
  if(!found) cout<<"This data is not present in linked list"<<endl;
}

void show()
{
  if(head==-1) { cout<<"Empty"<<endl; return; }

  int p;
  p = head;
  while(p!=-1)
  {
   cout<<a[p][0]<<endl;
   p = a[p][1];
  }
}

int main()
{
 int i,n,ch,num;

 cout<<"Length of linked list: ";
 cin>>n;

 for(i=0;i<n;i++)
 {
   if(i==n-1) {  a[i][1] = -1; continue; }
   a[i][1] = i+1;
 }

 while(true)
 {
   cout<<"1.Insert  2.Delete  3.Show"<<endl;
   cin>>ch;

   switch(ch)
   {
       case 1: cout<<"Enter the number: "; cin>>num; insert(num); break;
       case 2: cout<<"Enter the number: "; cin>>num; del(num); break;
       case 3: show(); break;
   }
 }

return 0;
}
