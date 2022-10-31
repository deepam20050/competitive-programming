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
  int fav = 0, oth = 0;
  for (int i = 0; i < n; ++i) {
    int op, a, b; cin >> op >> a >> b; 
    if (op == 1) {
      cout << "YES\n";
      fav = a;
      oth = b;
    } else {
      if (a == b) {
        cout << "YES\n";
        fav = oth = b;
      } else {
        if (a > b) swap(a, b);
        if (a < fav && fav <= b && oth <= a) {
          cout << "YES\n";
          fav = b;
          oth = a;
        } else if (a < oth && oth <= b && fav <= a) {
          cout << "YES\n";
          fav = a;
          oth = b;
        } else {
          cout << "NO\n";
        }
      }
    }
  }
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