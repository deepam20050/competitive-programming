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
  vector < int > v = {2, 100, 1000};
  while (1) {
    sort(all(v));
    bool ok = 0;
    FOR(i, 0, sz(v)) if (!ok) FOR(j, i + 1, sz(v)) {
      if (!binary_search(all(v), (int)abs(v[i] - v[j]))) {
        v.eb(abs(v[i] - v[j]));
        ok = 1;
        break;
      }
    }
    if (!ok) break;
  }
  for (auto &e : v) {
    cout << e << " ";
  }
  return 0;
}