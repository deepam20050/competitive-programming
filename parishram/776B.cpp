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

bool not_prime[N];

void test_case() {
  for (int i = 2; i * 1ll * i < N; ++i) {
    if (!not_prime[i]) {
      for (int j = i + i; j < N; j += i) {
        not_prime[j] = 1;
      }
    }
  }
  int n; cin >> n;
  cout << (n > 2 ? 2 : 1) << '\n';
  for (int i = 2; i <= n + 1; ++i) {
    cout << (!not_prime[i] ? 1 : 2) << " ";
  }
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