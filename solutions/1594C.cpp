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
  int n; char c; cin >> n >> c;
  string s; cin >> s;
  if (all_of(all(s), [&] (char x) { return x == c; })) {
    cout << 0 << '\n';
    return;
  }
  for (int i = 1; i <= n; ++i) {
    bool ok = 0;
    for (int j = i; j <= n; j += i) {
      ok |= s[j - 1] != c;
    }
    if (!ok) {
      cout << "1\n" << i << '\n';
      return;
    }
  }
  cout << "2\n" << n << " " << n - 1 << '\n';
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