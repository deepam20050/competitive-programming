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

const int N = 1e6 + 5;

int p[N];

int find (int x) {
  return p[x] == x ? x : p[x] = find(p[x]);
}

void test_case() {
  int n, nq; cin >> n >> nq;
  for (int i = 1; i <= n; ++i) {
    p[i] = i;
  }
  while (nq--) {
    string s; cin >> s;
    int x; cin >> x;
    if (s[0] == '-') {
      p[x] = x + 1;
    } else {
      int ans = find(x);
      if (!ans) ans = -1;
      cout << ans << '\n';
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  int nt = 1;
  while (nt--) {
    test_case();
  }
  return 0;
}