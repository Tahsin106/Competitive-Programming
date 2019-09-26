#include<bits/stdc++.h>
using namespace std;

int check(char c)
{
  if(c=='*'||c=='/') return 2;
  if(c=='+'||c=='-') return 1;
  if(c=='('||c==')')  return 0;
  return -1;
}

int main()
{
 string s;
 cin>>s;
 int i,j;
 stack<char>op;
 string ans;

 for(i=0;i<s.size();i++)
 {
    if(s[i]=='(') op.push(s[i]);
    else if(s[i]==')')
    {
      while(op.top()!='(')
      {
         ans = ans + op.top();
         ans = ans+ ' ';
         op.pop();
      }
      op.pop();
    }
    else if(check(s[i])==-1)
    {
       while(check(s[i])==-1&&i<s.size()) { ans = ans+s[i]; i++; }
       ans = ans+ ' ';
       i--;
    }
    else
    {
      // if(s.empty()) { op.push(s[i]); continue;  }

       while(!op.empty()&&check(op.top())>=check(s[i]))
       {
          ans = ans + op.top();
          ans = ans+ ' ';
          op.pop();
       }
       op.push(s[i]);
    }
 }

 while(!op.empty())
 {
     ans+=op.top();
     ans = ans+ ' ';
     op.pop();
 }

 cout<<ans<<endl;

return 0;
}


