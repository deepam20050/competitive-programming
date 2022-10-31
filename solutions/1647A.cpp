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

const string s1 = "12", s2 = "21";

void test_case() {
  int n; cin >> n;
  int m = n % 3;
  n /= 3;
  if (m == 0) {
    while (n--) {
      cout << s2;
    }
  } else if (m == 1) {
    while (n--) {
      cout << s1;
    }
    cout << "1";
  } else {
    while (n--) {
      cout << s2;
    }
    cout << "2";
  }
  cout << '\n';
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