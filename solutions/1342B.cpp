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
  string s; cin >> s;
  int n = sz(s);
  if (all_of(all(s), [&] (char &x) { return x == s.front(); })) {
    cout << s << '\n';
    return;
  }
  string a = "";
  int what = 1;
  for (int i = 0; i < n; ) {
    if (s[i] - '0' == what) {
      a += what + '0';
      what ^= 1;
      ++i;
    } else {
      a += what + '0';
      what ^= 1;
    }
  }
  cout << a << '\n';
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