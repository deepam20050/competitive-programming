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

const int N = 3e5 + 5;

int n, k;
int a[N];

int main () {
  scanf("%d %d", &n, &k);
  FOR(i, 0, n) {
    scanf("%d", a + i);
  }
  vector < lli > s;
  lli ans = 0;
  for (int i = n - 1; i >= 0; --i) {
    ans += a[i];
    if (i > 0) {
      s.eb(ans);
    }
  }
  sort(all(s), greater < lli > ());
  FOR(i, 0, k - 1) {
    ans += s[i];
  }
  printf("%lld\n", ans);
  return 0;
}
