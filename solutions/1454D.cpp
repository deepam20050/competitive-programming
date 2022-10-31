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
  lli n; cin >> n;
  int mx = 0;
  lli who = 0;
  lli m = n;
  for (int i = 2; i * 1ll * i <= n; ++i) {
    int curr = 0;
    while (n % i == 0) {
      n /= i;
      ++curr;
    }
    if (curr > mx) {
      mx = curr;
      who = i;
    }
  }
  if (n > 0) {
    if (mx == 0) {
      mx = 1;
      who = n;
    }
  }
  cout << mx << '\n';
  for (int i = 0; i + 1 < mx; ++i) {
    cout << who << " ";
    m /= who;
  }
  cout << m << '\n';
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