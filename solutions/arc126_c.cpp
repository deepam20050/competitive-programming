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

const int M = 3e5;

lli cnt[M + 5];
lli sum[M + 5];
int n;
lli k;

void test_case() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    ++cnt[x];
    sum[x] += x;
  }
  for (int i = 1; i <= M; ++i) {
    cnt[i] += cnt[i - 1];
    sum[i] += sum[i - 1];
  }
  lli ans = 1;
  for (int x = 2; x <= M; ++x) {
    int l = 0, r = x;
    lli cost = 0;
    while (l <= M) {
      lli c = cnt[min(M, r)] - cnt[l];
      lli s = sum[min(M, r)] - sum[l];
      cost += c * 1ll * r - s;
      l += x, r += x;
    }
    if (cost <= k) {
      ans = x;
    }
  }
  lli max_cost = n * 1ll * M - sum[M];
  if (max_cost <= k) {
    ans = M + (lli)(k - max_cost) / n;
  }
  cout << ans << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  int nt = 1;
  while (nt--) {
    test_case();
  }
  return 0;
}