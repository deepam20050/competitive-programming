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

const int prime1 = 1000000007;
const int prime2 = 1000000009;

void test_case() {
  int n; cin >> n;
  vector < int > a(n);
  for (auto &e : a) {
    cin >> e;
  }
  vector < array < int, 4 > > ans;
  int now = 0;
  for (int i = 0; i + 1 < n; ++i) {
    if (gcd(a[i], a[i + 1]) > 1) {
      now ^= 1;
      int x = min(a[i], a[i + 1]);
      int curr_prime = now ? prime1 : prime2;
      ans.push_back({i + 1, i, x, curr_prime});
      a[i + 1] = x;
      a[i] = curr_prime;
    }
  }
  debug(a);
  cout << sz(ans) << '\n';
  for (auto &[a, b, c, d] : ans) {
    cout << a + 1 << " " << b + 1 << " " << c << " " << d << '\n';
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