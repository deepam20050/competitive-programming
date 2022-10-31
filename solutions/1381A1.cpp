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
  vector < int > ans;
  for (int i = n - 1; i >= 0; --i) {
    if (a[i] == b[i]) continue;
    ans.emplace_back(i + 1);
    ans.emplace_back(1);
    ans.emplace_back(i + 1);
    reverse(a.begin(), a.begin() + i + 1);
    for_each(a.begin(), a.begin() + i + 1, [&] (char &x) {
      if (x == '1') x = '0';
      else x = '1';
    });
    a[0] = a[0] == '1' ? '0' : '1';
    reverse(a.begin(), a.begin() + i + 1);
    for_each(a.begin(), a.begin() + i + 1, [&] (char &x) {
      if (x == '1') x = '0';
      else x = '1';
    });
  }
  cout << sz(ans) << '\n';
  for (auto &e : ans) {
    cout << e << " ";
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