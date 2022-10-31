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
  vector < int > a(n + 1), present(n + 1, 1), minAns(n + 1), maxAns(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (a[i] != a[i - 1]) {
      present[a[i]] = 0;
      minAns[i] = a[i];
      maxAns[i] = a[i];
    }
  }
  vector < int > notPresent;
  set < int > s;
  for (int i = n; i >= 1; --i) {
    if (present[i]) {
      notPresent.emplace_back(i);
      s.emplace(i);
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (!minAns[i]) {
      minAns[i] = notPresent.back();
      notPresent.pop_back();
    }
  }
  s.emplace(n + 1);
  for (int i = 1; i <= n; ++i) {
    if (!maxAns[i]) {
      auto it = s.lower_bound(a[i]);
      --it;
      maxAns[i] = *it;
      s.erase(it);
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << minAns[i] << " \n"[i == n];
  }
  for (int i = 1; i <= n; ++i) {
    cout << maxAns[i] << " \n"[i == n];
  }
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
