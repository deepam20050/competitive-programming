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
  vector < vector < int > > ans;
  for (int len = 1000; len >= 2; len -= 2) {
    int open = len / 2;
    int close = len / 2;
    vector < int > vopen;
    int lst = 0;
    for (int i = 1; i <= n; ++i) {
      if (s[i] == '(' && open > 0) {
        --open;
        vopen.emplace_back(i);
        lst = i;
      }
    }
    vector < int > vclose;
    for (int i = n; i > lst; --i) {
      if (s[i] == ')' && open == 0 && close > 0) {
        --close;
        vclose.emplace_back(i);
      }
    }
    reverse(all(vclose));
    if (sz(vopen) + sz(vclose) == len) {
      ans.emplace_back(vector < int > ());
      for (auto &e : vopen) {
        ans.back().emplace_back(e);
        s[e] = 'X';
      }
      for (auto &e : vclose) {
        s[e] = 'X';
        ans.back().emplace_back(e);
      }
    }
  }
  cout << sz(ans) << '\n';
  for (auto &v : ans) {
    cout << sz(v) << '\n';
    for (auto &e : v) {
      cout << e << " ";
    }
    cout << '\n';
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
