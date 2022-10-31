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

const int M = 26;

int cnt[M];

void test_case() {
  memset(cnt, 0, sizeof cnt);
  int n; cin >> n;
  string s; cin >> s;
  for (auto &e : s) {
    ++cnt[e - 'a'];
  }
  if ((n & 1) || *max_element(cnt, cnt + M) * 2 > n) {
    cout << "NO\n";
  } else {
    sort(all(s));
    string ans(n, '0');
    for (int i = 0; i + i < n; ++i) {
      ans[i] = s[i];
      ans[n - i - 1] = s[i + n / 2];
    }
    cout << "YES\n" << ans << '\n';
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