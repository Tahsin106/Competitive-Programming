#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef complex <long double> Complex;
typedef valarray <Complex> ValComplex;
#define sf(n) scanf("%lld",&n)
#define sff(n,m) scanf("%lld %lld",&n,&m)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PLL pair<ll,ll>
#define mod 1000007
#define mx 17
#define FILE freopen("input.txt","r",stdin)

const long double PI = 2 * acos(0.0);

void fft(ValComplex &p, bool inverse = 0) {
  ll n = p.size();
  if(n <= 1) return;

  ValComplex f = p[slice(0, n/2, 2)],
             g = p[slice(1, n/2, 2)];

  fft(f, inverse); fft(g, inverse);

  Complex omega_n = exp(Complex(0, 2 * PI / n)), w = 1;
  if(inverse) omega_n = Complex(1, 0) / omega_n;

  for(ll k = 0; k < n / 2; k++) {
    Complex add = w * g[k];
    p[k]       = f[k] + add;

    p[k + n/2] = f[k] - add;
    w *= omega_n;
  }
}
void ifft(ValComplex &p) {
  fft(p, 1);
  p /= p.size();
}

vector<ll> multiply(vector<ll> a, vector<ll> b) {
  ll n = a.size(), m = b.size();
  ll t = n + m - 1, sz = 1; // t is degree of R
  while(sz < t) sz <<= 1;  // rounding to nearest 2^x

  ValComplex x(sz), y(sz), z(sz);
  // Resize first polynomial by inserting 0.
  for(ll i = 0; i < n; i++) x[i] = Complex(a[i], 0);
  for(ll i = n; i < sz; i++) x[i] = Complex(0, 0);

  // Resize second polynomial by inserting 0.
  for(ll i = 0; i < m; i++) y[i] = Complex(b[i], 0);
  for(ll i = m; i < sz; i++) y[i] = Complex(0, 0);

  fft(x); fft(y);   // Do fft on both polynomial
  // Multiply in Point-Value Form
  for(ll i = 0; i < sz; i++) z[i] = x[i] * y[i];

  ifft(z);  // Inverse FFT
  vector<ll> res(sz);
  // Precision problem may occur, round to nearest integer
  for(ll i = 0; i < sz; i++) res[i] = z[i].real() + 0.5;
  // remove trailing 0's
  while(res.size() > 1 && res.back() == 0) res.pop_back();
  return res;
}

int main()
{
ll t,n,x;
sf(t);

while(t--)
{
  sf(n);

  vector<ll>a,b;

  for(ll i = 1;i<=n+1;i++)
  {
    sf(x);
    a.push_back(x);
  }

  for(ll i = 1;i<=n+1;i++)
  {
    sf(x);
    b.push_back(x);
  }

  reverse(a.begin(),a.end());
  reverse(b.begin(),b.end());

  vector<ll>v = multiply(a,b);

  reverse(v.begin(),v.end());

  for(ll i = 0;i<v.size();i++)
  {
    if(i>0) printf(" ");
    printf("%lld",v[i]);
  }

  printf("\n");
}

return 0;
}
