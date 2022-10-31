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

const int M = 2e5 + 5;
const int MOD = 1e9 + 7;

int cnt[M];
int m;
int p[M], s[M];

inline int add (int a, int b, int modd = MOD) {
  a += b;
  return a >= modd ? a - modd : a;
}

inline int mult (int a, int b, int modd = MOD) {
  return a * 1ll * b % modd;
}

inline int bin_pow (int a, int b, int modd = MOD) {
  int ret = 1;
  while (b > 0) {
    if (b & 1) {
      ret = mult(ret, a, modd);
    }
    a = mult(a, a, modd);
    b >>= 1;
  }
  return ret;
}

int main () {
  scanf("%d", &m);
  FOR(i, 0, m) {
    int x;
    scanf("%d", &x);
    ++cnt[x];
  }
  int ans = 1;
  p[1] = 1;
  s[M - 1] = 1;
  FOR(i, 2, M) {
    if (cnt[i]) {
      ++cnt[i];
      p[i] = mult(p[i - 1], cnt[i], MOD - 1);
    } else {
      p[i] = p[i - 1];
    }
  }
  for (int i = M - 2; i >= 0; --i) {
    if (cnt[i]) {
      s[i] = mult(s[i + 1], cnt[i], MOD - 1);
    } else {
      s[i] = s[i + 1];
    }
  }
  FOR(i, 2, M - 1) {
    if (!cnt[i]) {
      continue;
    }
    --cnt[i];
    int c = 1ll * (cnt[i] * 1ll * (cnt[i] + 1) >> 1ll) % (MOD - 1);
    c = mult(c, mult(p[i - 1], s[i + 1], MOD - 1), MOD - 1);
    ans = mult(ans, bin_pow(i, c), MOD);
  }
  printf("%d\n", ans);
  return 0;
}
