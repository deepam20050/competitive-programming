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
  string s; cin >> s;
  string a(n, '0'), b(n, '0');
  bool large = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '2') {
      if (large) {
        a[i] = '2';
      } else {
        a[i] = b[i] = '1';
      }
    } else if (s[i] == '1') {
      if (large) {
        a[i] = '1';
      } else {
        large = 1;
        b[i] = '1';
      }
    }
  }
  cout << a << '\n' << b << '\n';
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