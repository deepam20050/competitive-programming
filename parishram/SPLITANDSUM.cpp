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

const int N = 1e5 + 5;
const int LN = 60;

int a[N];
int n;

void test_case() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int bit = 0; bit < LN; ++bit) {
    int c = 0;
    vector < int > v = {0};
    for (int i = 1; i <= n; ++i) {
      if (a[i] & 1) {
        v.emplace_back(i);
      }
    }
    if (sz(v) > 2) {
      cout << "YES\n";
      v.back() = max(v.back(), n);
      cout << sz(v) - 1 << '\n';
      for (int i = 1; i < sz(v); ++i) {
        cout << v[i - 1] + 1 << " " << v[i] << '\n';
      }
      return;
    }
    for (int i = 1; i <= n; ++i) {
      a[i] >>= 1;
    }
  }
  cout << "NO\n";
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