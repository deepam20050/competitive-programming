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
  map < int, int > fst;
  map < int, int > lst;
  for (int i = 1; i <= n; ++i) {
    int x; cin >> x;
    if (fst.count(x) == 0) {
      fst[x] = i;
    }
    lst[x] = i;
  }
  while (k--) {
    int a, b; cin >> a >> b;
    if (!fst.count(a) || !fst.count(b)) {
      cout << "NO\n";
    } else {
      fst[a] <= lst[b] ? cout << "YES\n" : cout << "NO\n";
    }
  }
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