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

const int N = 1e5 + 5;

char s[N];
int y[N];
int n, x;

void solve () {
  scanf("%d %d", &n, &x);
  scanf("%s", s + 1);
  int zero = 0, one = 0;
  lli ans = x == 0;
  FOR(i, 1, n + 1) {
    zero += s[i] == '0';
    one += s[i] == '1';
    y[i] = zero - one;
    ans += y[i] == x;
  }
  int k = y[n];
  FOR(i, 1, n + 1) {
    if (ans == -1) {
      break;
    }
    int d = x - y[i];
    if (k == 0 && d == 0) {
      ans = -1;
      break;
    }
    if (k == 0 && d != 0) {
      continue;
    }
    if (k != 0 && d % k == 0 && d / k > 0) {
      ++ans;
    }
  }
  printf("%lld\n", ans);
}

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
