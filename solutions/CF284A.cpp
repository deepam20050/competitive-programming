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
  int p; scanf("%d", &p);
  if (p == 2) {
    puts("1");
    exit(0);
  }
  int ans = 0;
  FOR(x, 2, p) {
    int y = x - 1;
    bool ok = 1;
    FOR(i, 2, p) {
      y = x * y % p + x - 1;
      y %= p;
      y += p;
      y %= p;
      if (i == p - 1) {
        ok &= y == 0;
      } else {
        ok &= y != 0;
      }
    }
    ans += ok;
  }
  printf("%d\n", ans);
  return 0;
}
