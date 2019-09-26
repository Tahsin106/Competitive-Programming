#include<bits/stdc++.h>

using namespace std;

vector<int>adj[100];
queue<int>q;

int visit[100],u,v;
int dis[100];
void bfs(int s,int n)
{
   int i;
    for(i=0;i<n;i++) visit[i]=0;
    cout<<"Traversal: "<<endl;
    q.push(s);
    visit[s]=1;

    while(!q.empty())
    {
        u=q.front();

        cout<<u<<endl;
        q.pop();

        for(i=0;i<adj[u].size();i++)
        {
            if(visit[adj[u][i]]==0)
            {
                v=adj[u][i];
                visit[v]=1;
                q.push(v);
            }
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

   for(int i=0;i<e;i++)
   {
       cin>>a>>b;
       adj[a].push_back(b);

   }
   cout<<"Source :"<<endl;
   cin>>s;
   bfs(s,n);


  return 0;
}
