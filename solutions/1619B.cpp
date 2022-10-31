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

const int limit = 1e9;

vector < int > ans;

void init () {
  ans.reserve(1 << 19);
  ans.emplace_back(1);
  for (int i = 2; i * 1ll * i <= limit; ++i) {
    ans.emplace_back(i * i);
  }
  for (int i = 2; i * 1ll * i * i <= limit; ++i) {
    ans.emplace_back(i * i * i);
  }
  sort(all(ans));
  ans.erase(unique(all(ans)), ans.end());
}

void test_case() {
  int x; cin >> x;
  cout << lower_bound(all(ans), x + 1) - ans.begin() << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  init();
  int nt = 1;
  cin >> nt;
  while (nt--) {
    test_case();
  }
  return 0;
}