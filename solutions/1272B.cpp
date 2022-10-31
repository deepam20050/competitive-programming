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
  map < char, int > cnt;
  for (auto &e : s) {
    ++cnt[e];
  }
  int x = min(cnt['R'], cnt['L']);
  cnt['R'] = x;
  cnt['L'] = x;
  int x2 = min(cnt['U'], cnt['D']);
  cnt['U'] = x2;
  cnt['D'] = x2;
  if (x2 == 0 && x) {
    cout << "2\nLR\n";
    return;
  }
  if (x == 0 && x2) {
    cout << "2\nUD\n";
    return;
  }
  cout << 2 * (x + x2) << '\n';
  debug(s, cnt);
  for (char x : "URDL") {
    cout << string(cnt[x], x);
  }
  cout << '\n';
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
