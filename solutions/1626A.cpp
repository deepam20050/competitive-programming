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

const int N = 26;

int cnt[N];

void test_case() {
  string s; cin >> s;
  memset(cnt, 0, sizeof cnt);
  for (auto &e : s) {
    ++cnt[e - 'a'];
  }
  string ans ; 
  for (int i = 0; i < N; ++i) {
    if (cnt[i] == 1) {
      ans += i + 'a';
      --cnt[i];
    }
  }
  string add;
  for (int i = 0; i < N; ++i) {
    if (cnt[i]) {
      add += i + 'a';
    }
  }
  add += add;
  cout << ans + add << '\n';
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