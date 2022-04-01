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

bool check (int l, int r) {
  FOR(i, l, r + 1) {
    FOR(j, i + 1, r + 1) {
      FOR(k, j + 1, r + 1) {
        if ((a[i] >= a[j] && a[j] >= a[k]) || (a[i] <= a[j] && a[j] <= a[k])) {
          return 1;
        }
      }
    }
  }
  return 0;
}

void solve () {
  scanf("%d", &n);
  FOR(i, 1, n + 1) {
    scanf("%d", a + i);
  }
  int ans = 0;
  FOR(i, 1, n + 1) {
    int j = i;
    while (j <= n && !check(i, j)) {
      ++j;
    }
    ans += j - i;
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
