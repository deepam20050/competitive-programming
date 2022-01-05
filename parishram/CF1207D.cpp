// AC
#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

const int MOD = 998244353;
const int N = 3e5 + 5;

int f[N];
pii arr[N];
int n;

inline int add (int _x, int _y) {
  _x += _y;
  if (_x < 0) _x += MOD;
  if (_x >= MOD) _x -= MOD;
  return _x;
}

inline int mul (int _x, int _y) {
  return _x * 1ll * _y % MOD;
}

int solve () {
  int res = 1;
  int prev = arr[0].first;
  int x = 0;
  FOR(i, 0, n) {
    if (arr[i].first == prev) ++x;
    else {
      prev = arr[i].first;
      res = mul(res, f[x]);
      x = 1;
    }
  }
  res = mul(res, f[x]);
  return res;
}

int solve2 () {
  bool ok = 1;
  FOR(i, 1, n) {
    ok &= arr[i].first >= arr[i - 1].first;
    ok &= arr[i].second >= arr[i - 1].second;
  }
  if (!ok) return 0;
  auto prev = arr[0];
  int x = 0;
  int res = 1;
  FOR(i, 0, n) {
    if (prev == arr[i]) ++x;
    else {
      prev = arr[i];
      res = mul(res, f[x]);
      x = 1;
    }
  }
  res = mul(res, f[x]);
  return res;
}

int main () {
  f[0] = 1;
  FOR(i, 1, N) f[i] = mul(f[i - 1], i);
  scanf("%d", &n);
  FOR(i, 0, n) {
    int x, y;
    scanf("%d %d", &x, &y);
    arr[i] = {x, y};
  }
  sort(arr, arr + n);
  int ans = 0;
  ans = add(ans, solve());
  FOR(i, 0, n) {
    auto p = pii(arr[i].second, arr[i].first);
    arr[i] = p;
  }
  sort(arr, arr + n);
  ans = add(ans, solve());
  ans = add(ans, -solve2());
  printf("%d\n", add(f[n], -ans));
  return 0;
}