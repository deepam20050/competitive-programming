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
  int n;
  scanf("%d", &n);
  if (n > 60) {
    puts("1");
    return 0;
  }
  vector < int > a(n);
  for (auto &e : a) {
    scanf("%d", &e);
  }
  int ans = 1e9;
  FOR(i, 0, n) {
    for (int x = a[i], j = i; j >= 0; --j, x ^= a[j]) {
      for (int y = a[i + 1], k = i + 1; k < n; ++k, y ^= a[k]) {
        if (x > y) {
          ans = min(ans, k - j - 1);
        }
      }
    }
  }
  if (ans == (int)1e9) {
    ans = -1;
  }
  printf("%d\n", ans);
  return 0;
}
