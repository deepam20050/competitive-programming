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
  set < int > uniq;
  FOR(i, 0, n) {
    int x;
    scanf("%d", &x);
    uniq.em(x);
  }
  int m = sz(uniq);
  FOR(i, 1, n + 1) {
    printf("%d%c", max(i, m), " \n"[i == n]);
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
