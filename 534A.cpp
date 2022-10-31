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
  if (n < 3) {
    cout << "1\n1\n";
  } else if (n == 3) {
    cout << "2\n1 3\n";
  } else {
    cout << n << '\n';
    for (int i = 2; i <= n; i += 2) {
      cout << i << " ";
    }
    for (int i = 1; i <= n; i += 2) {
      cout << i << " ";
    }
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
