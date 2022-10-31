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
  vector < int > a(n);
  for (auto &e : a) {
    cin >> e;
  }
  lli pos = 0, neg = 0;
  for (int i = n - 1; i >= 0; --i) {
    lli tmp_pos = pos, tmp_neg = neg;
    pos = max(pos, tmp_neg + a[i]);
    neg = max(neg, tmp_pos - a[i]);
  }
  cout << pos << '\n';
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