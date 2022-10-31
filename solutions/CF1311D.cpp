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
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int ans = 1e9, ansa, ansb, ansc;
    FOR(aa, 1, a + a + 1) for (int bb = aa; bb <= b + b; bb += aa) FOR(i, 0, 2) {
      int cc = bb * (c / bb) + i * bb;
      int result = abs(aa - a) + abs(bb - b) + abs(cc - c);
      if (result < ans) {
        ans = result;
        ansa = aa;
        ansb = bb;
        ansc = cc;
      }
    }
    printf("%d\n%d %d %d\n", ans, ansa, ansb, ansc);
  }
  return 0;
}
