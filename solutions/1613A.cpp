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

int get_size (int x) {
  int ret = 0;
  while (x > 0) {
    x /= 10;
    ++ret;
  }
  return ret;
}

void test_case() {
  int x1, p1; cin >> x1 >> p1;
  int x2, p2; cin >> x2 >> p2;
  int s1 = get_size(x1) + p1;
  int s2 = get_size(x2) + p2;
  if (s1 != s2) {
    cout << (s1 > s2 ? ">\n" : "<\n");
  } else {
    string sx1 = to_string(x1);
    string sx2 = to_string(x2);
    while (sz(sx1) < 10 && p1 > 0) {
      sx1 += "0";
      --p1; 
    }
    while (sz(sx2) < 10 && p2 > 0) {
      sx2 += "0";
      --p2; 
    }
    debug(s1);
    if (sx1 == sx2) {
      cout << "=\n";
    } else if (sx1 > sx2) {
      cout << ">\n";
    } else {
      cout << "<\n";
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