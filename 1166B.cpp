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
  int k; cin >> k;
  string s = "aeiou";
  for (int i = 5; i * i <= k; ++i) {
    if (k % i == 0 && k / i >= 5) {
      int n = i, m = k / i;
      for (int j = 0; j < n; ++j) {
        int rem = m;
        while (rem >= 5) {
          cout << s;
          rem -= 5;
        }
        for (int k = 0; k < rem; ++k) {
          cout << s[k];
        }
        rotate(s.begin(), 1 + all(s));
      }
      return;
    }
  }
  cout << "-1\n";
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
