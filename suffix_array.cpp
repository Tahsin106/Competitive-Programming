#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 65536
#define MAXLG 17

string A;

struct entry
{
    int nr[2];
    int p;
} L[MAXN];

int P[MAXLG][MAXN];
int N;
int stp, cnt;
int suff[MAXN];

int cmp(struct entry a, struct entry b)
{
    return a.nr[0]==b.nr[0] ?(a.nr[1]<b.nr[1] ?1: 0): (a.nr[0]<b.nr[0] ?1: 0);
}

int lcp(int x,int y)
{
    if(x==y) return N-x;

    int ret = 0;

    for(int i = stp;i>=0;i--)
    {
        if(P[i][x]==P[i][y]&&x<N&&y<N){

            ret+=(1<<i);
            x+=(1<<i);
            y+=(1<<i);
        }
    }

    return ret;
}

int main()
{
int t;
cin>>t;

while(t--){

    cin>>A;

    N = A.size();

    for(int i = 0;i<N;i++)
    {
        P[0][i] = A[i] - 'A';
    }

    for(stp=1, cnt = 1; cnt < N; stp++, cnt *= 2)
    {
        for(int i=0; i < N; i++)
        {
            L[i].nr[0]=P[stp- 1][i];
            L[i].nr[1]=i +cnt <N? P[stp -1][i+ cnt]:-1;
            L[i].p= i;
        }
        sort(L, L+N, cmp);
        for(int i=0; i < N; i++)
            {
                P[stp][L[i].p] =i> 0 && L[i].nr[0]==L[i-1].nr[0] && L[i].nr[1] == L[i- 1].nr[1] ? P[stp][L[i-1].p] : i;
                suff[i] = L[i].p;
            }
    }

    //suff is the suffix array

    if(N==1){
        suff[0] = 0;
    }

    stp--;

    int ans = 0; //Distinct Substring Count

    for(int i = 0;i<N;i++)
    {
        if(i==0) ans+=N-suff[i];
        else ans+=((N-suff[i])-lcp(suff[i-1],suff[i]));
    }

    cout<<ans<<endl;
}

return 0;
}
