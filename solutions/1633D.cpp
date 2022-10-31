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

using lli = int64_t;
using pii = pair < int, int >;

const int N = 1005;

int d[N];

void init () {
  fill(d, d + N, (int)1e9);
  d[1] = 0;
  for (int i = 1; i < N; ++i) {
    for (int j = 1; j <= i; ++j) {
      int nxt = i + i / j;
      if (nxt < N) {
        d[nxt] = min(d[nxt], d[i] + 1);
      }
    }
  }
}

void test_case() {
  int n, k; cin >> n >> k;
  vector < int > b(n), c(n);
  for (auto &e : b) {
    cin >> e;
  }
  for (auto &e : c) {
    cin >> e;
  }
  int sum = 0;
  for (auto &e : b) {
    e = d[e];
    sum += e;
  }
  k = min(k, sum);
  vector < int > dp(k + 1, 0);
  for (int i = 0; i < n; ++i) {
    for (int j = k - b[i]; j >= 0; --j) {
      dp[j + b[i]] = max(dp[j + b[i]], dp[j] + c[i]);
    }
  }
  cout << *max_element(all(dp)) << '\n';
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