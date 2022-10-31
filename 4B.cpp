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
  int d, s; cin >> d >> s;
  vector < int > min_time(d), max_time(d), ans(d);
  for (int i = 0; i < d; ++i) {
    cin >> min_time[i] >> max_time[i];
    ans[i] = min_time[i];
    s -= min_time[i];
  }
  if (s < 0) {
    cout << "NO\n";
    return;
  }
  for (int i = 0; i < d && s > 0; ++i) {
    int add = min(s, max_time[i] - min_time[i]);
    ans[i] += add;
    s -= add;
  }
  if (s) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  for (auto &e : ans) {
    cout << e << " ";
  }
}

int main() {
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  cin.tie(nullptr)->sync_with_stdio(false);
  int nt = 1;
  while (nt--) {
    test_case();
  }
  return 0;
}