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

const int MAXN = 1e6 + 5;

int sp[MAXN];
bool vis_prime[MAXN];
int a[2][MAXN];

// Credits : https://codeforces.com/blog/entry/7262
inline void sieve () {
  for (int i = 2; i < MAXN; i += 2) sp[i] = 2;
  for (int i = 3; i < MAXN; i += 2) 
    if (!vis_prime[i]) {
      sp[i] = i;
      for (int j = i; j * 1ll * i < 1ll * MAXN; j += 2) if (!vis_prime[j * i]) vis_prime[j * i] = 1, sp[j * i] = i;
    }
}

void add (int x, int i) {
  int y = x;
  while (x > 1) {
    int p = sp[x];
    int m = y / p;
    ++a[i][(m - 1) * p + 1];
    --a[i][m * p + 1];
    // cout << y << " = " << (m - 1) * p + 1 << " " << m * p << '\n';
    while (x % p == 0) {
      x /= p;
    }
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  sieve();  
  int x2; cin >> x2;
  add(x2, 1);
  FOR(i, 1, MAXN) {
    a[1][i] += a[1][i - 1];
    if (a[1][i] == 0) continue;
    if (vis_prime[i] || !(i & 1)) {
      add(i, 0);
    }
  }
  FOR(i, 3, MAXN) {
    a[0][i] += a[0][i - 1];
    if (a[0][i] > 0) {
      cout << i << '\n';
      exit(0);
    }
  }
  return 0;
}