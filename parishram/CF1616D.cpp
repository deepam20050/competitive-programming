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

const int N = 5e4 + 5;

int a[N];

void solve () {
  int n;
  scanf("%d", &n);
  FOR(i, 0, n) {
    scanf("%d", a + i);
  }
  int x;
  scanf("%d", &x);
  FOR(i, 0, n) {
    a[i] -= x;
  }
  vector < bool > marked(n, 1);
  FOR(i, 0, n) {
    bool ok = 1;
    int s = a[i];
    for (int j = i - 1, c = 0; j >= 0 && c <= 2; --j, ++c) {
      s += a[j];
      ok &= marked[j];
      if (!ok) {
        break;
      }
      if (s < 0 && ok) {
        marked[i] = 0;
        break;
      }
    }
  }
  int ans = 0;
  FOR(i, 0, n) {
    ans += marked[i];
  }
  printf("%d\n", ans);
}

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
