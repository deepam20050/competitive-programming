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

void solve () {
  int n;
  scanf("%d", &n);
  vector < int > v(n);
  for (auto &e : v) {
    scanf("%d", &e);
  }
  sort(all(v));
  if (n == 1) {
    v[0] > 1 ? puts("NO") : puts("YES");
    return;
  }
  if (v[n - 1] - v[n - 2] > 1) {
    puts("NO");
  } else {
    puts("YES");
  }
}

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
