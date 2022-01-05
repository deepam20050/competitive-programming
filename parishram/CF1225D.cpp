// AC
#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

const int N = 1e5 + 5;

map < vector < pii > , int > freq;
int sp[N];
bitset < N > vis_prime;

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

int main () {
  sieve();
  int n, k;
  scanf("%d %d", &n, &k);
  lli ans = 0;
  FOR(i, 0, n) {
    int x;
    scanf("%d", &x);
    int y = x;
    vector < pii > v, req;
    while (y > 1) {
      int g = sp[y];
      int c = 0;
      while (y % g == 0) {
        ++c;
        y /= g;
      }
      c %= k;
      if (c) {
        v.eb(g, c);
        req.eb(g, k - c);
      }
    }
    ans += freq[req];
    ++freq[v];
  }
  printf("%lld\n", ans);
  return 0;
}
