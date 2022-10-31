#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define eb emplace_back
#define em emplace
#define mp make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define lb lower_bound
#define ub upper_bound

using lli = long long;
using pii = pair < int, int >;

const int N = 1e5 + 5;

lli val[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  int x11, x22; cin >> x11 >> x22;
  vector < pair < double, int > > v1(n), v2(n);
  double x1 = (double)x11 + (1e-9);
  double x2 = (double)x22 - (1e-9);
  FOR(i, 0, n) {
    int k, b; cin >> k >> b;
    v1[i] = {k * 1ll * x1 + b, i};
    v2[i] = {k * 1ll * x2 + b, i};
  }
  sort(all(v1));
  sort(all(v2));
  FOR(i, 0, n) {
    if (v1[i].S != v2[i].S) {
      cout << "YES\n";
      exit(0);
    }
  }
  cout << "NO\n";
  return 0;
}