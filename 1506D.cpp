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

void test_case() {
  int n; cin >> n;
  map < int, int > cnt;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    ++cnt[x];
  }
  priority_queue < pii > pq;
  for (auto [val, c] : cnt) {
    pq.emplace(c, val);
  }
  while (sz(pq) >= 2) {
    auto [x1, y1] = pq.top(); pq.pop();
    auto [x2, y2] = pq.top(); pq.pop();
    --x1; --x2;
    if (x1) {
      pq.emplace(x1, y1);
    }
    if (x2) {
      pq.emplace(x2, y2);
    }
  }
  if (pq.empty()) {
    cout << 0 << '\n';
  } else {
    cout << pq.top().first << '\n';
  }
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