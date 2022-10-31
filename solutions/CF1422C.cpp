// tested by Hightail - https://github.com/dj3500/hightail
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int maxN = 1e5 + 1;
const ll MOD = 1e9 + 7;

ll sum[maxN];
ll multiply[maxN];
string str;

int main () {
  multiply[0] = 1;
  sum[0] = 1;
  for (int i = 1; i < maxN; ++i) {
    multiply[i] = (10 * multiply[i - 1]) % MOD;
    sum[i] = sum[i - 1] + (multiply[i] * (i + 1)) % MOD;
    sum[i] %= MOD;
  }
  cin >> str;
  ll ans = 0;
  for (int i = 0, n = str.size(); i < n; ++i) {
    ll x = str[i] - '0';
    ans += (x * ((i * (i + 1LL) / 2LL) % MOD) * multiply[n - i - 1]) % MOD;
    ans %= MOD;
    if (i + 1 != n) {
      ans += (x * sum[n - i - 2]) % MOD;
      ans %= MOD;
    }
  }
  cout << ans << '\n';
  return 0;
}
