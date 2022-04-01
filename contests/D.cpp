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

const int N = 2e5 + 5;

int a[N];
int n;

void solve () {
  scanf("%d", &n);
  vector < map < int, int > > pref(n + 2), suff(n + 2);
  FOR(i, 1, n + 1) {
    scanf("%d", a + i);
    if (abs(a[i]) == 2) {
      pref[i][a[i]] = pref[i - 1][a[i]] + 1;
    }
  }
  for (int i = n; i >= 1; --i) {
    if (abs(a[i]) == 2) {
      suff[i][a[i]] = suff[i + 1][a[i]] + 1;
    }
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
