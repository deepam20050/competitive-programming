#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
  #include "../algo/debug.hpp"
#else
  #define debug(...)
#endif
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define eb emplace_back

typedef long long lli;
typedef pair < int, int > pii;

template < class T > bool ckmin (T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template < class T > bool ckmax (T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int N = 2e5 + 5;

lli a[N], b[N];
int n;

void test_case() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  lli ans = min(abs(a[0] - b[0]) + abs(a[n - 1] - b[n - 1]), abs(a[0] - b[n - 1]) + abs(a[n - 1] - b[0]));
  lli cost[4];
  fill(cost, cost + 4, 1ll << 60);
  for (int i = 0; i < n; ++i) {
    ckmin(cost[0], abs(a[0] - b[i]));
    ckmin(cost[1], abs(a[n - 1] - b[i]));
    ckmin(cost[2], abs(b[0] - a[i]));
    ckmin(cost[3], abs(b[n - 1] - a[i]));
  }
  ckmin(ans, abs(a[0] - b[0]) + cost[1] + cost[3]);
  ckmin(ans, abs(a[0] - b[n - 1]) + cost[1] + cost[2]);
  ckmin(ans, abs(a[n - 1] - b[0]) + cost[0] + cost[3]);
  ckmin(ans, abs(a[n - 1] - b[n - 1]) + cost[0] + cost[2]);
  ckmin(ans, cost[0] + cost[1] + cost[2] + cost[3]);
  cout << ans << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  int nt = 1;
  cin >> nt;
  while (nt--) {
    test_case();
  }
  return 0;
}