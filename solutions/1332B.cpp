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

const int N = 1005;
const int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

int a[N];
int ans[N];

void test_case() {
  int n; cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    ans[i] = -1;
  }
  int what = 0;
  for (int i = 0; i < 11; ++i) {
    for (int j = 0; j < n; ++j) {
      if (ans[j] == -1 && a[j] % primes[i] == 0) {
        ++what;
        break;
      }
    }
    for (int j = 0; j < n; ++j) {
      if (ans[j] == -1 && a[j] % primes[i] == 0) {
        ans[j] = what;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (ans[i] == -1) {
      ++what;
      ans[i] = what;
    }
  }
  cout << what << '\n';
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << '\n';
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