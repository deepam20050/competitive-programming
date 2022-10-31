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

int a[N];
int b[N];

void test_case() {
  int n; cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a, a + n);
  int j = n - 1;
  for (int i = 0; i < n; i += 2) {
    b[i] = a[j--];
  }
  for (int i = 1; i < n; i += 2) {
    b[i] = a[j--];
  }
  int ans = 0;
  for (int i = 1; i + 1 < n; ++i) {
    ans += b[i] < b[i - 1] && b[i] < b[i + 1];
  }
  cout << ans << '\n';
  for (int i = 0; i < n; ++i) {
    cout << b[i] << " ";
  }
  cout << '\n';
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