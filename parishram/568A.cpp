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

const int N = 2e6 + 5;

bool prime[N];

void sieve () {
  prime[1] = 1;
  for (int i = 2; i * i < N; ++i) if (!prime[i]) {
    for (int j = i + i; j < N; j += i) {
      prime[j] = 1;
    }
  }
}

int ispal (int x) {
  auto s = to_string(x);
  FOR(i, 0, sz(s) + 1 >> 1) {
    if (s[i] != s[sz(s) - 1 - i]) {
      return 0;
    }
  }
  return 1;
}

int main () {
  sieve();
  ios_base::sync_with_stdio(0); cin.tie(0);
  int p, q; cin >> p >> q;
  int c1 = 0, c2 = 0;
  int ans = -1;
  FOR(i, 1, N) {
    c1 += !prime[i];
    c2 += ispal(i);
    if (c1 * 1ll * q <= p * 1ll * c2) {
      ans = i;
    }
  }
  if (ans == -1) {
    cout << "Palindromic tree is better than splay tree\n";
  } else {
    cout << ans << '\n';
  }
  return 0;
}