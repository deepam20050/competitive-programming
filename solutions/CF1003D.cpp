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
  int n, nq; scanf("%d %d", &n, &nq);
  vector < int > c(31);
  FOR(i, 0, n) {
    int x; scanf("%d", &x);
    ++c[__lg(x)];
  }
  while (nq--) {
    int x;
    scanf("%d", &x);
    int ans = 0;
    for (int i = 30; i >= 0; --i) {
      if (x < 0) {
        break;
      }
      int need = min(x >> i, c[i]);
      ans += need;
      x -= (1 << i) * need;
    }
    if (x > 0) {
      ans = -1;
    }
    printf("%d\n", ans);
  }
  return 0;
}
