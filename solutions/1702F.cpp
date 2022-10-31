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
  multiset < int > a;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    while (x % 2 == 0) {
      x >>= 1;
    }
    a.emplace(x);
  }
  multiset < int > b;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    b.emplace(x);
  }
  while (!b.empty()) {
    int x = *b.rbegin();
    if (a.find(x) == a.end()) {
      if (x == 1) {
        cout << "NO\n";
        return;
      }
      b.erase(b.find(x));
      b.emplace(x / 2);
    } else {
      b.erase(b.find(x));
      a.erase(a.find(x));
    }
  }
  b.empty() ? cout << "YES\n" : cout << "NO\n";
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
