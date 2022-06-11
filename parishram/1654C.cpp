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

using lli = int64_t;
using pii = pair < int, int >;

const int N = 2e5 + 5;

map < int, int > cnt_initial;
int n;

void test_case() {
  cin >> n;
  lli sum = 0;
  cnt_initial.clear();
  int mini = 2e9;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    sum += x;
    ++cnt_initial[x];
    mini = min(mini, x);
  }
  if (n == 1) {
    cout << "YES\n";
    return;
  }
  queue < lli > q;
  q.emplace(sum);
  for (int i = 1; i <= n - 1 && !q.empty(); ++i) {
    auto w = q.front();
    q.pop();
    lli f = w >> 1ll;
    lli c = w - f;
    debug(f, c);
    if (cnt_initial[f] == 0) {
      q.emplace(f);
    } else {
      --cnt_initial[f];
    }
    if (cnt_initial[c] == 0) {
      q.emplace(c);
    } else {
      --cnt_initial[c];
    }
  }
  for (auto [ignore, c] : cnt_initial) {
    if (c != 0) {
      cout << "NO\n";
      return;
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