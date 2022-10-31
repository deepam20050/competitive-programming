#include "bits/stdc++.h"

using namespace std;

using ll = long long;
const int N = 2e5 + 5;
const ll MOD = 1e9 + 7;

int arr[N];
ll facto[N];

ll mult (ll a, ll b) {
  return a * b % MOD;
}
  
ll binpow (ll a, ll x) {
  ll res = 1;
  while (x) {
    if (x & 1) res = mult(res, a);
    a = mult(a, a);
    x >>= 1LL;
  }
  return res;
}

ll inv (ll a) {
  return binpow(a, MOD - 2);
}

ll divide (ll a, ll b) {
  return mult(a, inv(b));
}

ll nCr (int n, int r) {
  if (r > n) return 0;
  return divide(facto[n], mult(facto[n - r], facto[r]));
}

void solve () {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", arr + i);
  }
  sort(arr, arr + n);
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    int x = arr[i];
    int pos = upper_bound(arr, arr + n, x + k) - arr;
    ans += nCr(pos - i - 1, m - 1);
    ans %= MOD;
  }
  printf("%lld\n", ans);
}

int main () {
  facto[0] = 1;
  for (int i = 1; i < N; ++i) {
    facto[i] = mult(facto[i - 1], i);
  }
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
