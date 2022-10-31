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

const int N = 1e6;

vector < int > ans;
bool p[N];

void init () {
  for (int i = 2; i < N; ++i) {
    if (!p[i]) {
      ans.emplace_back(i);
      for (int j = i + i; j < N; j += i) {
        p[j] = 1;
      }
    }
  }
}

void test_case() {
  int n; cin >> n;
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " \n"[i == n - 1];
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  init();
  int nt = 1;
  cin >> nt;
  while (nt--) {
    test_case();
  }
  return 0;
}