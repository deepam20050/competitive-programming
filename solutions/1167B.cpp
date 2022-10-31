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
  vector < int > ans(4);
  vector < int > p = { 4, 8, 15, 16, 23, 42};
  for (int i = 0; i < 4; ++i) {
    cout << "? " << i + 1 << " " << i + 2 << endl;
    cin >> ans[i];
  }
  do {
    bool ok = 1;
    for (int i = 0; i < 4; ++i) {
      ok &= p[i] * p[i + 1] == ans[i];
    }
    if (ok) break;
  } while (next_permutation(all(p)));
  cout << "! ";
  for (auto &e : p) {
    cout << e << " ";
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