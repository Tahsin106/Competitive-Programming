#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node{
  ll mark;
  node *next[30];
  node()
  {
     mark = 0;
     for(ll i=0;i<26;i++)
      next[i] = NULL;
  }
}*root;

void insert(string s)
{
  node *curr;
  curr = root;
  for(ll i=0;i<s.size();i++)
  {
     ll id = s[i]-'a';
     if(curr->next[id]==NULL) curr->next[id] = new node();
     curr = curr->next[id];
  }
  curr->mark = 1;
}

bool search(string s)
{
  node *curr;
  curr = root;
  for(ll i=0;i<s.size();i++)
  {
     ll id = s[i]-'a';
     if(curr->next[id]==NULL) return false;
     curr = curr->next[id];
  }
  return curr->mark;
}

void del(node *cur)
{
   for(ll i=0;i<26;i++)
    if(cur->next[i]) del(cur->next[i]);

    delete(cur);
}

int main()
{
root = new node();
insert("abcd");

cout<<search("abcd");


return 0;
}
