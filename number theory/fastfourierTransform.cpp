#include <bits/stdc++.h>
using namespace std;

#define IN freopen("in.txt", "r", stdin);
#define OUT freopen("out.txt", "w", stdout);
#define ll long long int
#define PII pair <int, int>
#define MX 100001
#define EPS 1e-9
#define MOD 1000000007
#define PI 2.0 * acos(0.0)

typedef complex <long double> Complex;
typedef valarray <Complex> ValComplex;

const long double PI = 2 * acos(0.0);

void fft(ValComplex &p, bool inverse = 0) {
  int n = p.size();
  if(n <= 1) return;

  ValComplex f = p[slice(0, n/2, 2)],
             g = p[slice(1, n/2, 2)];

  // splice(a, b, c) will return number in indexes
  // a, a + c, a + 2c, .... a + (b-1)c  

  fft(f, inverse); fft(g, inverse); // FFT for F and G

  Complex omega_n = exp(Complex(0, 2 * PI / n)), w = 1;
  if(inverse) omega_n = Complex(1, 0) / omega_n;

  for(int k = 0; k < n / 2; k++) {
    // Here w = omega_n^k
    Complex add = w * g[k];   
    // this is p(x)
    p[k]       = f[k] + add;  
    // Note that p(-x) should be in (x+n/2)th position
    p[k + n/2] = f[k] - add;  
    w *= omega_n;
  }
}
void ifft(ValComplex &p) {
  fft(p, 1);
  p /= p.size(); // Divide each element by p.size()
}

vector<int> multiply(vector<int> a, vector<int> b) {
  int n = a.size(), m = b.size();
  int t = n + m - 1, sz = 1; // t is degree of R
  while(sz < t) sz <<= 1;  // rounding to nearest 2^x

  ValComplex x(sz), y(sz), z(sz);
  // Resize first polynomial by inserting 0.
  for(int i = 0; i < n; i++) x[i] = Complex(a[i], 0);
  for(int i = n; i < sz; i++) x[i] = Complex(0, 0);

  // Resize second polynomial by inserting 0.
  for(int i = 0; i < m; i++) y[i] = Complex(b[i], 0);
  for(int i = m; i < sz; i++) y[i] = Complex(0, 0);

  fft(x); fft(y);   // Do fft on both polynomial
  // Multiply in Point-Value Form
  for(int i = 0; i < sz; i++) z[i] = x[i] * y[i];

  ifft(z);  // Inverse FFT
  vector<int> res(sz);
  // Precision problem may occur, round to nearest integer
  for(int i = 0; i < sz; i++) res[i] = z[i].real() + 0.5;
  // remove trailing 0's
  while(res.size() > 1 && res.back() == 0) res.pop_back();
  return res;
}


// cp-algorthms
using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();
    if (n == 1)
        return;

    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }
    fft(a0, invert);
    fft(a1, invert);

    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n/2] /= 2;
        }
        w *= wn;
    }
}

vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

int carry = 0;
for (int i = 0; i < n; i++) {
	result[i] += carry;
	carry = result[i] / 10;
	result[i] %= 10;
}

using cd = complex<double>;
const double PI = acos(-1);

int reverse(int num, int lg_n) {
    int res = 0;
    for (int i = 0; i < lg_n; i++) {
        if (num & (1 << i))
            res |= 1 << (lg_n - 1 - i);
    }
    return res;
}

void fft(vector<cd> & a, bool invert) {
    int n = a.size();
    int lg_n = 0;
    while ((1 << lg_n) < n)
        lg_n++;

    for (int i = 0; i < n; i++) {
        if (i < reverse(i, lg_n))
            swap(a[i], a[reverse(i, lg_n)]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}

const int mod = 7340033;
const int root = 5;
const int root_1 = 4404020;
const int root_pw = 1 << 20;

void fft(vector<int> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        int wlen = invert ? root_1 : root;
        for (int i = len; i < root_pw; i <<= 1)
            wlen = (int)(1LL * wlen * wlen % mod);

        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i+j], v = (int)(1LL * a[i+j+len/2] * w % mod);
                a[i+j] = u + v < mod ? u + v : u + v - mod;
                a[i+j+len/2] = u - v >= 0 ? u - v : u - v + mod;
                w = (int)(1LL * w * wlen % mod);
            }
        }
    }

    if (invert) {
        int n_1 = inverse(n, mod);
        for (int & x : a)
            x = (int)(1LL * x * n_1 % mod);
    }
}

int main() 
{
	
}