#include<bits/stdc++.h>
using namespace std;

struct node{
  int info;
  node *link;
}*head,*tail,*temp;


void input(int num)
{
  temp = (node*) malloc(sizeof(struct node));
  temp->info = num;
  temp->link = NULL;

  tail->link = temp;
  tail = tail->link;
}

void insert(int num)
{

  temp = (struct node*) malloc(sizeof(struct node));
  temp->info = num;
  temp->link = NULL;

  struct node *p,*q;

  p = head,q = head;
  while(p->link!=NULL)
  {
     p = p->link;

   // cout<<p->info<<" ";
   if(num<=(p->info))
   {
       temp->link = p;
       q->link = temp;
       break;

   }
   else if(p->link==NULL)
   {
      p->link = temp;
      temp->link = NULL;
      tail = p->link;
      break;
   }
   q = p;

  }
}


void erase(int num)
{

  struct node *p,*q;

  p = head,q = head;
  while(p->link!=NULL)
  {
     p = p->link;


   if(num==(p->info))
   {
       q->link = p->link;

   }
   else q = p;

  }
}

void show()
{
  struct node *p;

  p = head;
  while(p->link!=NULL)
  {
     p = p->link;
    cout<<p->info<<" ";

  }
  cout<<endl;
}

int main()
{
 struct node z;

 z.info = -1;
 z.link = NULL;
 tail=&z;
 head = tail;
 int nn,i;
 for(i = 1;i<=5;i++)
 {
   cin>>nn;
   input(nn);
 }

 int ins,er;
 cout<<"Enter the number you want to insert: ";
 cin>>ins;
 insert(ins);
 show();
 cout<<"Enter the number you want to delete: ";
 cin>>er;
 erase(er);
 show();

return 0;
}
