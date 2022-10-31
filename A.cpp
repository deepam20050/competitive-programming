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

using lli = long long;
using pii = pair < int, int >;

using t3 = tuple < string, int, int >;

const int N = 505;

string s;
lli score[N];
lli t[N << 2];

void point_update (int lx, int rx, int x, int idx, lli val) {
  if (lx == rx) {
    t[x] = max(t[x], val);
    return;
  }
  int midx = lx + (rx - lx >> 1);
  if (idx <= midx) point_update(lx, midx, 2 * x, idx, val);
  else point_update(midx + 1, rx, 2 * x + 1, idx, val);
  t[x] = max(t[2 * x], t[2 * x + 1]);
}

lli query (int lx, int rx, int x, int ql, int qr) {
  if (lx > qr || rx < ql || ql > qr) {
    return 0ll;
  }
  if (ql <= lx && rx <= qr) {
    return t[x];
  }
  int midx = lx + (rx - lx >> 1);
  return max(query(lx, midx, 2 * x, ql, qr), query(midx + 1, rx, 2 * x + 1, ql, qr));
}

void test_case() {
  int n; cin >> n;
  cin >> s;
  s = " " + s;
  for (int i = 1; i <= n; ++i) {
    cin >> score[i];
  }
  memset(t, 0, sizeof t);
  vector < t3 > a;
  a.reserve(n * n);
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; ++j) {
      a.emplace_back(s.substr(i, j - i + 1), -i, -j);
    }
  }
  sort(all(a));
  lli ans = 0ll;
  for (int i = sz(a) - 1; i >= 0; --i) {
    auto [ignore, x, y] = a[i];
    x = -x;
    y = -y;
    lli val = max(0ll, score[y - x + 1] + query(1, n, 1, y + 1, n));
    point_update(1, n, 1, x, val);
    ans = max(ans, val);
  }
  cout << ans << '\n';
}

int main() {
  #ifdef DEBUG
  freopen("debug.txt", "w", stderr);
  #endif
  cin.tie(nullptr)->sync_with_stdio(false);
  int nt = 1;
  cin >> nt;
  while (nt--) {
    test_case();
  }
  return 0;
}
