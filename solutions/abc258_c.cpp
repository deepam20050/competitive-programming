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
  int n, nq; cin >> n >> nq;
  string s; cin >> s;
  string t = s + s;
  int start = n;
  while (nq--) {
    int op, x; cin >> op >> x;
    if (op == 1) {
      start -= x;
      start %= n;
      start += n;
      start %= n;
    } else {
      cout << t[(start + x - 1) % n] << '\n';
    }
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
