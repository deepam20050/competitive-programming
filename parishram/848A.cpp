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

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int k; cin >> k;
  FOR(i, 0, 26) {
    int c = 0;
    while (c * 1ll * (c - 1) / 2 <= k) {
      ++c;
    }
    --c;
    k -= c * (c - 1) >> 1;
    FOR(j, 0, c) {
      cout << char(i + 'a');
    }
  }
  return 0;
}