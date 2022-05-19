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
#define lb lower_bound
#define ub upper_bound

using lli = long long;
using pii = pair < int, int >;

const int MAXN = 1e5 + 5;

int sp[MAXN];
bitset < MAXN > vis_prime;

// Credits : https://codeforces.com/contest/1420/submission/93731409
template < int M >
struct modint {
  int val = 0;
  modint () {}
  modint (int x) : val(x) {
    while (val < 0) val += M;
    while (val >= M) val -= M;
  }
  modint (long long x): val(x % M) {
    if (val < 0) val += M;
  }
  modint operator+= (modint oth) {
    val += oth.val;
    if (val >= M) val -= M;
    return *this;
  }
  modint operator-= (modint oth) {
    val -= oth.val;
    if (val < 0) val += M;
    return *this;
  }
  modint operator*= (modint oth) {
    val = val * 1LL * oth.val % M;
    return *this;
  }
  void operator++ () {
    ++val;
    if (val == M) val = 0;
  }
  void operator-- () {
    --val;
    if (val == -1) {
      val = M - 1;
    }
  }
  modint operator- () {
    modint res;
    res.val = (val == 0) ? 0 : M - val;
    return res;
  }
  int mod() {
    return M;
  }
  modint pow (int x) {
    modint base = val;
    modint res = 1;
    while (x > 0) {
      if (x & 1) res *= base;
      base *= base;
      x >>= 1;
    }
    return res;
  }
  modint pow (lli x) {
    modint base = val;
    modint res = 1;
    while (x > 0LL) {
      if (x & 1LL) res *= base;
      base *= base;
      x >>= 1LL;
    }
    return res;
  }
  modint inv () {
    return pow(M - 2);
  }
  friend modint operator+ (modint a, modint b) {
    return modint(a) += b;
  }
  friend modint operator- (modint a, modint b) {
    return modint(a) -= b;
  }
  friend modint operator* (modint a, modint b) {
    return modint(a) *= b;
  }
  friend bool operator== (modint a, modint b) {
    return a.val == b.val;
  }
  friend bool operator!= (modint a, modint b) {
    return a.val != b.val;
  }
};

using mint = modint < 1000000007 >;

const int MAXP = 1e5 + 5;

mint fact[MAXP];
mint inv_fact[MAXP];

inline mint nCk (int n, int k) {
  return k > n ? 0 : fact[n] * inv_fact[k] * inv_fact[n - k];
}

inline void genFacAndInv () {
  fact[0] = 1;
  inv_fact[0] = 1;
  FOR(i, 1, MAXP) {
    fact[i] = fact[i - 1] * i;
    inv_fact[i] = fact[i].inv();
  }
}

// Credits : https://codeforces.com/blog/entry/7262
inline void sieve () {
  tve
  for (int i = 2; i < MAXN; i += 2) sp[i] = 2;
  for (int i = 3; i < MAXN; i += 2) 
    if (!vis_prime[i]) {
      sp[i] = i;
      for (int j = i; j * 1ll * i < 1ll * MAXN; j += 2) if (!vis_prime[j * i]) vis_prime[j * i] = 1, sp[j * i] = i;
    }
  int x; scanf("%d", &x);
  FOR(i, 1, n + 1) {
    int y; scanf("%d", &y);

  }
}

void solveTestCase () {
	int n = 5;
	int x;
	scanf("%d", &x);
	vector < int > v(x + 1);
	FOR(i, 1, n + 1) {
		int y; scanf("%d", &y);
	}	
}

int main () {
	int _tc; scanf("%d", &_tc);
	while (_tc--) {
		solveTestCase();
	}
  return 0;
}