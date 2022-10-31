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

const int N = 2e5 + 5;

int cnt[N];

void test_case() {
  int n; cin >> n;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    ++cnt[x];
  }
  vector < int > incr, decr;
  for (int i = 0; i < N; ++i) {
    if (cnt[i] > 2) {
      cout << "NO\n";
      return;
    }
    if (cnt[i]) {
      --cnt[i];
      incr.emplace_back(i);
    }
  }
  for (int i = N - 1; i >= 0; --i) {
    if (cnt[i]) {
      --cnt[i];
      decr.emplace_back(i);
    }
  }
  cout << "YES\n";
  cout << sz(incr) << '\n';
  for (auto &e : incr) {
    cout << e << " ";
  }
  cout << '\n';
  cout << sz(decr) << '\n';
  for (auto &e : decr) {
    cout << e << " ";
  }
  cout << '\n';
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