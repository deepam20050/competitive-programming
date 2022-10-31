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
  vector < int > a(n + n);
  for (auto &e : a) {
    cin >> e;
  }
  sort(all(a));
  int s1 = accumulate(a.begin(), a.begin() + n, 0);
  int s2 = accumulate(n + all(a), 0);
  if (s1 != s2) {
    for (auto &e : a) {
      cout << e << " ";
    }
  } else if (a.front() != a.back()) {
    swap(a.front(), a.back());
    for (auto &e : a) {
      cout << e << " ";
    }
  } else {
    cout << "-1";
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