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

bool used[30];
vector < int > g[26];

void test_case() {
  string s, t; cin >> s >> t;
  for (int i = 0; i < 26; ++i) {
    g[i].clear();
  }
  int n = sz(s);
  memset(used, 0, sizeof used);
  int j = sz(t) - 1;
  for (int i = n - 1; i >= 0; --i) {
    g[s[i] - 'A'].emplace_back(i);
    if (j >= 0 && t[j] == s[i]) {
      used[i] = 1;
      --j;
    }
  }
  if (j != -1) {
    cout << "NO\n";
    return;
  }
  for (int i = 0; i < n; ++i) {
    if (!used[i]) {
      int x = s[i] - 'A';
      if (used[g[x].back()]) {
        cout << "NO\n";
        return;
      }
      g[x].pop_back();
    }
  }
  cout << "YES\n";
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