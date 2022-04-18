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

int n;
int a[N];

void solve () {
  scanf("%d", &n);
  array < int, 3 > ans = {0, 0, n};
  int l = 1;
  FOR(i, 1, n + 2) {
    if (i <= n) {
      scanf("%d", a + i);
    }
    if (i == n + 1 || a[i] == 0) {
      bool neg = 0;
      int two = 0;
      int first_neg = 1e9;
      int lol = 0;
      for (int j = l; j < i; ++j) {
        two += abs(a[j]) == 2;
        if (a[j] < 0) {
          neg ^= 1;
          if (first_neg == (int)1e9) {
            first_neg = two;
            lol = j;
          }
        }
        if (!neg) {
          ans = max(ans, {two, l - 1, n - j}); 
        } else {
          ans = max(ans, {two - first_neg, lol, n - j});
        }
      }
      l = i + 1;
    }
  }
  printf("%d %d\n", ans[1], ans[2]);
}

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
