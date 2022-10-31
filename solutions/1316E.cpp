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
const int P = 7;
const int PN = 1 << P;

int a[N];
int score[P][N];
lli dp[N][PN];
int ndx[N];

void test_case() {
  int n, p, k; cin >> n >> p >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    ndx[i] = i;
  }
  sort(ndx + 1, ndx + n + 1, [&] (int i, int j) {
    return a[i] > a[j];
  });
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < p; ++j) {
      cin >> score[j][i];
    }
  }
  memset(dp, -1, sizeof dp);
  dp[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int mask = 0; mask < (1 << p); ++mask) {
      if (dp[i - 1][mask] != -1) {
        dp[i][mask] = dp[i - 1][mask];
        int rem = i - 1 - __builtin_popcount(mask);
        if (rem < k) {
          dp[i][mask] += a[ndx[i]];
        }
      }
      for (int z = 0; z < p; ++z) {
        int newMask = mask ^ (1 << z);
        if ((mask >> z & 1) && dp[i - 1][newMask] != -1) {
          dp[i][mask] = max(dp[i][mask], dp[i - 1][newMask] + score[z][ndx[i]]);
        }
      }
    }
  }
  cout << dp[n][(1 << p) - 1]; 
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