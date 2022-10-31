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
  string a, b; cin >> a >> b;
  int cnt[2] = {};
  for (int i = 0; i < n; ++i) {
    ++cnt[a[i] - '0'];
  }
  int swaps = 0;
  for (int i = n - 1; i >= 0; --i) {
    int c = (a[i] - '0') ^ swaps;
    if (c + '0' == b[i]) {
      --cnt[a[i] - '0'];
      continue;
    }
    if (cnt[0] == cnt[1]) {
      --cnt[a[i] - '0'];
      swaps ^= 1;
    } else {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
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