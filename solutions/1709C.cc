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
  int m = sz(s) / 2;
  int cntOpen = count(all(s), '(');
  int cntClose = count(all(s), ')');
  // if (max(cntOpen, cntOpen) == m) {
  //   cout << "YES\n";
  //   return;
  // }
  vector < int > open, close;
  int bal = 0;
  int idx = 0;
  for (auto &e : s) {
    if (e == '?') {
      if (cntOpen < m) {
        e = '(';
        ++cntOpen;
        open.emplace_back(idx);
      } else {
        e = ')';
        close.emplace_back(idx);
      }
    }
    if (e == '(') {
      ++bal;
    } else {
      --bal;
    }
    if (bal < 0) {
      cout << "NO\n";
      return;
    }
    ++idx;
  }
  if (open.empty() || close.empty()) {
    cout << "YES\n";
    return;
  }
  swap(s[open.back()], s[close.front()]);
  bal = 0;
  for (int i = 0; i < sz(s); ++i) {
    if (s[i] == '(') {
      ++bal;
    } else {
      --bal;
    }
    if (bal < 0) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
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