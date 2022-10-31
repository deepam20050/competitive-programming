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

const int N = 3005;

char s[N];

void solve () {
  int n;
  scanf("%d", &n);
  scanf("%s", s + 1);
  int ans = 0;
  FOR(i, 1, n + 1) {
    int plus = 0, minus = 0, cost = 0, d = 0;
    FOR(j, i, n + 1) {
      int now = 0;
      if (s[j] == '+') {
        ++plus;
        cost += d >> 1;
        now = cost;
      } else {
        ++minus;
        ++d;
        now = d >> 1;
      }
      if (minus >= plus && (minus - plus) % 3 == 0) {
        ans += (minus - plus) / 3 <= now;
      }
    }
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
