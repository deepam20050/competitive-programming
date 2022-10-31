#include "bits/stdc++.h"
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)

using lli = long long;
using pii = pair < int, int >;

// Credits : https://codeforces.com/contest/1420/submission/93731409
template < int M > struct modint {
  int val = 0;
  modint () {}
  modint (int x) : val(x) {
    while (val < 0) val += M;
    while (val >= M) val -= M;
  }
  modint (long long x): val(x % M) {
    if (val < 0) val += M;
  }
  modint operator+= (modint oth) {
    val += oth.val;
    if (val >= M) val -= M;
    return *this;
  }
  modint operator-= (modint oth) {
    val -= oth.val;
    if (val < 0) val += M;
    return *this;
  }
  modint operator*= (modint oth) {
    val = val * 1LL * oth.val % M;
    return *this;
  }
  void operator++ () {
    ++val;
    if (val == M) val = 0;
  }
  void operator-- () {
    --val;
    if (val == -1) {
      val = M - 1;
    }
  }
  modint operator- () {
    modint res;
    res.val = (val == 0) ? 0 : M - val;
    return res;
  }
  modint& operator/= (modint const& b) {
    return *this *= inv(b);
  }
  int mod() {
    return M;
  }
  template < class T >
  modint pow (T x) {
    modint base = val;
    modint res = 1;
    while (x > 0) {
      if (x & 1) res *= base;
      base *= base;
      x >>= 1;
    }
    return res;
  }
  modint inv () {
    return pow(M - 2);
  }
  friend modint operator+ (modint a, modint b) {
    return modint(a) += b;
  }
  friend modint operator- (modint a, modint b) {
    return modint(a) -= b;
  }
  friend modint operator* (modint a, modint b) {
    return modint(a) *= b;
  }
  friend bool operator== (modint a, modint b) {
    return a.val == b.val;
  }
  friend bool operator!= (modint a, modint b) {
    return a.val != b.val;
  }
  friend modint operator/(modint a, modint const b) {
    return a /= b;
  }
  friend std::istream& operator>> (std::istream& istream, modint& a) {
    long long v; istream >> v; a = v; return istream;
  }
  friend std::ostream& operator<< (std::ostream& ostream, modint const& a) {
    return ostream << a.val;
  }
};

const int MM = 1e9 + 7;

using mint = modint < MM >;

template < class T > struct Matrix {
  int R, C;
  vector < vector < T > > data;
  Matrix(int r, int c) : R(r), C(c) {
    data.assign(R, vector < T > (C));
  }
  Matrix(vector<vector<T>> dat) : data(dat), R(sz(data)), C(sz(data[0])) {}

  Matrix operator+(const Matrix& M) {
    Matrix res(R, C);
    rep(i, 0, R) {
      rep(j, 0, C) {
        res.data[i][j] = data[i][j] + M.data[i][j];
      }
    }
    return res;
  }
  Matrix operator-(const Matrix& M) {
    Matrix res(R, C);
    rep(i, 0, R) {
      rep(j, 0, C) {
        res.data[i][j] = data[i][j] - M.data[i][j];
      }
    }
    return res;
  }
  Matrix operator*(const Matrix& M) {
    Matrix res(R, M.C);
    rep(i, 0, R) {
      rep(j, 0, C) {
        rep(k, 0, M.C) {
          res.data[i][k] += data[i][j] * M.data[j][k];
        }
      }
    }
    return res;
  }
  Matrix& operator+=(const Matrix& M) {
    return *this = (*this)+M;
  }
  Matrix& operator-=(const Matrix& M) {
    return *this = (*this)-M;
  }
  Matrix& operator*=(const Matrix& M) {
    return *this = (*this)*M;
  }
  friend Matrix exp(Matrix M, lli P) {
    Matrix res(M.R, M.C);
    rep(i, 0, M.R) {
      res.data[i][i] = 1;
    }
    for (; P; P >>= 1ll, M *= M) if (P & 1) res *= M;
    return res;
  }
};

void test_case() {
  int n, m, k; cin >> n >> m >> k;
  Matrix < mint > mat(n, n);
  for (int i = 0; i < m; ++i) {
    int x, y; cin >> x >> y;
    --x;
    --y;
    ++mat.data[x][y];
    ++mat.data[y][x];
  }
  auto p = exp(mat, (k) * 1ll);
  mint ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += p.data[0][i];
  }
  cout << ans << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  test_case();
  return 0;
}
