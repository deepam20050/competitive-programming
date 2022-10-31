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

const int M = 26 * 26 * 26 + 26 * 26 + 26;

string t[M];
int idx = 0;

void init () {
  for (int i = 0; i < 26; ++i) {
    t[idx++] = i + 'a';
  }
  for (int i = 0; i < 26; ++i) {
    for (int j = 0; j < 26; ++j) {
      t[idx++] = string(1, i + 'a') + string(1, j + 'a');
    }
  }
  for (int i = 0; i < 26; ++i) {
    for (int j = 0; j < 26; ++j) {
      for (int k = 0; k < 26; ++k) {
        t[idx++] = string(1, i + 'a') + string(1, j + 'a') + string(1, k + 'a');
      }
    }
  }
}

void test_case() {
  int n; cin >> n;
  string s; cin >> s;
  for (int i = 0; i < M; ++i) {
    bool ok = 0;
    int m = sz(t[i]);
    for (int j = 0; j + m - 1 < n; ++j) {
      ok |= t[i] == s.substr(j, m);
    }
    if (!ok) {
      cout << t[i] << '\n';
      return;
    }
  }
}

int main() {
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  cin.tie(nullptr)->sync_with_stdio(false);
  init();
  int nt = 1;
  cin >> nt;
  while (nt--) {
    test_case();
  }
  return 0;
}