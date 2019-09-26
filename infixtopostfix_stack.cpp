#include<bits/stdc++.h>
using namespace std;

char a[10000],i = 0; // a is the stack array and i is the stack pointer

void push(char p)
{
  a[i] = p;
  i++;
}
char top()   //just returns the top element of the stack but doesn't delete it
{
   if(i==0)  return 'e';  //i==0 means stack is empty, so we return 'e' which will indicate that the stack is empty
   i--;
   char ch = a[i++];
   return ch;
}

void pop()  //deletes top element of the stack and decreases the stack pointer
{
    if(i>0) i--;
}
int check(char c) //check if the character is an operator or a number, if operator then what is its precedence value according to BODMAS
{
  if(c=='*'||c=='/') return 2;
  if(c=='+'||c=='-') return 1;
  if(c=='('||c==')')  return 0;
  return -1;      // if it is a number return -1
}
int main()
{
 string s;
 cin>>s;
 int i,j;
 string ans;

 for(i=0;i<s.size();i++)
 {
    if(s[i]=='(') push(s[i]);
    else if(s[i]==')')
    {
      while(top()!='(')    //when we get '(' we will pop the stack until get a '('
      {
         ans = ans + top();
         ans = ans+ ' ';
         pop();
      }
      pop();
    }
    else if(check(s[i])==-1)  //we got a number
    {
       while(check(s[i])==-1&&i<s.size()) { ans = ans+s[i]; i++; }  // append the number in ans string
       ans = ans+ ' ';
       i--;
    }
    else   //we got a operator
    {

       while(top()!='e'&&check(top())>=check(s[i]))
       {
          ans = ans + top();
          ans = ans+ ' ';
          pop();
       }
       push(s[i]);  //now we can push the operator on the stack since every element in the stack greater than this operator has been popped out from stack
    }
 }

 while(top()!='e')
 {
     ans+=top();
     ans = ans+ ' ';   //append rest of operator in stack to ans string
     pop();
 }

 cout<<ans<<endl;


return 0;
}
