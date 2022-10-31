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

template < class T > struct FenwickTree {
  vector < T > t;
  int n;
  FenwickTree (int m) : n(m) {
    t.resize(n + 1);
  }
  void update (int idx, T add) {
    while (idx <= n) {
      t[idx] += add;
      idx += idx & -idx;
    }
  }
  T query (int idx) {
    T ret = 0;
    while (idx > 0) {
      ret += t[idx];
      idx -= idx & -idx;
    }
    return ret;
  }
  T rangeQuery (int l, int r) {
    return l > r ? 0 : query(r) - query(l - 1);
  }
};

void test_case() {
  int n, nq; cin >> n >> nq;
  string s; cin >> s;
  s = " " + s;
  vector < int > good(n + 1);
  for (int i = 1; i + 2 <= n; ++i) {
    good[i] |= s[i] == s[i + 1] || s[i] == s[i + 2];
    good[i] |= s[i + 1] == s[i + 2];
  }
  FenwickTree < int > tree1(n);
  for (int i = 1; i <= n; ++i) {
    tree1.update(i, good[i]);
  }
  while (nq--) {
    int l, r; cin >> l >> r;
    tree1.rangeQuery(l, r - 2) ? cout << "YES\n" : cout << "NO\n";
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