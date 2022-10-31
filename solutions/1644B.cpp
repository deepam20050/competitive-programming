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

void print (const vector < int > &v) {
  for (auto &e : v) {
    cout << e << " ";
  }
  cout << '\n';
}

void test_case() {
  int n; cin >> n;
  vector < int > a(n);
  iota(all(a), 1);
  reverse(all(a));
  print(a);
  for (int i = 0; i + 1 < n; ++i) {
    swap(a[i], a[i + 1]);
    print(a);
    swap(a[i], a[i + 1]);
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