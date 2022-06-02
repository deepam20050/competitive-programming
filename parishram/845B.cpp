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
#define lb lower_bound
#define ub upper_bound

using lli = long long;
using pii = pair < int, int >;

const int N = 1e7;

template < class T > bool ckmin (T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template < class T > bool ckmax (T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int main () {
  int val; scanf("%d", &val);
  int ans = 2e9;
  FOR(i, 0, N) {
    int x = i;
    int rgt = 0, lft = 0;
    for (int c = 0; c < 3 && x > 0; ++c) {
      rgt += x % 10;
      x /= 10;
    }
    for (int c = 0; c < 3 && x > 0; ++c) {
      lft += x % 10;
      x /= 10;
    }
    if (lft == rgt) {
      int x = i, y = val;
      int cnt = 0;
      while (x > 0 && y > 0) {
        cnt += (x % 10) != (y % 10);
        x /= 10;
        y /= 10;
      }
      while (x > 0) {
        cnt += x % 10 > 0;
        x /= 10;
      }
      while (y > 0) {
        cnt += y % 10 > 0;
        y /= 10;
      }
      ckmin(ans, cnt);
    }
  }
  printf("%d\n", ans);
  return 0;
}