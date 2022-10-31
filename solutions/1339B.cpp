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
  deque < int > a(n);
  for (auto &e : a) {
    cin >> e;
  }
  sort(all(a));
  vector < int > ans(n);
  for (int i = n - 1; i >= 0; --i) {
    if (n - i & 1) {
      ans[i] = a.back();
      a.pop_back();
    } else {
      ans[i] = a.front();
      a.pop_front();
    }
  }
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