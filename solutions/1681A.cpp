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
  int alice = 0;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    alice = max(alice, x);
  }
  int m; cin >> m;
  int bob = 0;
  for (int i = 0; i < m; ++i) {
    int x; cin >> x;
    bob = max(bob, x);
  }
  alice >= bob ? cout << "Alice\n" : cout << "Bob\n";
  bob >= alice ? cout << "Bob\n" : cout << "Alice\n";
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