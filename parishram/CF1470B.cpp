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

const int MN = 1e6 + 5;

int sp[MN];
bitset < MN > vis_prime;
map < int, int > cnt;

// Credits : https://codeforces.com/blog/entry/7262
inline void sieve () {
  for (int i = 2; i < MN; i += 2) sp[i] = 2;
  for (int i = 3; i < MN; i += 2) 
    if (!vis_prime[i]) {
      sp[i] = i;
      for (int j = i; j * 1ll * i < 1ll * MN; j += 2) {
        if (!vis_prime[j * i]) vis_prime[j * i] = 1, sp[j * i] = i;
      }
    }
}

void solve () {
  cnt.clear();
  int n;
  scanf("%d", &n);
  FOR(i, 0, n) {
    int a;
    scanf("%d", &a);
    int b = 1;
    while (a > 1) {
      int p = sp[a], c = 0;
      while (a % p == 0) {
        a /= p;
        ++c;
      }
      if (c & 1) {
        b *= p;
      }
    }
    ++cnt[b];
  }
  int even = 0;
  int mx = 0;
  for (auto [val, c] : cnt) {
    if (c % 2 == 0 || val == 1) {
      even += c;
    }
    mx = max(mx, c);
  }
  int nq;
  scanf("%d", &nq);
  while (nq--) {
    lli x;
    scanf("%lld", &x);
    if (x == 0) {
      printf("%d\n", mx);
    } else {
      printf("%d\n", max(mx, even));
    }
  }
}

int main () {
  sieve();
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
