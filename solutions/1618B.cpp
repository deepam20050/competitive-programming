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

string s[N];

void test_case() {
  int n; cin >> n;
  for (int i = 0; i < n - 2; ++i) {
    cin >> s[i]; 
  }
  bool ok = 0;
  string ans;
  for (int i = 0; i < n - 2; ++i) {
    ans += s[i][0];
    if (i + 1 < n - 2 && s[i].back() != s[i + 1].front()) {
      ok = 1;
      ans += s[i].back();
    }
  }
  ans += s[n - 3].back();
  debug(ok);
  if (!ok) {
    ans += "a";
  }
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