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

typedef long long lli;
typedef pair < int, int > pii;

const int N = 21;

int a[N];
int ans = 1 << 30;
int n;

void solve (int i, int curr_xor) {
  if (i == n) {
    ans = min(ans, curr_xor);
  }
  int x = a[i];
  for (int j = i; j < n; ++j) {
    x |= a[j];
    solve(j + 1, curr_xor ^ x);
  }
}

void test_case() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  solve(0, 0);
  cout << ans << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  int nt = 1;
  // cin >> nt;
  while (nt--) {
    test_case();
  }
  return 0;
}