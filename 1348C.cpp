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
  int n, k; cin >> n >> k;
  string s; cin >> s;
  sort(all(s));
  if (s[0] != s[k - 1]) {
    cout << s[k - 1] << '\n';
    return;
  }
  cout << s[0];
  if (s[k] != s[n - 1]) {
    cout << s.substr(k);
  } else {
    cout << string((n - 1) / k, s[n - 1]);
  }
  cout << '\n';
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
