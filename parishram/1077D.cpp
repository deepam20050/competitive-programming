#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
#include "../algo/debug.hpp"
#else
#define debug(...) 0
#endif

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define eb emplace_back
#define em emplace
#define mp make_pair
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound

using lli = long long;
using pii = pair < int, int >;

const int N = 2e5 + 5;

int n, k;
int freq[N];
vector < pii > v;
vector < int > ans;

bool f (int x) {
  int len = 0;
  ans.clear();
  for (auto [f, val] : v) {
    int c = f / x;
    len = min(len + c, k);
    while (sz(ans) < len) {
      ans.eb(val);
    }
  }
  return len == k;
}

int main () {
  #ifdef DEBUG
  freopen("debug.txt", "w", stderr);
  #endif
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cout << fixed << setprecision(15); cerr << fixed << setprecision(10);
  cin >> n >> k;
  FOR(i, 0, n) {
    int x; cin >> x;
    ++freq[x];
  }
  FOR(i, 1, N) {
    if (freq[i]) {
      v.eb(freq[i], i);
    }
  }
  sort(all(v), greater < pii > ());
  int l = 1, r = N;
  FOR(i, 0, 19) {
    int midx = l + r >> 1;
    if (f(midx)) {
      l = midx;
    } else {
      r = midx;
    }
  }
  f(l);
  for (auto &e : ans) {
    cout << e << " ";
  }
  return 0;
}