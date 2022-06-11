#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
#include "../algo/debug.hpp" 
#else
#define debug(...) 0
#endif

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define eb emplace_back
#define em emplace
#define mp make_pair
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound

using lli = long long;
using pii = pair < int, int >;

const int N = 6e4 + 5;

int x[N], v[N];
int n;

bool f (double s) {
  double lft = -1e18, rgt = 1e18;
  FOR(i, 1, n + 1) {
    double l = 1.0 * x[i] - s * v[i];
    double r = 1.0 * x[i] + s * v[i];
    lft = max(lft, l); rgt = min(rgt, r);
  }
  return lft <= rgt;
}

int main () {
  #ifdef DEBUG
  freopen("debug.txt", "w", stderr);
  #endif
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cout << fixed << setprecision(15); cerr << fixed << setprecision(10);
  cin >> n;
  FOR(i, 1, n + 1) {
    cin >> x[i];
  }
  debug(x[1], x[2]);
  FOR(i, 1, n + 1) {
    cin >> v[i];
  }
  double l = 0, r = 1e10;
  FOR(i, 0, 100) {
    double midx = (l + r) * 0.5;
    if (f(midx)) {
      r = midx;
    } else {
      l = midx;
    }
  }
  cout << r << '\n';
  return 0;
}