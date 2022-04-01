#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define eb emplace_back
#define em emplace
#define mp make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

const int N = 1e7 + 5;

int sp[N];
bitset < N > vis_prime;
int ans[N];

// Credits : https://codeforces.com/blog/entry/7262
inline void sieve () {
  for (int i = 2; i < N; i += 2) sp[i] = 2;
  for (int i = 3; i < N; i += 2) 
    if (!vis_prime[i]) {
      sp[i] = i;
      for (int j = i; j * 1ll * i < 1ll * N; j += 2) {
        if (!vis_prime[j * i]) vis_prime[j * i] = 1, sp[j * i] = i;
      }
    }
}

void init () {
  memset(ans, -1, sizeof ans);
  ans[1] = 1;
  FOR(i, 2, N) {
    int x = i;
    lli y = 1;
    while (x > 1 && y < N) {
      int p = sp[x];
      int num = 1;
      while (x % p == 0) {
        x /= p;
        num *= p;
      }
      lli mul = (num * p - 1) / (p - 1);
      y *= 1ll * (num * p - 1) / (p - 1);
    }
    if (y < N && ans[y] == -1) {
      ans[y] = i;
    }
  }
}

void solve () {
  int c;
  scanf("%d", &c);
  printf("%d\n", ans[c]);
}

int main () {
  sieve();
  init();
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
