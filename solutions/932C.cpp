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

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, a, b; cin >> n >> a >> b;
  vector < int > v(n);
  iota(all(v), 1);
  for (int i = 0, j = 1; i < n; ++j) {
    if ((n - i) % b == 0) {
      rotate(v.begin() + i, v.begin() + i + 1, v.begin() + i + b);
      i += b;
    } else {
      if (i + a > n) {
        cout << "-1";
        exit(0);
      }
      rotate(v.begin() + i, v.begin() + i + 1, v.begin() + i + a);
      i += a;
    }
  }
  for (auto &e : v) {
    cout << e << " ";
  }
  return 0;
}