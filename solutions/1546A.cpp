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

const int N = 105;

int a[N], b[N], d[N];

void test_case() {
  int n; cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int sum = 0;
  vector < int > pos, neg;
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
    d[i] = b[i] - a[i];
    sum += d[i];
    if (d[i] > 0) {
      pos.eb(i);
    } else if (d[i] < 0) {
      neg.eb(i);
    }
  }
  if (sum != 0) {
    cout << -1 << '\n';
    return;
  }
  vector < pii > ans;
  while (!pos.empty()) {
    auto x = pos.back();
    while (d[x] > 0) {
      auto y = neg.back();
      ++d[y];
      --d[x];
      ans.emplace_back(y + 1, x + 1);
      if (d[y] == 0) {
        neg.pop_back();
      }
    }
    pos.pop_back();
  }
  cout << sz(ans) << '\n';
  for (auto &[x, y] : ans) {
    cout << x << " " << y << '\n';
  }
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