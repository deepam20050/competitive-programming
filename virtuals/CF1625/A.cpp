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

using lli = long long;
using pii = pair < int, int >;

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n, l;
    scanf("%d %d", &n, &l);
    vector < int > v(n);
    for (auto &e : v) scanf("%d", &e);
    int ans = 0;
    FOR(i, 0, l) {
      int c = 0;
      for (auto e : v) {
        if (e >> i & 1) {
          ++c;
        }
      }
      if (!c) continue;
      if (c >= n - c) {
        ans |= 1 << i;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
