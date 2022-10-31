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
  string s; cin >> s;
  int n = sz(s);
  s = " " + s;
  int l = 1, r = n;
  vector < int > open, close;
  while (l < r) {
    while (l <= n && s[l] == ')') {
      ++l;
    }
    while (r >= 1 && s[r] == '(') {
      --r;
    }
    if (l <= n && r >= 1 && l < r) {
      open.emplace_back(l);
      close.emplace_back(r);
      ++l;
      --r;
    }
  }
  if (open.empty()) {
    cout << "0\n";
    return;
  }
  cout << "1\n";
  cout << 2 * sz(open) << '\n';
  for (auto &e : open) {
    cout << e << " ";
  }
  reverse(all(close));
  for (auto &e : close) {
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
