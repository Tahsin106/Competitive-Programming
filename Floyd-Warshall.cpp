#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i = 1;i<=n;i++)
#define sf(n) scanf("%lld",&n);
#define pf(n) printf("%lld\n",n);

int main()
{
    ll val = INFINITY;
    cout<<val<<endl;
    ll b[100][100];
    ll n;

    cin>>n;

    cout<<"Input Weights"<<endl;
    for (ll i = 1;i<=n;i++)
    {
        for (ll j = 1;j<=n;j++)
        {
            cout<<i<<"-->"<<j<<": ";
            cin>>b[i][j];
        }
    }

     ll i, j, k;
    for (k = 1; k <=n; k++)
    {
        for (i = 1; i <=n; i++)
        {
            for (j = 1; j <=n; j++)
            {

                    if (b[i][k] + b[k][j] < b[i][j])
                    {
                        b[i][j] = b[i][k] + b[k][j];
                    }

            }
        }
    }

    for(i=1;i<=n;i++)
    {
        for(j = 1;j<=n;j++)
        {
            cout<<i<<" "<<j<< "  " <<b[i][j]<<" ";
        }
        cout<<endl;
    }


 return 0;

}
