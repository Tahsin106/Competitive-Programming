#include<bits/stdc++.h>
using namespace std;

vector<int>adj[100];
stack<int>s;

bool visit[1000];

void dfs(int sr,int n)
{
    int i;
    s.push(sr);
  cout<<"Traversal: "<<endl;

    while(!s.empty())
    {
        int u=s.top();
        s.pop();

        if(!visit[u])
        {
            visit[u] =  true;
            cout<<u<<endl;
        }

        for(i=adj[u].size()-1;i>=0;i--)
        {
           if(!visit[adj[u][i]]) s.push(adj[u][i]);
        }

    }

}

int main()
{

    int r,n,e,a,b,s;
    cout<<"Nodes : ";
    cin>>n;
    cout<<"Edges : ";
    cin>>e;

 memset(visit,false,sizeof(visit));

   for(int i=0;i<e;i++)
   {
       cin>>a>>b;
       adj[a].push_back(b);

   }
   cout<<"Source :"<<endl;
   cin>>s;
   dfs(s,n);


  return 0;
}
