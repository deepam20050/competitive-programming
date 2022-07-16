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

const int N = 2e5 + 5;

int a[N];

void test_case() {
  int n, k; cin >> n >> k;
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    cnt += a[i] & 1;
  }
  if (cnt < k) {
    cout << "NO\n";
    return;
  }
  if (cnt % 2 != k % 2) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  int prev = 1;
  for (int i = 1; i <= n; ++i) {
    if (k == 1) {
      break;
    }
    if (a[i] & 1) {
      cout << i << " "; 
      --k;
    }
  }
  cout << n << '\n';
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