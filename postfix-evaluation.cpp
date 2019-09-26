#include<bits/stdc++.h>
using namespace std;

int check(char c)
{
  if(c=='*'||c=='/') return 1;
  if(c=='+'||c=='-'||c==' ') return 1;

  return 0;
}

int func(char c,int x,int y)
{
  if(c=='+') return x+y;
  if(c=='-') return y-x;
  if(c=='/') return y/x;
  if(c=='*') return y*x;
}

int main()
{
 string s;
 getline(cin,s);
 int i,x,y;
 stack<int>ans;

 for(i=0;i<s.size();i++)
 {
   if(check(s[i])==0)
    {
       string num;
       while(check(s[i])==0&&i<s.size())
       {
           num+=s[i];
           i++;
       }
       int n = atoi(num.c_str());
       ans.push(n);
    }
    else
    {
       x = ans.top();
       ans.pop();
       y = ans.top();
       ans.pop();
       ans.push(func(s[i],x,y));

       i++;
    }
 }
 cout<<ans.top()<<endl;

return 0;
}
