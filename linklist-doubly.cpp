#include<bits/stdc++.h>
using namespace std;

struct node{
  int info;
  struct node *flink,*blink;
}*head,*tail,*temp;


void input(int num)
{
  temp = (struct node*) malloc(sizeof(struct node));
  temp->info = num;
  temp->blink = NULL;
  temp->flink = NULL;

  tail->flink = temp;
  temp->blink = tail;
  tail = tail->flink;
}

void insert(int num)
{

  temp = (struct node*) malloc(sizeof(struct node));
  temp->info = num;
  temp->flink = NULL;
  temp->blink = NULL;

  struct node *p,*q;

  p = head,q = head;
  while(p->flink!=NULL)
  {
     p = p->flink;

   // cout<<p->info<<" ";
   if(num<=(p->info))
   {
       q->flink = temp;
       q->flink->blink = q;
       q->flink->flink = p;
       p->blink = temp;
       break;

   }
   else if(p->flink==NULL)
   {
      p->flink = temp;
      temp->blink = p;
      temp->flink = NULL;
      tail = p->flink;
      break;
   }
   q = p;

  }
}


void erase(int num)
{

  struct node *p,*q;

  p = head,q = head;
  while(p->flink!=NULL)
  {
     p = p->flink;


   if(num==(p->info))
   {
       q->flink = p->flink;
       p->flink->blink = q;

   }
   else q = p;

  }
}

void show()
{
  struct node *p;

  p = head;
  while(p->flink!=NULL)
  {
     p = p->flink;
    cout<<p->info<<" ";

  }
  cout<<endl;
}

int main()
{
 struct node z;

 z.info = -1;
 z.flink = NULL;
 z.blink = NULL;
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
